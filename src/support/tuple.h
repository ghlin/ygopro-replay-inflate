#pragma once

#include "../prelude/stdincl.h"

namespace ri {
namespace traits {
namespace details {

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

template <class T>
struct has_dup_type
  : std::integral_constant<bool, T_Dup<Tuple_Append<Nil, T>, T, 0>::value != std::tuple_size<T>::value>
{
  static constexpr size_t NDups = T_Dup<Tuple_Append<Nil, T>, T, 0>::value;
};

} // namespace details

template <typename T, class Y>
using has_type_t = details::has_type<T, Y>;

template <class T>
using has_dup_type_t = details::has_dup_type<T>;

} // namespace traits
} // namespace ri

