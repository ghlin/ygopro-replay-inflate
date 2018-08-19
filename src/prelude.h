#pragma once

#include <cstddef>           // size_t
#include <cstdint>           // [u]int_*_t
#include <cstdio>

#include <cstring>           // c style str*

#include <functional>
#include <initializer_list>
#include <utility>           // forward / move

#include <cmath>             // for M_PI / sin / cos ...

#include <algorithm>
#include <iterator>

// tuple
#include <tuple>

// string
#include <string>
#include <string_view>
#include <variant>

// smart pointers
#include <memory>

// nullable
#include <optional>

// tagged union
#include <variant>

// type-erasure container
#include <any>

// better tuple
#include <tuple>

// exceptions
#include <exception>
#include <stdexcept>

// time & date
#include <chrono>
#include <ctime>


// containers
#include <array>
#include <list>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

// stream
#include <sstream>
#include <iostream>

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
using Str_View = std::string_view;

using Buffer = std::vector<u8>;

template <typename ...T> using Seq     = std::vector<T...>;
template <typename ...T> using List    = std::list<T...>;
template <typename ...T> using Queue   = std::queue<T...>;
template <typename ...T> using Deque   = std::deque<T...>;
template <typename ...T> using Stack   = std::stack<T...>;
template <typename ...T> using Map     = std::map<T...>;
template <typename ...T> using Set     = std::set<T...>;
template <typename ...T> using Variant = std::variant<T...>;
template <typename ...T> using HashMap = std::unordered_map<T...>;
template <typename ...T> using HashSet = std::unordered_set<T...>;
template <typename ...T> using Arc     = std::shared_ptr<T...>;
template <typename ...T> using Wrc     = std::weak_ptr<T...>;
template <typename ...T> using Ptr     = std::unique_ptr<T...>;
template <typename ...T> using Func    = std::function<T...>;

#define attr_ctrl(...)        __attribute__((__VA_ARGS__))
#define attr_export           attr_ctrl(visibility("default"))
#define attr_local            attr_ctrl(visibility("hidden"))
#define attr_unused           attr_ctrl(unused)
#define attr_must_use_ret     attr_ctrl(warn_unused_result)
#define attr_packed           attr_ctrl(packed)
#define attr_init(prio)       attr_ctrl(constructor(prio))
#define attr_fini(prio)       attr_ctrl(destructor(prio))

#define RiDefault_Init_Prio     (RiInternal_Init_Prio + 1000 + 1)
#define RiInternal_Init_Prio    (50000)

using namespace std::literals;

namespace $arg = std::placeholders;

} // namespace ri

