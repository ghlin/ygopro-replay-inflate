#pragma once

#include "../prelude.h"
#include "tuple.h"

namespace ri {

namespace details {

// {{{ invoke format
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
template <class ...Args>
static inline
Str invoke_format_impl(const char    *fmt,
                       const Args &...args)
{
  auto desired_buff_length = std::snprintf(nullptr, 0, fmt, args...);

  constexpr auto default_buff_length = 1024 * 4 + 1;

  if (default_buff_length > desired_buff_length)
  {
    char buff[default_buff_length];
    std::sprintf(buff, fmt, args...);

    return { buff };
  }
  else
  {
    auto storage = std::unique_ptr<char []>(new char[desired_buff_length + 1]);
    std::sprintf(storage.get(), fmt, args...);

    return { storage.get() };
  }
}
#pragma GCC diagnostic pop

template <class TArgs, std::size_t ...I>
static inline
Str invoke_format(const char  *fmt,
                  const TArgs &targs,
                  std::index_sequence<I...>)
{
  return invoke_format_impl(fmt, std::get<I>(targs)...);
}

// }}}

// {{{ Format Ctrl
struct Format_Ctrl { };

template <size_t N>
static inline const char *
operator %(const Format_Ctrl &, const char (&c_str)[N])
{ return c_str; }

static inline const char *
operator %(const Format_Ctrl &, const Str &s)
{ return s.c_str(); }

static inline const char *
operator %(const Format_Ctrl &, const Str_View &s)
{ return s.data(); }

template <typename T>
auto next_one(const T &t, const std::true_type &)
{ return Format_Ctrl() % t; }

template <typename T>
auto next_one(const T t, const std::false_type &)
{ return t; }

// }}}

// {{{ Safe(?) Format
template <typename T>
auto next_one(const T &t)
{ return next_one(t, std::is_class<std::decay_t<T>>()); }

template <class TArgs, std::size_t ...I>
auto next_helper(const TArgs &targs,
                 std::index_sequence<I...>)
{ return std::make_tuple(next_one(std::get<I>(targs))...); }

template <typename ...Args>
auto next_tuple(const std::tuple<Args...> &targs)
{
  return next_helper(targs,
                     std::make_index_sequence<sizeof... (Args)>());
}

template < class TThis
         , class TPrev
         , class TAccu
         , bool = std::is_same<TThis, TPrev>::value
         >
struct Format_Helper
{
  static inline auto format(const Str &fmt,
                            const TThis &tthis)
  {
    constexpr auto has_bad_recursion = traits::has_type_t<TAccu, TThis>::value;

    static_assert(!has_bad_recursion, "Bad Recursion Detected!");

    auto  tnext = next_tuple(tthis);
    using TNext = decltype(tnext);

    return Format_Helper< TNext
                        , TThis
                        , traits::details::Tuple_Append<TThis, TAccu>
                        >::format(fmt, tnext);
  }
};

template < class TThis
         , class TPrev
         , class TAccu
         >
struct Format_Helper<TThis, TPrev, TAccu, true>
{
  static inline auto format(const Str   &fmt,
                            const TThis &tthis)
  {
    constexpr auto I = std::tuple_size<TThis>::value;

    return invoke_format(fmt.c_str(),
                         tthis,
                         std::make_index_sequence<I>());
  }
};

// }}}

// {{{ Misc
template <typename T, std::size_t I>
const T *fit_tuple(const T (&array)[I])
{ return array; }

template <typename T>
const T &fit_tuple(const T &t)
{ return t; }

template <typename ...Args>
auto make_arg_tuple(const Args &...args)
{ return std::make_tuple(fit_tuple(args)...); }

// }}}

} // namespace details

template <typename ...Args>
static inline
Str format(const Str &fmt, const Args &...args)
{
  using namespace details;
  struct Nil;

  auto   targs = details::make_arg_tuple(args...);
  using  TThis = decltype(targs);

  return Format_Helper< TThis
                      , Nil
                      , std::tuple<Nil>
                      >::format(fmt, targs);
}

} // namespace ri

