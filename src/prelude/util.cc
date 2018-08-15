#include "util.h"
#include "stdalias.h"

#include <cxxabi.h>

namespace ri {

Str u_name_demangle(const Str &mangled_name)
{
  auto demangled_name = abi::__cxa_demangle( mangled_name.c_str()
                                           , nullptr
                                           , nullptr
                                           , nullptr);
  auto _ = defer_with (s = demangled_name) { free(s); };

  return { demangled_name };
}

} // namespace ri



