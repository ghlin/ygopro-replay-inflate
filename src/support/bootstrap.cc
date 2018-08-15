#include "debug.h"
#include "assert.h"
#include "bootstrap.h"
#include "misc.h"
#include "string.h"

namespace ri {
namespace bootstrap {

Reg make_reg_from_string( const Str &name
                        , const Str &schema
                        , Routine &&early_init
                        , Routine &&late_init
                        , Routine &&early_fini
                        , Routine &&late_fini)
{
  return make_reg( name
                 , split<Set>(schema, ",")
                 , std::move(early_init)
                 , std::move(late_init)
                 , std::move(early_fini)
                 , std::move(late_fini));
}

Args make_args_from_commandline(int argc, const char **argv)
{
  return { *argv
         , u_map(u_collect(argv + 1, argv + argc), u_id_function_of_<Str>())
         };
}


struct Node;

using Node_List = Seq<Node *>;
using Deps      = Set<Str>;

enum Init_Status
{
  Waiting,
  Initializing,
  Finalizing,
  Done_Initialization,
  Done_Finalization,
};

struct Node
{
  Ptr<Reg> reg;

  Set<Ptr<Node>>   pool;
  Map<Str, Node *> entries;

  Node            *root;
  Node            *parent;
  unsigned                   depth;

  Node_List                  queue;
  Node_List                  pending;

  Str                        path;

  bool                       activated;

  Init_Status                status;

  Node(Reg &&reg, bool activated = false)
    : reg(std::make_unique<Reg>(std::move(reg)))
    , root(this)
    , parent(nullptr)
    , depth(0)
    , activated(activated)
    , status(Waiting)
  {
    path = this->reg->name;
  }

  Node() : Node(make_reg("<root>")) { }

  inline
  Node *add_entry(Ptr<Node> &&entry)
  {
    auto *save = entry.get();

    pool.insert(std::move(entry));
    entries.emplace(save->reg->name, save);

    save->parent = this;
    save->root   = root;
    save->depth  = depth + 1;

    if (this == root)
      save->path = save->reg->name;
    else
      save->path = path + "." + save->reg->name;

    return save;
  }

  inline
  Node *prepare_path(const Str_List &path, bool active = false)
  {
    auto *iter = this;

    for (auto &&entry : path)
    {
      if (!u_has(iter->entries, entry))
      {
        iter->add_entry(std::make_unique<Node>(make_reg(entry)));
      }

      iter->activated = iter->activated || active;
      iter            = iter->entries.at(entry);

      for (size_t i = 0; i != Stage::Total_Stages; ++i) try
      {
        RiRuntime_Assert(iter->reg->tasks[i]);
      }
      catch (...)
      {
        RiLogE("panic at stage[%zu]", i);
        throw;
      }
    }

    return iter;
  }

  inline
  Node *prepare_path(const Str &path, bool active = false)
  {
    return prepare_path(u_map(split(path, "."), trim), active);
  }

  inline
  void complete_deep_dependences(const Node *dep)
  {
    RiAssert(root == dep->root);

    auto *node = this;

    while (node->depth > dep->depth)
      node = node->parent;

    while (dep->depth > node->depth)
      dep = dep->parent;

    while (node->parent != dep->parent)
    {
      node = node->parent;
      dep  = dep->parent;
    }

    node->reg->deps.insert(dep->reg->name);
  }

  inline void add_dependence(const Str &depname)
  {
    RiAssert(!depname.empty());

    if (depname[0] == '@')
      reg->deps.insert(depname.substr(1));
    else
      complete_deep_dependences(root->prepare_path(depname));
  }

  inline
  Opt<size_t> probe_install_pos(Node *entry)
  {
    auto ndeps = entry->reg->deps.size();

    if (ndeps == 0)
      return { 0 };

    for (size_t pos = 0; pos != queue.size(); ++pos)
    {
      auto that = queue.at(pos);

      if (u_has(entry->reg->deps, that->reg->name)
        && that->activated
        && --ndeps == 0)
      {
        return { pos + 1 };
      }
    }

    return { };
  }

  inline
  void install(Node *entry, size_t pos)
  { queue.insert(queue.begin() + pos, entry); }

  inline void resolve_pending()
  {
    for (auto iter = pending.begin(); iter != pending.end(); ++iter)
    {
      if (auto pos = probe_install_pos(*iter))
      {
        install(*iter, *pos);
        pending.erase(iter);

        return resolve_pending();
      }
    }
  }

  inline void resolve_one(Node *one)
  {
    if (auto pos = probe_install_pos(one))
    {
      install(one, *pos);
      resolve_pending();
    }
    else
    {
      pending.push_back(one);
    }
  }

  inline void resolve()
  {
    for (auto &entry : pool)
      resolve_one(entry.get());
  }

  void sort()
  {
    if (status != Waiting)
      RiPanicF("Multiply initialization detected!");

    resolve();

    if (!pending.empty())
    {
      auto unresolved = str_map_join(pending, "\n", [] (auto *node)
                                     {
                                       return node->path
                                        +     " requires ["
                                        +     str_join(node->reg->deps, ", ")
                                        +     "]";
                                     });

      auto msg = "Unresolved deps of " + path + " :\n" + unresolved;

      RiPanicF("%s", msg);
    }

    for (auto *entry : queue)
      entry->sort();
  }

  void initialize(Args &args)
  {
    status = Initializing;
    auto _ = defer_with (this)
    {
      status = Done_Initialization;
    };

    reg->tasks[Early_Init](args, *reg);

    for (auto &&entry : queue)
      entry->initialize(args);

    reg->tasks[Late_Init](args, *reg);
  }

  void finalize(Args &args)
  {
    status = Finalizing;
    auto _ = defer_with (this)
    {
      status = Done_Finalization;
    };

    reg->tasks[Early_Fini](args, *reg);

    for (auto pent = queue.rbegin(); pent != queue.rend(); ++pent)
      (*pent)->finalize(args);

    reg->tasks[Late_Fini](args, *reg);
  }

  Str dump(int ind = 0) const
  {
    auto padding   = Str(ind, ' ');
    auto deps_text = reg->deps.empty()
                   ? Str("")
                   : "requires " + str_join( u_map( reg->deps
                                                  , [](auto s)
                                                    { return "@" + s; })
                                           , ", ");
    auto dump_text = format("%s@%s %s", padding, reg->name, deps_text);

    if (!pool.empty())
    {
      dump_text += format("\n%s{\n", padding)
                +  str_map_join(pool,
                                "",
                                [ind] (auto &i) { return i->dump(ind + 4); })
                +  format("%s}\n", padding);
    }
    else
    {
      dump_text += format(" { - }\n");
    }


    return dump_text;
  }

  Str_List collect() const
  {
    Str_List result = { path };
    for (auto &&sub : queue)
    {
      auto sublist = sub->collect();

      result.insert(result.end(),
                    sublist.begin(),
                    sublist.end());
    }

    return result;
  }
};

struct Init_Scope
{
  Ptr<Node> root;
  Args      args;
  Str                 domain;

  Init_Scope(const Str &domain)
    : root(new Node)
    , args()
    , domain(domain)
  { }
};

Init_Scope *g_init_scope()
{
  static auto the_scope = Init_Scope("_G");
  return &the_scope;
}

Init_Scope *acquire_handle(const Str &domain)
{ return new Init_Scope(domain); }

void release_handle(Init_Scope *handle)
{ delete handle; }

void init_register(Init_Scope *handle,
                   Reg &&reg)
{
  RiLogI("register: %s : [%s]", reg.name, str_join(reg.deps, ", "));

  RiRuntime_Assert(handle->root->status == Waiting);

  auto *node = handle->root->prepare_path(reg.name);

  for (auto &&dep : reg.deps)
    node->add_dependence(dep);

  node->activated  = true;

  for (size_t i = 0; i != Stage::Total_Stages; ++i)
  {
    node->reg->tasks[i] = combine_routine( std::move(reg.tasks[i])
                                         , std::move(node->reg->tasks[i]));
  }
}

void init_init(Init_Scope *handle, Args &args)
{
  handle->args = args;

  handle->root->activated = true;
  handle->root->sort();

  handle->root->initialize(handle->args);
}

void init_fini(Init_Scope *handle)
{
  handle->root->finalize(handle->args);
}

void init_register_add_dependence(Init_Scope *handle,
                                  const Str  &path,
                                  const Str  &dep)
{
  auto *node = handle->root->prepare_path(path);

  node->activated = true;

  node->add_dependence(dep);
}

void init_register_add_dependences(Init_Scope     *handle,
                                   const Str      &path,
                                   const Set<Str> &deps)
{
  auto *node = handle->root->prepare_path(path);

  node->activated = true;

  for (auto &&dep : deps)
    node->add_dependence(dep);
}

void init_register_add_dependences_from_string(Init_Scope *handle,
                                          const Str  &path,
                                          const Str  &scheme)
{
  auto deps = split(scheme, ",");

  init_register_add_dependences(handle,
                                path,
                                { deps.begin(), deps.end() });
}

void init_append_routine( Init_Scope   *handle
                        , const Str    &path
                        , size_t        stage
                        , Routine &&routine)
{
  auto *node = handle->root->prepare_path(path);

  node->activated = true;

  node->reg->tasks[stage] = combine_routine(
    std::move(node->reg->tasks[stage])
  , std::move(routine));
}

} // namespace bootstrap
} // namespace ri

