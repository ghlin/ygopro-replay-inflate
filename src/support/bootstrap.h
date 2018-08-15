#pragma once

#include "../prelude.h"

namespace ri {
namespace bootstrap {

struct Reg;
struct Args;

using Routine_Prototype    = void (Args &, const Reg &);

using Routine = std::function<Routine_Prototype>;

struct Args
{
  Str          app_name; ///> argv[0]
  Str_List     args;     ///> argv + 1
};

attr_export Args make_args_from_commandline(int argc, const char **argv);

static inline
Args make_empty_args()
{
  return Args { };
}

enum Stage : size_t { Early_Init
                    , Late_Init
                    , Early_Fini
                    , Late_Fini
                    , Total_Stages };

struct Reg
{
  Str           name;
  Set<Str>      deps;

  Routine       tasks[4];
};

static inline auto make_empty_routine()
{
  return [](Args &, const Reg &) { };
}

static inline auto combine_routine( Routine &&first
                                  , Routine &&then)
{
  return [first = std::move(first), then = std::move(then)]
    (Args &args, const Reg &reg) { first(args, reg); then(args, reg); };
}

static inline
auto make_reg( const Str &name
             , const Set<Str> &deps = { }
             , Routine &&early_init = nullptr
             , Routine &&late_init  = nullptr
             , Routine &&early_fini = nullptr
             , Routine &&late_fini  = nullptr)
{
  // do the fallback.
  if (!early_init) early_init = make_empty_routine();
  if (!late_init)  late_init  = make_empty_routine();
  if (!early_fini) early_fini = make_empty_routine();
  if (!late_fini)  late_fini  = make_empty_routine();

  return Reg { name, deps, {
    std::move(early_init), std::move(late_init),
    std::move(early_fini), std::move(late_fini) } };
}

attr_export
Reg make_reg_from_string( const Str &name
                        , const Str &deps = ""
                        , Routine &&early_init = nullptr
                        , Routine &&late_init  = nullptr
                        , Routine &&early_fini = nullptr
                        , Routine &&late_fini  = nullptr);

// {{{
/**
 * opaque handler.
 */
struct Init_Scope;

/**
 * create a Init_Scope.
 */
attr_export Init_Scope *acquire_handle(const Str &domain);

/**
 * release the handler.
 */
attr_export void release_handle(Init_Scope *);

/**
 * register a node.
 *
 * not allowed after `release_handle`, `init_init` called.
 */
attr_export void init_register(Init_Scope *init_scope, Reg &&);


/**
 * add dependence to node "path".
 */
attr_export void init_register_add_dependence( Init_Scope *init_scope
                                             , const Str  &path
                                             , const Str  &dep);

/**
 * add dependences to node "path".
 */
attr_export void init_register_add_dependences( Init_Scope     *init_scope
                                              , const Str      &path
                                              , const Set<Str> &deps);

/**
 * add dependences (from a comma separated string) to node "path".
 */
attr_export void init_register_add_dependences_from_string( Init_Scope *init_scope
                                                          , const Str  &path
                                                          , const Str  &scheme);

/**
 * append action on node "path", action "routine" will be executed at stage "stage"
 */
attr_export void init_append_routine( Init_Scope *init_scope
                                    , const Str  &path
                                    , size_t      stage
                                    , Routine   &&routine);

/**
 * invoke initialization.
 *
 * stage Early_Init, Late_Init.
 */
attr_export void init_init(Init_Scope *init_scope, Args &args);

/**
 * invoke finalization.
 *
 * stage Early_Fini, Late_Fini.
 */
attr_export void init_fini(Init_Scope *init_scope);

// }}}

// {{{ init domain
class Init_Domain
{
  Init_Scope *init_scope;

public:
  Init_Domain(Init_Scope *init_scope) : init_scope(init_scope) { }
  Init_Domain(const Str &domain) : init_scope(acquire_handle(domain)) { }

  inline Init_Domain &operator +=(Reg &&reg)
  {
    init_register(init_scope, std::move(reg));

    return *this;
  }

  inline Init_Domain &operator +=(const Str &path)
  {
    init_register(init_scope, make_reg(path));

    return *this;
  }

  inline Init_Domain &operator +=(const Str_List &nodes)
  {
    for (auto &&path : nodes)
      init_register(init_scope, make_reg(path));

    return *this;
  }

  // {{{ adapter
  class Ops_Adapter
  {
    Init_Scope *init_scope;
    Str path;

  public:
    Ops_Adapter( Init_Scope *init_scope
               , Str &&path)
      : init_scope(init_scope)
      , path(std::move(path)) { }

    inline auto operator [](size_t stage)
    {
      class Ops_Adapter_2 : public Ops_Adapter
      {
        size_t stage;
      public:
        Ops_Adapter_2( Init_Scope *init_scope
                     , Str &&path
                     , size_t stage)
          : Ops_Adapter(init_scope, std::move(path))
          , stage(stage) { }
      public:
        inline Ops_Adapter_2 &operator +=(Routine &&task)
        {
          init_append_routine(init_scope, path, stage, std::move(task));

          return *this;
        }

        inline Ops_Adapter_2 &operator <<(Routine &&task)
        {
          return *this += std::move(task);
        }

        inline Ops_Adapter_2 &operator +=(Func<void (Args &)> &&task)
        {
          auto wrapped_task = [task = std::move(task)]
            (Args &args, const Reg &) { task(args); };

          init_append_routine(init_scope, path, stage, std::move(wrapped_task));

          return *this;
        }

        inline Ops_Adapter_2 &operator <<(Func<void (Args &)> &&task)
        {
          return *this += std::move(task);
        }

        inline Ops_Adapter_2 &operator +=(Func<void (const Reg &)> &&task)
        {
          auto wrapped_task = [task = std::move(task)]
            (Args &, const Reg &regs) { task(regs); };

          init_append_routine(init_scope, path, stage, std::move(wrapped_task));

          return *this;
        }

        inline Ops_Adapter_2 &operator <<(Func<void (const Reg &)> &&task)
        {
          return *this += std::move(task);
        }

        inline Ops_Adapter_2 &operator +=(Func<void (void)> &&task)
        {
          auto wrapped_task = [task = std::move(task)] (Args &, const Reg &) { task(); };

          init_append_routine(init_scope, path, stage, std::move(wrapped_task));

          return *this;
        }

        inline Ops_Adapter_2 &operator <<(Func<void (void)> &&task)
        {
          return *this += std::move(task);
        }

        inline Ops_Adapter_2 &operator <<(const Str &deps)
        {
          *this %= deps;

          return *this;
        }

        inline Ops_Adapter_2 &operator <<(const Str_List &deps)
        {
          *this %= deps;

          return *this;
        }
      };

      return Ops_Adapter_2 { init_scope, Str(path), stage };
    }

    inline Ops_Adapter &operator +=(const Str &dep)
    {
      init_register_add_dependence(init_scope, path, dep);

      return *this;
    }

    inline Ops_Adapter &operator %=(const Str &schema)
    {
      init_register_add_dependences_from_string(init_scope, path, schema);

      return *this;
    }

    inline Ops_Adapter &operator +=(const Str_List &deps)
    {
      for (auto &&dep : deps) *this += dep;
      return *this;
    }

    inline Ops_Adapter &operator %=(const Str_List &deps)
    {
      for (auto &&dep : deps) *this %= dep;
      return *this;
    }

    inline Ops_Adapter &operator <<(const Str &deps)
    {
      return *this %= deps;
    }

    inline Ops_Adapter &operator <<(const Str_List &deps)
    {
      return *this %= deps;
    }

    inline auto operator <<(std::size_t stage)
    {
      return (*this)[stage];
    }
  };
  // }}}

  inline auto operator [](const Str &path)
  {
    return Ops_Adapter { init_scope, Str(path) };
  }

  inline auto operator <<(const Str &path)
  {
    return Ops_Adapter { init_scope, Str(path) };
  }

  // {{{ raii candy
  class RAII_Scope
  {
    Init_Scope *init_scope;
  public:
    RAII_Scope(Init_Scope *init_scope, Args &args) : init_scope(init_scope)
    {
      init_init(init_scope, args);
    }

    ~RAII_Scope()
    {
      init_fini(init_scope);
    }

    RAII_Scope(const RAII_Scope &)      = delete;
    RAII_Scope(RAII_Scope &&)           = delete;

    void operator =(RAII_Scope &&)      = delete;
    void operator =(const RAII_Scope &) = delete;
  };
  // }}}

  inline Ptr<RAII_Scope> bootstrap(Args &args)
  {
    return std::make_unique<RAII_Scope>(init_scope, args);
  }

  inline Ptr<RAII_Scope> bootstrap()
  {
    auto args = make_empty_args();

    return std::make_unique<RAII_Scope>(init_scope, args);
  }
};

// }}}

/**
 * obtain the default/global init handler.
 */
attr_export Init_Scope *g_init_scope();

} // namespace bootstrap
} // namespace ri

#define RiBootstrap_Register(path, scheme) \
  $RiUnsequenced_Static_Scope() \
  { \
    using namespace ::ri::bootstrap; \
    init_register( g_init_scope() \
                 , make_reg_from_string(path, scheme)); \
  }

#define RiBootstrap_Append_Routine(path, stage) \
  namespace { namespace $RiGensym(AR) { \
    static \
    void bootstrap_routine(       ::ri::bootstrap::Args &  \
                          , const ::ri::bootstrap::Reg  &); \
  } } \
  $RiUnsequenced_Static_Scope() \
  { \
    using namespace ::ri::bootstrap; \
    init_append_routine( g_init_scope() \
                       , path \
                       , stage \
                       , $RiGensym(AR)::bootstrap_routine); \
  } void $RiGensym(AR)::bootstrap_routine( \
    attr_unused       ::ri::bootstrap::Args &$args, \
    attr_unused const ::ri::bootstrap::Reg  &$reg)

#define RiBootstrap_Append_Dependences(path, scheme) \
  $RiUnsequenced_Static_Scope() \
  { \
    using namespace ::ri::bootstrap; \
    init_register_add_dependences_from_string(g_init_scope(), path, scheme); \
  }

