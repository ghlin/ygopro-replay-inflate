#pragma once

#include <cstddef>           // size_t
#include <cstdint>           // [u]int_*_t
#include <cstdio>
#include <cstring>           // c style str*

#include <functional>
#include <utility>           // forward / move

#include <algorithm>
#include <iterator>

#include <string>
#include <tuple>

// smart pointers
#include <memory>

// nullable
#include <optional>

// tagged union
#include <variant>

// exceptions
#include <exception>
#include <stdexcept>

// containers
#include <array>
#include <list>
#include <vector>
#include <map>
#include <set>

namespace ri {

using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using buffer_ptr = const u8 *;

using std::size_t;

template <typename T>
using Opt = std::optional<T>;

using Str      = std::string;
using Str_List = std::vector<Str>;

using Buffer = std::vector<u8>;

template <typename ...T> using Seq     = std::vector<T...>;
template <typename ...T> using List    = std::list<T...>;
template <typename ...T> using Map     = std::map<T...>;
template <typename ...T> using Set     = std::set<T...>;
template <typename ...T> using Variant = std::variant<T...>;
template <typename ...T> using Arc     = std::shared_ptr<T...>;
template <typename ...T> using Wrc     = std::weak_ptr<T...>;
template <typename ...T> using Ptr     = std::unique_ptr<T...>;
template <typename ...T> using Func    = std::function<T...>;

using namespace std::literals;

} // namespace ri

