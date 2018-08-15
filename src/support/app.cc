#include "support.h"
#include "bootstrap.h"

namespace ri { int main(const Str_List &args); } // namespace ri

int main(int argc, const char **argv)
{
  using namespace ri;
  using namespace ri::bootstrap;

  auto args = make_args_from_commandline(argc, argv);

  bootstrap::init_init(g_init_scope(), args);

  int exit_status = ri::main(u_map( u_collect(argv, argv + argc)
                                  , [] (auto *arg) { return Str(arg); }));

  bootstrap::init_fini(g_init_scope());

  return exit_status;
}


