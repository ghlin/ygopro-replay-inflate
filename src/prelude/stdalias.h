#pragma once

#include "stdincl.h"

namespace ri {

using i8  = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8  = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using std::size_t;

template <typename T>
using Opt = std::experimental::optional<T>;

using Str      = std::string;
using Str_List = std::vector<Str>;
using Str_View = std::experimental::string_view;

using Buffer = std::vector<u8>;

template <typename ...T> using Seq     = std::vector<T...>;
template <typename ...T> using List    = std::list<T...>;
template <typename ...T> using Queue   = std::queue<T...>;
template <typename ...T> using Deque   = std::deque<T...>;
template <typename ...T> using Stack   = std::stack<T...>;
template <typename ...T> using Map     = std::map<T...>;
template <typename ...T> using Set     = std::set<T...>;
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

