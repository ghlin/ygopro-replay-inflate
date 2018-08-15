#pragma once

#include "../prelude.h"
#include "memberdetect.h"

namespace ri {

namespace details {

RiGenerate_Member_Detector(ref_retain);
RiGenerate_Member_Detector(ref_release);
RiGenerate_Member_Detector(ref_count);

} // namespace details

template <class X>
class Ref
{
  static_assert( details::has_member_ref_retain<X>::value
                 && details::has_member_ref_release<X>::value
               , "define `ref_retain' & `ref_release' first.");

  X *repo;
private: // {{{ guarded forward
  inline void safe_retain()
  {
    if (repo)
      repo->ref_retain();
  }

  inline void safe_release()
  {
    if (repo)
      repo->ref_release();
  }
  // }}}

public:
  using reference_type = X;
  using pointer_type   = X *;
public:
  Ref(X *repo) : repo(repo)
  {
    safe_retain();
  }

  Ref(const Ref &ref) : repo(ref.repo)
  {
    safe_retain();
  }

  Ref(Ref &&ref) : repo(ref.repo)
  {
    ref.repo = nullptr;
  }

  ~Ref()
  {
    safe_release();
  }

  template < class T
           , class = std::enable_if_t<!std::is_same<T, X>::value>>
  Ref(T *repo) : Ref(static_cast<X *>(repo)) { }

  template < class T
           , class = std::enable_if_t<!std::is_same<T, X>::value>>
  Ref(const Ref<T> &ref) : Ref(static_cast<X *>(ref.repo)) { }

  template < class T
           , class = std::enable_if_t<!std::is_same<T, X>::value>>
  Ref(Ref<T> &&ref) : Ref(static_cast<X *>(ref.repo))
  {
    ref.repo = nullptr;
  }
public: // {{{ operators
  inline
  Ref &operator =(const Ref &ref)
  {
    if (this == &ref)
      return *this;

    this->~Ref();
    new (this) Ref(ref);

    return *this;
  }

  inline
  Ref &operator =(Ref &&ref)
  {
    if (this == &ref)
      return *this;

    repo = ref.repo;
    ref.repo = nullptr;

    return *this;
  }

  inline       X *operator ->()       { return repo; }
  inline       X *operator ->() const { return repo; }

  inline       X &operator *()       { return *repo; }
  inline       X &operator *() const { return *repo; }

  // }}}

  inline       X *get()       { return repo; }
  inline       X *get() const { return repo; }
public:
  inline auto ref_count() const
  {
    static_assert( details::has_member_ref_count<X>::value
                 , "define `ref_count' for X first.");

    if (repo)
      return repo->ref_count();
    else
      return 0;
  }
};

template <class X>
static inline
auto ref(X *ptr)
{
  return Ref<X>(ptr);
}

template <class T, class X>
static inline
auto ref_as(X *ptr)
{
  return Ref<T>(static_cast<X *>(ptr));
}

template <typename ref_count_t>
class Ref_Count
{
public:
  ref_count_t ref_count = 0;

  Ref_Count()                  { }
  Ref_Count(const Ref_Count &) { }
  Ref_Count(Ref_Count &&)      { }

  inline
  Ref_Count &operator =(const Ref_Count &) { return *this; }

  inline
  Ref_Count &operator =(Ref_Count &&)      { return *this; }

  inline void retain()  {        ++ref_count; }
  inline bool release() { return --ref_count == 0; }
};

} // namespace ri

