#include "support/file-io.h"
#include "replay/replay-machine.h"
#include "replay/parse-meta.h"
#include "core-msg/dump.h"
#include "3rd-part/nlohmann-json/json.hpp"
#include "options.h"

#include <iostream>
#include <fstream>

namespace ri::core_msg {
void to_json(nlohmann::json &j, const CoreMsg &msg)
{
  j = nlohmann::json::parse(core_msg::dump_json(msg));
}
} // namespace ri::core_msg

namespace ri::replay {
void to_json(nlohmann::json &j, const ReplayHeader &replay_header)
{
  j["id"]      = replay_header.id;
  j["version"] = replay_header.version;
  j["hash"]    = replay_header.hash;
  // there're no need to export other fields here.
}

void to_json(nlohmann::json &j, const ReplayDuelConfig &duel_config)
{
  j["start_lp"]   = duel_config.start_lp;
  j["start_hand"] = duel_config.start_hand;
  j["draw_count"] = duel_config.draw_count;
  j["duel_rule"]  = duel_config.opt;
}

void to_json(nlohmann::json &j, const ReplayPlayer &replay_player)
{
  j["name_buffer"]   = replay_player.name;
  j["deck"]["main"]  = replay_player.deck.main;
  j["deck"]["extra"] = replay_player.deck.extra;
}

void to_json(nlohmann::json &j, const ReplayMeta &meta)
{
  j["header"]  = meta.header;
  j["config"]  = meta.config;
  j["players"] = meta.players;
}
} // namespace ri::replay

int main(int argc, const char **argv) try
{
  auto options = ri::parse_command_line_options(argc, argv);

  if (!options) {
    std::cerr << ri::CommandLineOptions::usage << std::endl;
    return -1;
  }

  if (options->display_usage_only) {
    std::cerr << ri::CommandLineOptions::usage << std::endl;
    return 0;
  }

  if (options->display_version_only) {
    std::cerr << ri::CommandLineOptions::version << std::endl;
    return 0;
  }

  const auto ygopro_root   = options->ygopro_root_path.value_or(".");
  const auto replay_file   = options->replay_file_path.value_or(ygopro_root + "/replay/_LastReplay.yrp");
  const auto replay_buffer = ri::read_file(replay_file);
  const auto replay_meta   = ri::replay::parse_replay_meta(replay_buffer);

  ri::replay::init_core_engine(ygopro_root);

  const auto messages = ri::replay::simulate(replay_meta);

  nlohmann::json inflated = replay_meta;
  nlohmann::json data_json = messages;
  inflated["records"] = data_json;

  const auto &output_file = options->output_file_path;

  if (!output_file) {
    std::cout << inflated.dump(2);
  } else {
    std::ofstream target(*output_file);
    if (!target) {
      std::cerr << "Cannot write to file " << *output_file << std::endl;
      return -3;
    }

    target << inflated.dump(2);
  }

  return 0;
} catch (const ri::replay::UnknownCodeException &) {
  // be quiet...
}

