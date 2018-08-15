#pragma once

#include "../prelude/stdincl.h"
#include "../prelude/stdalias.h"
#include "../prelude/memberdetect.h"

namespace ri {

// {{{ u_* utilities

// {{{ universal push-back
namespace details {

$RiGenerate_Member_Detector(emplace_back);

template < typename Container
         , typename ...Args>
auto push_impl( Container &c
              , const std::true_type &
              , Args &&...args)
{
  return c.emplace_back(std::forward<Args>(args)...);
}

template < typename Container
         , typename ...Args>
auto push_impl( Container &c
              , const std::false_type &
              , Args &&...args)
{
  return c.emplace(std::forward<Args>(args)...);
}

template < typename Container
         , typename ...Args>
auto u_push(Container &c, Args &&...args)
{
  return push_impl( c
                  , has_member_emplace_back<std::decay_t<Container>>()
                  , std::forward<Args>(args)...);
}

} // namespace details

using details::u_push;

// }}}

// {{{ map
template < template <typename ...> class Container = Seq
         , typename Input
         , typename Lambda
         >
static inline
auto u_map( const Input  &input
          , Lambda      &&lambda)
{
  using Element = std::decay_t<decltype (lambda(*std::cbegin(input)))>;
  using Output  = Container<Element>;

  Output output;

  auto end = std::cend(input);

  for (auto it = std::cbegin(input); it != end; ++it)
    u_push(output, lambda(*it));

  return output;
}



template < template <typename ...> class Container = Seq
         , typename Element
         , typename Lambda
         >
static inline
auto u_map( std::initializer_list<Element> &&input
          , Lambda                         &&lambda)
{
  using Output  = Container<Element>;

  Output output;

  auto end = std::cend(input);

  for (auto it = std::cbegin(input); it != end; ++it)
    u_push(output, lambda(std::move(*it)));

  return output;
}

template < template <typename ...> class Container = Seq
         , typename Input
         , typename Lambda
         >
static inline
auto u_map_index( const Input  &input
                , Lambda      &&lambda)
{
  using Element = std::decay_t<decltype (lambda(*std::cbegin(input), size_t(0)))>;
  using Output  = Container<Element>;

  Output output;
  size_t idx = 0;

  auto end = std::cend(input);

  for (auto it = std::cbegin(input); it != end; ++it)
    u_push(output, lambda(*it, idx++));

  return output;
}



template < template <typename ...> class Container = Seq
         , typename Element
         , typename Lambda
         >
static inline
auto u_map_index( std::initializer_list<Element> &&input
                , Lambda                         &&lambda)
{
  using Output  = Container<Element>;

  Output output;
  size_t idx = 0;

  for (auto &&e : input)
    u_push(output, lambda(std::move(e), idx++));

  return output;
}
// }}}

// {{{ filter
template < class    Container
         , typename Lambda
         >
static inline
auto u_filter_cp( const Container  &input
                , Lambda          &&lambda)
{
  Container output;

  auto end = std::cend(input);

  for (auto it = std::cbegin(input); it != end; ++it)
    if (lambda(*it))
      u_push(output, *it);

  return output;
}

template < template <typename ...> class Container = Seq
         , typename T
         , typename Lambda
         >
static inline
auto u_filter_cp( std::initializer_list<T> &&input
                , Lambda                   &&lambda)
{
  Container<T> output;

  for (auto &&e : input)
    if (lambda(e))
      u_push(output, std::move(lambda(e)));

  return output;
}

template < class    Container
         , typename Lambda
         >
static inline
auto u_filter_inp( Container &input
                 , Lambda   &&lambda)
{
  input.erase(std::remove_if(std::begin(input),
                             std::end(input),
                             std::forward<Lambda>(lambda)));

  return input;
}

template < typename T
         , typename Lambda
         >
static inline
auto u_filter_inp( List<T>  &input
                 , Lambda  &&lambda)
{
  input.remove_if(std::begin(input),
                  std::end(input),
                  std::forward<Lambda>(lambda));

  return input;
}

// }}}

// {{{ fold
template < typename Output
         , typename Input
         , typename Lambda
         >
static inline
Output u_foldl( Output        output
              , const Input  &input
              , Lambda      &&lambda)
{
  auto end = std::cend(input);

  for (auto it = std::cbegin(input); it != end; ++it)
    output = lambda(output, *it);

  return output;
}

template < typename Output
         , typename Input
         , typename Lambda
         >
static inline
Output u_foldr( Output        output
              , const Input  &input
              , Lambda      &&lambda)
{
  for (auto iter = std::crbegin(input); iter != std::crend(input); ++iter)
    output = lambda(output, *iter);

  return output;
}

template < typename Output
         , typename Element
         , typename Lambda
         >
static inline
Output u_foldl( Output                           output
              , std::initializer_list<Element> &&input
              , Lambda                         &&lambda)
{
  for (auto &&ele : input)
    output = lambda(output, std::move(ele));

  return output;
}

template < typename Output
         , typename Element
         , typename Lambda
         >
static inline
Output u_foldr( Output                           output
              , std::initializer_list<Element> &&input
              , Lambda                         &&lambda)
{
  for (auto iter = std::crbegin(input); iter != std::crend(input); ++iter)
    output = lambda(output, std::move(*iter));

  return output;
}

// }}}

// {{{ flatten

template < template <typename ...> class Output = Seq
         , class Container_Of_Container
         >
static inline
auto u_flatten(const Container_Of_Container &set)
{
  using Output_Container = std::decay_t<decltype(*std::cbegin(set))>;
  using Output_Element   = std::decay_t<decltype(*std::cbegin(std::declval<Output_Container>()))>;

  Output<Output_Element> output;

  auto out_end = std::cend(set);

  for (auto it = std::cbegin(set); it != out_end; ++it)
  {
    auto &subset = *it;
    auto in_end = std::cend(subset);

    for (auto it = std::cbegin(subset); it != in_end; ++it)
      u_push(output, *it);
  }

  return output;
}

template < template <typename ...> class Output = Seq
         , class Output_Element
         >
static inline
auto u_flatten(const std::initializer_list<Output_Element> &set)
{
  Output<Output_Element> output;

  for (auto &&subset : set)
  {
    auto end = std::cend(subset);
    for (auto it = std::cbegin(subset); it != end; ++it)
      u_push(output, *it);
  }

  return output;
}

// }}}

// {{{ intersperse

template <class Container>
static inline
auto
u_intersperse(const Container &set, const typename Container::value_type &in)
{
  Container out;
  auto i = std::cbegin(set);
  u_push(out, *i);

  while (++i != std::cend(set))
  {
    u_push(out, in);
    u_push(out, *i);
  }

  return out;
}

template < template <typename ...> class Container = Seq
         , class T>
static inline
auto
u_intersperse( std::initializer_list<T> &&set
             , const T &in)
{
  Container<std::decay_t<T>> out;

  auto i = std::cbegin(set);
  u_push(out, std::move(*i));

  while (++i != std::cend(set))
  {
    u_push(out, in);
    u_push(out, std::move(*i));
  }

  return out;
}

// }}}

// {{{ zip
// TODO: zip-n 2016-10-18 10:45:09

template < template <typename ...> class Out = Seq
         , class Left
         , class Right
         >
static inline
auto
u_zip( const Left &left
     , const Right &right)
{
  using Out_Element = std::pair< typename Left::value_type
                               , typename Right::value_type>;
  using Output = Out<Out_Element>;

  Output output;

  auto li = std::cbegin(left);
  auto ri = std::cbegin(right);

  while (li != std::cend(left) && ri != std::cend(right))
  {
    u_push(output, std::make_pair(*li++, *ri++));
  }

  return output;
}

template < template <typename ...> class Out = Seq
         , class Left_Type
         , class Right
         >
static inline
auto
u_zip( const std::initializer_list<Left_Type> &left
     , const Right &right)
{
  using Out_Element = std::pair< Left_Type
                               , typename Right::value_type>;
  using Output = Out<Out_Element>;

  Output output;

  auto li = std::cbegin(left);
  auto ri = std::cbegin(right);

  while (li != std::cend(left) && ri != std::cend(right))
  {
    u_push(output, std::make_pair(*li++, *ri++));
  }

  return output;
}

template < template <typename ...> class Out = Seq
         , class Left
         , class Right_Type
         >
static inline
auto
u_zip( const Left &left
     , const std::initializer_list<Right_Type> &right)
{
  using Out_Element = std::pair< typename Left::value_type
                               , Right_Type>;
  using Output = Out<Out_Element>;

  Output output;

  auto li = std::cbegin(left);
  auto ri = std::cbegin(right);

  while (li != std::cend(left) && ri != std::cend(right))
  {
    u_push(output, std::make_pair(*li++, *ri++));
  }

  return output;
}

template < template <typename ...> class Out = Seq
         , class Left_Type
         , class Right_Type
         >
static inline
auto
u_zip( const std::initializer_list<Left_Type>  &left
     , const std::initializer_list<Right_Type> &right)
{
  using Out_Element = std::pair<Left_Type , Right_Type>;
  using Output = Out<Out_Element>;

  Output output;

  auto li = std::cbegin(left);
  auto ri = std::cbegin(right);

  while (li != std::cend(left) && ri != std::cend(right))
  {
    u_push(output, std::make_pair(*li++, *ri++));
  }

  return output;
}
// }}}

// {{{ group

template < template <typename ...> class Container = Seq
         , template <typename ...> class Inner_Container = Seq
         , typename Input
         , typename Lambda
         >
static inline
auto u_group( const Input &input
            , Lambda     &&compare)
{
  using Element = std::decay_t<decltype(*std::cbegin(input))>;
  using Inner   = Inner_Container<Element>;
  using Output  = Container<Inner>;

  Output output;
  Inner  collected;

  auto it  = std::cbegin(input);
  auto end = std::cend(input);

  if (it == end)
    return Output { };

  auto last = it;

  u_push(collected, *it);

  for (++it; it != end; ++it)
  {
    if (!compare(*it, *last))
    {
      u_push(output, collected);
      collected.clear();
    }

    last = it;
    u_push(collected, *it);
  }

  u_push(output, collected);
  return output;
}

template < template <typename ...> class Container = Seq
         , template <typename ...> class Inner_Container = Seq
         , typename T
         , typename Lambda
         >
static inline
auto u_group( const std::initializer_list<T> &input
            , Lambda &&compare)
{
  using Element = std::decay_t<T>;
  using Inner   = Inner_Container<Element>;
  using Output  = Container<Inner>;

  Output output;
  Inner  collected;

  auto it  = std::cbegin(input);
  auto end = std::cend(input);

  if (it == end)
    return Output { };

  auto last = it;

  u_push(collected, *it);

  for (++it; it != end; ++it)
  {
    if (!compare(*it, *last))
    {
      u_push(output, collected);
      collected.clear();
    }

    last = it;
    u_push(collected, *it);
  }

  u_push(output, std::move(collected));
  return output;
}

template < template <typename ...> class Container = Seq
         , template <typename ...> class Inner_Container = Seq
         , typename Input
         , typename Lambda
         >
static inline
auto u_group_by( const Input &input
               , Lambda &&key)
{
  auto compare = [key = std::forward<Lambda>(key)] (auto &l, auto &r)
                 {
                   return key(l) == key(r);
                 };

  return u_group<Container, Inner_Container>(input, std::move(compare));
}

template < template <typename ...> class Container = Seq
         , template <typename ...> class Inner_Container = Seq
         , typename T
         , typename Lambda
         >
static inline
auto u_group_by( const std::initializer_list<T> &input
               , Lambda &&key)
{
  auto compare = [key = std::forward<Lambda>(key)] (const auto &l, const auto &r)
                 {
                   return key(l) == key(r);
                 };

  return u_group<Container, Inner_Container>(input, std::move(compare));
}

// }}}

// {{{ find / has

template <class T, class K>
static inline
auto u_find(const T &c, const K &k)
  -> Opt<decltype(c.find(k)->second)>
{
  auto found = c.find(k);

  if (found == c.end())
    return { };
  else
    return { found->second };
}

template <class T, class K>
static inline
auto u_find(const T &c, K &&k)
  -> Opt<std::decay_t<decltype(*std::find(std::cbegin(c), std::cend(c), std::forward<K>(k)))>>
{
  auto found = std::find(std::cbegin(c), std::cend(c), std::forward<K>(k));

  if (found == std::cend(c))
    return { };
  else
    return { *found };
}

template <class T, class K>
static inline
auto u_find_ptr(const T &c, const K &k)
{
  auto found = c.find(k);

  if (found == c.end())
    return nullptr;

  return &found->second;
}

template <class T, class K>
static inline
bool u_has(const T &c, const K &k)
{
  return c.find(k) != c.cend();
}

// }}}

// {{{ helpers

template <typename T_>
static inline
auto u_id_function_of_()
{
  using T = std::decay_t<T_>;

  return [=] (const T &t) -> const T & { return t; };
}

static inline
auto u_id_function_()
{
  return [=] (const auto &x) -> std::decay_t<decltype(x)> & { return x; };
}

template <template <typename ...> class Out = Seq>
static inline
auto u_repeat_(size_t n)
{
  return [=] (auto &x) { return Out<std::decay_t<decltype(x)>>(n, x); };
}

template <template <typename ...> class Out>
static inline
auto u_pure_()
{
  return [] (auto &x) { return Out<std::decay_t<decltype(x)>>(x); };
}

template <typename Container>
static inline
auto u_pusher_(Container &c)
{
  return [&] (auto &x) { u_push(c, x); };
}

template <typename Lambda>
static inline
auto u_pair_mapper_(Lambda &&lambda)
{
  return [lambda = std::forward<Lambda>(lambda)] (auto &&pair)
    -> decltype(auto)
  {
    return lambda(pair.first, pair.second);
  };
}

// }}}

// {{{ container

template < template <typename ...> class Container = Seq
         , typename I
         , typename E>
static inline
auto u_collect(I first, E last)
{
  struct _ { I first; E last;
    I cbegin() const { return first; }
    E cend()   const { return last; } };

  return u_map<Container>(_ { first, last }, u_id_function_());
}

template < template <typename ...> class Container = Seq
         , typename I>
static inline
auto u_collect(I first, I last)
{
  using T = std::decay_t<decltype(*first)>;

  return Container<T>(first, last);
}

template < template <typename ...> class Container = Seq
         , typename Input>
static inline
auto u_collect(const Input &input)
{
  return u_collect<Seq>(std::cbegin(input), std::cend(input));
}

template < template <typename ...> class Container = Seq
         , typename T>
static inline
auto u_collect(std::initializer_list<T> &&il)
{
  return Container<T>(std::move(il));
}


// }}}

// }}}

} // namespace ri

