#pragma once

#include "format.h"
#include "string.h"

namespace ri {

struct Src_Location
{
  unsigned    line;
  const char *file;
  const char *func;
  const char *pretty_func;

  inline Str dump() const
  {
    using namespace std::string_literals;

    return "[ File: "s + file
      +    ", Line: "s + std::to_string(line)
      +    ", Func: "s + func
      +    " ]";
  }
};

namespace details {

static inline
Str operator <<( const Format_Ctrl &
               , const Src_Location &sl)
{
  using namespace std::string_literals;

  return "[ "s + sl.file
    +    ", "s + std::to_string(sl.line)
    +    ", "s + sl.func
    +    " ]"s;
}

} // namespace details
} // namespace ri

#define RiSrc_Location           \
  RiPrefix Src_Location {        \
    __LINE__, __FILE__, __func__, \
    __PRETTY_FUNCTION__  }

namespace ri {
namespace details {

Str tracef_text_impl(const Str &, const Str &);

template <typename ...Args>
static inline
Str tracef_text( const Str  &header
               , const Args &...args)
{ return tracef_text_impl(header, format(args...)); }

template <typename ...Args>
static inline
Str tracef(const Str &header, const Args &...fmt_and_args)
{
  auto text = tracef_text(header, fmt_and_args...);
  std::fprintf(stderr, "%s", text.c_str());
  return text;
}

Str shortify_path(const Str &path);

} // namespace details
} // namespace ri

#define RiTraceF_Default_Header(L)       RiPrefix \
  format("[%s] %-15s %3d", L, RiImpl_Prefix shortify_path(__FILE__), __LINE__)
#define RiTraceF_With_Level(L, ...)      RiImpl_Prefix tracef(RiTraceF_Default_Header(L), __VA_ARGS__)
#define RiTraceF_Text_With_Level(L, ...) RiImpl_Prefix tracef_text(RiTraceF_Default_Header(L), __VA_ARGS__)

#define RiTraceF(...) RiTraceF_With_Level("I", __VA_ARGS__)
#define RiErrorF(...) RiTraceF_With_Level("E", __VA_ARGS__)
#define RiWarnF(...)  RiTraceF_With_Level("W", __VA_ARGS__)

#define RiTraceF_Text(...) RiTraceF_Text_With_Level("I", __VA_ARGS__)
#define RiErrorF_Text(...) RiTraceF_Text_With_Level("E", __VA_ARGS__)
#define RiWarnF_Text(...)  RiTraceF_Text_With_Level("W", __VA_ARGS__)

#define RiPanicF(...) throw std::runtime_error("PANIC!!!\n" + RiTraceF_Text_With_Level("Panic", __VA_ARGS__))

#define $RiAssertion_Failed_Fmt(...)                      \
  "Assertion failed: [%s]", #__VA_ARGS__

#define RiRuntime_Assert(...) do { \
  if ((__VA_ARGS__)) { } \
    else RiPanicF($RiAssertion_Failed_Fmt(__VA_ARGS__)); \
  } while (false)

#define RiRuntime_Ensure(...) do { \
  if ((__VA_ARGS__)) { } \
    else RiErrorF($RiAssertion_Failed_Fmt(__VA_ARGS__)); \
  } while (false)

#ifndef NDEBUG
#define RiLogI(...) RiTraceF(__VA_ARGS__)
#define RiLogE(...) RiErrorF(__VA_ARGS__)
#define RiLogW(...) RiWarnF(__VA_ARGS__)
#define RiAssert(...) RiRuntime_Assert(__VA_ARGS__)
#define RiEnsure(...) RiRuntime_Ensure(__VA_ARGS__)
#else
#define RiLogI(...)   do { } while (false)
#define RiLogE(...)   do { } while (false)
#define RiLogW(...)   do { } while (false)
#define RiAssert(...) do { } while (false)
#define RiEnsure(...) do { } while (false)
#endif

