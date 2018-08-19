#include "support/file-io.h"
#include "replay/replay-machine.h"
#include "core-msg/dump.h"
#include "3rd-part/nlohmann-json/json.hpp"

namespace ri::core_msg {
void to_json(nlohmann::json &j, const core_msg::CoreMsg &msg)
{
  j = nlohmann::json::parse(core_msg::dump_json(msg));
}
} // namespace ri::core_msg


int main(int argc, const char **argv)
{
  const auto replay_buffer = ri::read_file(argc > 1 ? argv[1] : "_LastReplay.yrp");

  ri::replay::init_core_engine();

  const auto messages = ri::replay::replay(replay_buffer);
  nlohmann::json full_json = messages;
  std::cout << full_json.dump(2);

  return 0;
}

