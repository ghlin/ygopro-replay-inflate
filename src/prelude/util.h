#pragma once

#include "stdincl.h"
#include "pp.h"

namespace ri {

// {{{ obj-ctrl

/**
 * construct a `T' at `ptr' with `args...'
 */
template <class T, class ...Args>
static inline
T *u_construct(void *ptr, Args &&...args)
{
  return new (ptr) T(std::forward<Args>(args)...);
}

/**
 * destruct a `T'.
 *
 * non trivial, call it's dtor.
 */
template <class T>
static inline
std::enable_if_t<!std::is_trivially_destructible<T>::value>
u_destruct(T *ptr)
{
  ptr->~T();
}

/**
 * destruct a `T'.
 *
 * trivial type, do noting.
 */
template <class T>
static inline
std::enable_if_t<std::is_trivially_destructible<T>::value>
u_destruct(T *) { }


/**
 * reconstruct a `T' at `ptr'.
 */
template <class T, class ...Args>
static inline
T *u_reconstruct(T *ptr, Args &&...args)
{
  u_destruct(ptr);
  return u_construct<T>(ptr, std::forward<Args>(args)...);
}

// }}}

// {{{ RAII-Helper

namespace details {

using RAII_Helper_Closure = std::function<void (void)>;

class RAII_Helper
{
  RAII_Helper_Closure closure;
public:
  RAII_Helper() : closure() { }

  template <class Lambda>
  RAII_Helper(Lambda &&lambda)
    : closure(std::forward<Lambda>(lambda))
  { }

  RAII_Helper(RAII_Helper &&)       = default;
  RAII_Helper(const RAII_Helper &)  = delete;

  RAII_Helper &operator =(RAII_Helper &&)      = default;
  RAII_Helper &operator =(const RAII_Helper &) = default;

  /**
   * cancel all the pending stuffs.
   */
  inline void retract() { closure = [] { }; }

  /**
   * do it now.
   */
  inline void commit()
  {
    this->~RAII_Helper();
    new (this) RAII_Helper;
  }

  ~RAII_Helper() { if (closure) closure(); }

  /**
   * take over ownership.
   *
   * `ptr' will be deleted by `deletor' after RAII_Helper object dead.
   */
  template <typename T, class D>
  inline T *manage(T *ptr, D &&deletor)
  {
    auto old = std::move(closure);
    closure  = [ptr, pre = std::move(old), deletor = std::forward<D>(deletor)]
    {
      deletor(ptr);
      if (pre)
        pre();
    };

    return ptr;
  }

  template <typename T, class D>
  inline const T *manage(const T *ptr, D &&deletor)
  {
    auto old = std::move(closure);
    closure  = [ptr, pre = std::move(old), deletor = std::forward<D>(deletor)]
    {
      deletor(ptr);
      if (pre)
        pre();
    };

    return ptr;
  }

  /**
   * take over ownership.
   *
   * `ptr' will be deleted by delete operator after RAII_Helper object dead.
   */
  template <typename T>
  inline T *manage(T *ptr)
  {
    return manage(ptr, [] (T *ptr) { delete ptr; });
  }

  /**
   * take over ownership.
   *
   * `ptr' will be deleted by delete operator after RAII_Helper object dead.
   */
  template <typename T>
  inline const T *manage(const T *ptr)
  {
    return manage(ptr, [] (T *ptr) { delete ptr; });
  }
};

struct RAII_Helper_Candy
{
  template <class Lambda>
  inline RAII_Helper operator +(Lambda &&lambda) const
  {
    return RAII_Helper(std::forward<Lambda>(lambda));
  }
};

} // namespace details

/**
 * make a defer block.
 *
 * <code>
 * auto reminader = defer { ... };
 *
 * reminader.manage(...);
 * reminader.manage(...);
 *
 * // bang., reminader dead.
 * </code>
 */
#define defer           ::ri::details::RAII_Helper_Candy() + []
#define defer_with(...) ::ri::details::RAII_Helper_Candy() + [__VA_ARGS__]

// }}}

// {{{ misc

template <typename ...T>
struct hint_t { using packed = std::tuple<T...>; };

static inline
bool u_check_bit(uint64_t pattern, uint64_t mask)
{
  return (pattern & mask) == mask;
}

template <typename I = unsigned>
static inline
auto u_pattern_of(unsigned i)
{
  return I(1u) << i;
}

static inline
bool u_check_bit_at(uint64_t pattern, unsigned i)
{
  return u_check_bit(pattern, u_pattern_of(i));
}

/**
 * make a nice formatted string from a managled version.
 */
std::string u_name_demangle(const std::string &mangled_name);

/**
 * make a nice formatted string for type `T'
 */
template <typename T>
static inline
std::string u_pretty_typename()
{
  return u_name_demangle(typeid (T).name());
}

// }}}

} // namespace ri

