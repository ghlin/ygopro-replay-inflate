#pragma once

// Member Detector
// from https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Member_Detector

#include <type_traits>
#include "pp.h"

/**
 * generate a member(variable) detector in namespace "ns".
 */
#define $RiGenerate_Member_Detector_With_NS(member, ns) \
namespace ns { \
template <class Target> \
struct RiCat2(Member_Detector_For_, member) \
{ \
  struct Fallback { int member; }; \
  struct Derived : public Target, Fallback { }; \
 \
  template <class U> \
  static std::false_type test(decltype(U::member) *); \
  template <class U> \
  static std::true_type  test(...); \
 \
  using result_type = decltype(test<Derived>(nullptr)); \
}; \
} /* namespace ns */ \
 \
template <class Target> \
struct RiCat2(has_member_, member) \
  : ns::RiCat2(Member_Detector_For_, member)<Target>::result_type \
{ }

/**
 * generate a nested-typedef detector in namespace "ns".
 */
#define $RiGenerate_Typedef_Detector_With_NS(member, ns) \
namespace ns { \
template <class Target> \
struct RiCat2(Typedef_Detector_For_, member) \
{ \
  struct Fallback { struct member { }; }; \
  struct Derived : public Target, Fallback { }; \
 \
  template <class U> \
  static std::false_type test(typename U::member *); \
  template <class U> \
  static std::true_type  test(U *); \
 \
  using result_type = decltype(test<Derived>(nullptr)); \
}; \
} /* namespace ns */ \
 \
template <class Target> \
struct RiCat2(has_typedef_, member) \
  : ns::RiCat2(Typedef_Detector_For_, member)<Target>::result_type \
{ }

#define $RiGenerate_Member_Detector(member)  $RiGenerate_Member_Detector_With_NS(member, details)
#define $RiGenerate_Typedef_Detector(member) $RiGenerate_Typedef_Detector_With_NS(member, details)
#define $RiGenerate_Member_Detector_1(m)     $RiGenerate_Member_Detector(m)
#define $RiGenerate_Typedef_Detector_1(m)    $RiGenerate_Typedef_Detector(m)
#define $RiGenerate_Member_Detector_2(m, n)  $RiGenerate_Member_Detector_With_NS(m, n)
#define $RiGenerate_Typedef_Detector_2(m, n) $RiGenerate_Typedef_Detector_With_NS(m, n)

/* {{{ export */

/**
 * generate a member(variable) detector in namespace "details".
 */
#define RiGenerate_Member_Detector(...) \
  RiCat2($RiGenerate_Member_Detector_, RiNargs(__VA_ARGS__))(__VA_ARGS__)

/**
 * generate a nested-typedef detector in namespace "details".
 */
#define RiGenerate_Typedef_Detector(...) \
  RiCat2($RiGenerate_Typedef_Detector_, RiNargs(__VA_ARGS__))(__VA_ARGS__)

/* }}} */

