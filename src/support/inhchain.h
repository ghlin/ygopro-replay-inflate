#pragma once

#include "../prelude.h"

namespace ri {
namespace details {

struct End_Of_Chain;

template <class Super, class Klass>
struct Pack
{
  using super = Super;
  using klass = Klass;
};

template <class pack, class I, class ...R>
struct chain_impl
{
  using repack = Pack< typename chain_impl<pack, R...>::klass
                     , typename pack::klass>;

  using klass = typename I::template Closure<repack>;
};

template <class pack>
struct chain_impl<pack, End_Of_Chain>
{
  using klass = typename pack::super;
};

} // namespace details

template <class pack, class ...R>
class chain : public details::chain_impl<pack, R..., details::End_Of_Chain>::klass
{
private:
  using Chain_Base = typename details::chain_impl
    < pack
    , R...
    , details::End_Of_Chain>::klass;
protected:
  using super = chain;
public:
  using Chain_Base::Chain_Base;
};

template <template <class ...> class F, class ...Partial_Args>
struct partially_apply
{
  template <class Pack> using Closure = F<Pack, Partial_Args...>;
};

#define $partially_apply(x)          $partially_apply_helper x
#define $partially_apply_helper(...) RiPrefix partially_apply<__VA_ARGS__>
#define $pack(p)                     $pack_helper p
#define $pack_helper(...)            RiImpl_Prefix Pack<__VA_ARGS__>
#define $chain(pack, ...)            RiPrefix chain<$pack(pack), RiTranslate($partially_apply, __VA_ARGS__)>

} // namespace ri

