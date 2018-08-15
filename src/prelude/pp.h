#pragma once

/* {{{ core */
#define RiPrefix                  ::ri::
#define RiImpl_Prefix             ::ri::details::

#define RiStd_Prefix              ::std::

#define RiCat2(a, b)              RiCat2_Prim(a, b)
#define RiCat2_Prim(a, b)         a ## b

#define RiTo_Str(s)               RiTo_Str_Prim(s)
#define RiTo_Str_Prim(s)          #s

#define RiCar(x, ...)             x
#define RiCdr(x, ...)             __VA_ARGS__

/* }}} */

/* {{{ nargs */

#define $RiNargs_Select( \
    _0, _1, _2, _3 , _4, _5, _6, _7 \
  , _8, _9, _A, _B , _C, _D, _E, _F \
  , _G,  Q, ...) Q

#define $RiNargs_Fwd(...) $RiNargs_Select(__VA_ARGS__)
#define $RiNargs_Dummy \
    16, 15, 14, 13, 12, 11, 10,  9 \
  ,  8,  7,  6,  5,  4,  3,  2,  1 \
  ,  0

#define RiNargs(...) $RiNargs_Fwd($, ##__VA_ARGS__, $RiNargs_Dummy)

/* }}} */

/* {{{ xgen */

#define $RiJoin_2(L, R)           RiCat2(L, R)
#define $RiJoin_3(L, R...)        RiCat2(L, $RiJoin_2(R))
#define $RiJoin_4(L, R...)        RiCat2(L, $RiJoin_3(R))
#define $RiJoin_5(L, R...)        RiCat2(L, $RiJoin_4(R))
#define $RiJoin_6(L, R...)        RiCat2(L, $RiJoin_5(R))
#define $RiJoin_7(L, R...)        RiCat2(L, $RiJoin_6(R))
#define $RiJoin_8(L, R...)        RiCat2(L, $RiJoin_7(R))
#define $RiJoin_9(L, R...)        RiCat2(L, $RiJoin_8(R))
#define $RiJoin_10(L, R...)       RiCat2(L, $RiJoin_9(R))
#define $RiJoin_11(L, R...)       RiCat2(L, $RiJoin_10(R))
#define $RiJoin_12(L, R...)       RiCat2(L, $RiJoin_11(R))
#define $RiJoin_13(L, R...)       RiCat2(L, $RiJoin_12(R))
#define $RiJoin_14(L, R...)       RiCat2(L, $RiJoin_13(R))
#define $RiJoin_15(L, R...)       RiCat2(L, $RiJoin_14(R))

#define RiJoin(R...)              RiCat2($RiJoin_, RiNargs(R))(R)

#define $RiTranslate_1(M, A, R...)      M(A)
#define $RiTranslate_2(M, A, R...)      M(A), $RiTranslate_1(M, ##R)
#define $RiTranslate_3(M, A, R...)      M(A), $RiTranslate_2(M, ##R)
#define $RiTranslate_4(M, A, R...)      M(A), $RiTranslate_3(M, ##R)
#define $RiTranslate_5(M, A, R...)      M(A), $RiTranslate_4(M, ##R)
#define $RiTranslate_6(M, A, R...)      M(A), $RiTranslate_5(M, ##R)
#define $RiTranslate_7(M, A, R...)      M(A), $RiTranslate_6(M, ##R)
#define $RiTranslate_8(M, A, R...)      M(A), $RiTranslate_7(M, ##R)
#define $RiTranslate_9(M, A, R...)      M(A), $RiTranslate_8(M, ##R)
#define $RiTranslate_10(M, A, R...)     M(A), $RiTranslate_9(M, ##R)
#define $RiTranslate_11(M, A, R...)     M(A), $RiTranslate_10(M, ##R)
#define $RiTranslate_12(M, A, R...)     M(A), $RiTranslate_11(M, ##R)
#define $RiTranslate_13(M, A, R...)     M(A), $RiTranslate_12(M, ##R)
#define $RiTranslate_14(M, A, R...)     M(A), $RiTranslate_13(M, ##R)
#define $RiTranslate_15(M, A, R...)     M(A), $RiTranslate_14(M, ##R)

#define RiTranslate(M, R...)            RiCat2($RiTranslate_, RiNargs(R))(M, ##R)

#define $RiGensym(t) RiCat2($Unit_, RiCat2(t, __LINE__))

/**
 * static block.
 *
 * <code>
 *   $RiUnsequenced_Static_Scope()
 *   {
 *     // code here.
 *   }
 * </code>
 */
#define $RiUnsequenced_Static_Scope() \
  namespace { namespace $RiGensym(Hidden) { \
  struct $RiGensym(Static) { $RiGensym(Static)(); } $RiGensym(obj); } } \
  $RiGensym(Hidden)::$RiGensym(Static)::$RiGensym(Static)()


/* }}} */

