#pragma once

#include "../prelude/stdincl.h"
#include "../prelude/stdalias.h"

namespace ri {

// {{{ stringify
namespace details {

template <typename T>
static inline
std::enable_if_t<std::is_integral<T>::value, Str>
stringify_impl(T t)
{
  return std::to_string(t);
}

template <typename ...Args>
static inline
std::enable_if_t<std::is_constructible<Str, Args...>::value, Str>
stringify_impl(Args &&...args)
{
  return Str(std::forward<Args>(args)...);
}

template <typename T>
static inline
std::enable_if_t<!std::is_constructible<Str, T>::value && !std::is_integral<T>::value , Str>
stringify_impl(const T &t)
{
  std::stringstream ss;
  ss << t;
  return ss.str();
}

} // namespace details

template <typename ...Args>
static inline Str stringify(Args &&...args)
{
  return details::stringify_impl(std::forward<Args>(args)...);
}

// }}}

// {{{ split / trim / join

enum class Split_Options { Discard, Compress, Keep };

template <template <typename ...> class Container = Seq>
static inline
Container<Str> split( const Str &input
                    , const Str &sep)
{
  Container<Str> output;

  Str::size_type npos = Str::npos, f = 0, s = 0;
  auto           iter = std::inserter(output, std::end(output));

  while ((s = input.find_first_not_of(sep, f)) != npos)
  {
    f    = input.find_first_of(sep, s);
    iter = input.substr(s, f - s);
  }

  return output;
}

template <template <typename ...> class Container = Seq>
static inline
Container<Str> split_compress( const Str &input
                             , const Str &sep)
{
  Container<Str> output;

  Str::size_type npos = Str::npos, f = 0, s = 0;
  auto           iter = std::inserter(output, std::end(output));

  while ((s = input.find_first_not_of(sep, f)) != npos)
  {
    if (f + 1 < s) iter = "";

    f    = input.find_first_of(sep, s);
    iter = input.substr(s, f - s);
  }

  return output;
}



static inline Str trim_left(const Str &poor_guy)
{
  auto pos = poor_guy.find_first_not_of(" \t\n");

  return pos == Str::npos ? Str() : poor_guy.substr(pos);
}



static inline Str trim_right(const Str &poor_guy)
{
  auto pos = poor_guy.find_last_not_of(" \t\n");

  return pos == Str::npos ? Str() : poor_guy.substr(0, pos + 1);
}



static inline Str trim(const Str &poor_poor_guy)
{
  return trim_right(trim_left(poor_poor_guy));
}


template <class Input, class Lambda = std::function<Str (const Str &)>>
static inline
Str str_map_join(const Input &input,
                 const Str   &sep,
                 Lambda     &&lambda)
{
  auto iter = std::cbegin(input);
  if (iter == std::cend(input))
    return {};

  Str out = lambda(*iter++);

  while (iter != std::cend(input))
  {
    out += sep;
    out += lambda(*iter++);
  }

  return out;
}

template <class Input>
static inline Str str_join(const Input &input,
                           const Str   &sep)
{
  return str_map_join(input, sep, [](const Str &x) { return x; });
}


// }}}

// {{{ pad
static inline
Str pad_right(const Str &src, size_t pad, char fill = ' ')
{
  if (src.length() >= pad)
    return src;
  else
    return src + Str(pad - src.length(), fill);
}

static inline
Str pad_left(const Str &src, size_t pad, char fill = ' ')
{
  if (src.length() >= pad)
    return src;
  else
    return Str(pad - src.length(), fill) + src;
}
// }}}

// {{{ starts with / ends with
static inline
bool starts_with(const Str &str, const Str &prefix)
{
  if (str.length() < prefix.length())
    return false;

  return str.substr(0, prefix.length()) == prefix;
}

static inline
bool ends_with(const Str &str, const Str &prefix)
{
  return starts_with( { str.rbegin(), str.rend() }
                    , { prefix.rbegin(), prefix.rend() });
}


// }}}

// {{{ u_* helpers
// XXX: std::bind doesn't works due to bug:
//      http://lists.llvm.org/pipermail/llvm-bugs/2013-October/030911.html

static inline
auto u_starts_with(const Str &prefix)
{
  return [=] (const Str &s) { return starts_with(s, prefix); };
}

static inline
auto u_ends_with(const Str &prefix)
{
  return [=] (const Str &s) { return ends_with(s, prefix); };
}

template <typename Set>
static inline
auto u_split(const Set &sep_set)
{
  return [=] (const Str &inp) { return split(inp, sep_set); };
}

static inline
auto u_to_string()
{
  return [] (const auto &x) { return std::to_string(x); };
}

static inline
auto u_stringify()
{
  return [] (const auto &x) { return stringify(x); };
}

template <typename T>
static inline
auto u_concat_left(const T &left)
{
  return [=] (const auto &s) { return left + s; };
}

template <typename T>
static inline
auto u_concat_right(const T &right)
{
  return [=] (const auto &s) { return s + right; };
}

template <typename T1, typename T2>
static inline
auto u_decorate(const T1 &left, const T2 &right)
{
  return [=] (const auto &s) { return left + s + right; };
}

// }}}

// {{{ pretty-print utils

static inline
auto reindent( const Str      &head
             , const Str_List &body
             , const Str      &bar  = "")
{
  return head + str_join(body, "\n" + pad_left(bar, head.length()));
}

static inline
auto reindent( const Str &head
             , const Str &body
             , const Str &bar  = "")
{
  return reindent(head, split(body, "\n"), bar);
}

// }}}

} // namespace ri

