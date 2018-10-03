#pragma once

#include <string>
#include <string_view>
#include <tuple>
#include <memory>

namespace ri {

namespace format_details {

template <typename Tail, typename ...List>
struct T_Append { };

template <typename Tail, typename ...List>
struct T_Append<Tail, std::tuple<List...>>
{
  using type = std::tuple<List..., Tail>;
};

template <typename Head, typename ...Tail>
struct T_Car { };

template <typename Head, typename ...Tail>
struct T_Car<std::tuple<Head, Tail...>>
{
  using type = Head;
};

template <typename Head, typename ...Tail>
struct T_Cdr { };

template <typename Head, typename ...Tail>
struct T_Cdr<std::tuple<Head, Tail...>>
{
  using type = std::tuple<Tail...>;
};

template <typename Tail, class Tuple>
using Tuple_Append = typename T_Append<Tail, Tuple>::type;

template <class Tuple>
using Tuple_Car  = typename T_Car<Tuple>::type;

template <class Tuple>
using Tuple_Cdr  = typename T_Cdr<Tuple>::type;

struct Nil { };

template <typename T, class Y, size_t C>
struct T_Has
{
  using H = Tuple_Car<Y>;
  using N = Tuple_Cdr<Y>;

  static constexpr size_t value = T_Has<T, N, std::is_same<T, H>::value ? C + 1 : C>::value;
};

template <typename T, size_t C>
struct T_Has<T, std::tuple<Nil>, C>
{
  static constexpr size_t value = C;
};

template <typename T, typename ...List>
struct has_type
  : std::integral_constant<bool, T_Has<T, std::tuple<List..., Nil>, 0>::value != 0>
{ };

template <typename T, class ...List>
struct has_type<T, std::tuple<List...>> : has_type<T, List...>
{ };

template <class T, class Y, size_t C>
struct T_Dup
{
  using H = Tuple_Car<T>;
  using N = Tuple_Cdr<T>;

  static constexpr size_t value = T_Dup<N, Y, C + T_Has<H, Tuple_Append<Nil, Y>, 0>::value>::value;
};

template <class Y, size_t C>
struct T_Dup<std::tuple<Nil>, Y, C>
{
  static constexpr size_t value = C;
};

template <typename T, class Y>
using has_type_t = has_type<T, Y>;

template <class ...Args>
static inline
std::string
invoke_format_impl( const char    *fmt
                  , const Args &...args)
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"

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

#pragma GCC diagnostic pop
}

template <class TArgs, std::size_t ...I>
static inline
std::string invoke_format(const char  *fmt,
                  const TArgs &targs,
                  std::index_sequence<I...>)
{
  return invoke_format_impl(fmt, std::get<I>(targs)...);
}


struct Format_Ctrl { };

template <size_t N>
static inline const char *
operator %(const Format_Ctrl &, const char (&c_str)[N])
{ return c_str; }

static inline const char *
operator %(const Format_Ctrl &, const std::string &s)
{ return s.c_str(); }

static inline const char *
operator %(const Format_Ctrl &, const std::string_view &s)
{ return s.data(); }

template <typename T>
auto next_one(const T &t, const std::true_type &)
{ return Format_Ctrl() % t; }

template <typename T>
auto next_one(const T t, const std::false_type &)
{ return t; }


// {{{ Safe(?) Format
template <typename T>
auto next_one(const T &t)
{ return next_one(t, std::is_class<std::decay_t<T>>()); }

template <class TArgs, std::size_t ...I>
auto next_helper( const TArgs &targs
                , std::index_sequence<I...>)
{ return std::make_tuple(next_one(std::get<I>(targs))...); }

template <typename ...Args>
auto next_tuple(const std::tuple<Args...> &targs)
{
  return next_helper( targs
                    , std::make_index_sequence<sizeof... (Args)>());
}

template < class TThis
         , class TPrev
         , class TAccu
         , bool = std::is_same<TThis, TPrev>::value
         >
struct Format_Helper
{
  static inline auto format(const std::string &fmt,
                            const TThis &tthis)
  {
    constexpr auto has_bad_recursion = has_type_t<TAccu, TThis>::value;

    static_assert(!has_bad_recursion, "Bad Recursion Detected!");

    auto  tnext = next_tuple(tthis);
    using TNext = decltype(tnext);

    return Format_Helper< TNext
                        , TThis
                        , Tuple_Append<TThis, TAccu>
                        >::format(fmt, tnext);
  }
};

template < class TThis
         , class TPrev
         , class TAccu
         >
struct Format_Helper<TThis, TPrev, TAccu, true>
{
  static inline auto format(const std::string   &fmt,
                            const TThis &tthis)
  {
    constexpr auto I = std::tuple_size<TThis>::value;

    return invoke_format( fmt.c_str()
                        , tthis
                        , std::make_index_sequence<I>());
  }
};

// }}}

// {{{ Misc
template <typename T, std::size_t I>
const T *fit_tuple(const T (&array)[I]) { return array; }

template <typename T>
const T &fit_tuple(const T &t) { return t; }

template <typename ...Args>
auto make_arg_tuple(const Args &...args)
{ return std::make_tuple(fit_tuple(args)...); }


} // namespace format_details

template <typename ...Args>
static inline
std::string
format(const std::string &fmt, const Args &...args)
{
  struct Nil;

  auto   targs = format_details::make_arg_tuple(args...);
  using  TThis = decltype(targs);

  return format_details::Format_Helper< TThis
                                      , Nil
                                      , std::tuple<Nil>
                                      >::format(fmt, targs);
}

} // namespace ri

