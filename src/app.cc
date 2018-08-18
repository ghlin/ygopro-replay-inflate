#include "support.h"
#include "replay/replay-machine.h"

namespace ri {

int main(attr_unused const Str_List &args)
{
  const auto replay_buffer = read_file("test.yrp");

  replay::init_core_engine();

  try {
    replay::replay(replay_buffer);
  } catch (const std::exception &e) {
    RiLogE("e: %s", e.what());
  } catch (...) {
    RiLogE("ops.");
  }

  return 0;
}

} // namespace ri

