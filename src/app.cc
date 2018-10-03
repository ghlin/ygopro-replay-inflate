#include "support/file-io.h"
#include "support/format.h"
#include "replay/replay-machine.h"
#include "replay/parse-meta.h"
#include "core-card-data/default-storage.h"
#include "tell.h"
#include "core-msg/dump.h"
#include "3rd-part/nlohmann-json/json.hpp"

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

namespace ri {

int run_tell_mode( const Seq<core_msg::CoreMsg> &messages
                 , Opt<Str>                      out_file
                 , bool                          write_to_stdout)
{
  const story::StoryTellerConfig cfg = { { "Player1", "Player2" } };

  for (const auto &msg: messages) {
    const auto lines = story::translate(msg, cfg);
    for (const auto &line: lines) {
      std::cout << line << std::endl;
    }
    if (!lines.empty()) {
      std::cout << std::endl;
    }
  }

  return 0;
}

int run_dump_mode( const Seq<core_msg::CoreMsg> &messages
                 , Opt<Str>                      out_file
                 , bool                          write_to_stdout)
{
  for (const auto &msg: messages) {
    std::cout << dump(msg) << std::endl;
  }

  return 0;
}


} // namespace ri

/*
 * @@@ project.cppflags: -std=c++2a
 * @@@ project.cflags: -std=c99
 * @@@ link: -llua
 * @@@ project: replay-inflate
 */

int main(int argc, const char **argv)
{
  using namespace ri;

  // TODO: load from sqlite db(use ygopro's assets).
  Opt<Str> in_file, out_file;
  bool tell_mode = false;
  bool write_to_stdout = false;

  enum Mode { In_File, Out_File };

  // parse args.

  Mode mode = In_File;
  bool double_hyphen = false;

  for (int i = 1; i != argc; ++i) {
    const Str arg = argv[i];

    if (arg.empty()) continue;

    if (arg == "--") {
      double_hyphen = true;
      continue;
    }

    if (!double_hyphen && arg[0] == '-') {
      if (arg == "-t" || arg == "--tell") {
        tell_mode = true;
      } else if (arg == "-u" || arg == "--stdout") {
        write_to_stdout = true;
      } else if (arg == "-o" || arg == "--output") {
        mode = Out_File;
      }
    } else if (mode == In_File) {
      if (in_file) {
        std::cerr << "too many input files!" << std::endl;
        return -1;
      }
      in_file = { arg };
    } else if (mode == Out_File) {
      if (out_file) {
        std::cerr << "too many output files!" << std::endl;
        return -1;
      }
      out_file = { arg };
      mode = In_File;
    }

    double_hyphen = false;
  }

  if (!in_file) {
    std::cerr << "no input file!" << std::endl;
    return -1;
  }

  try {
    const auto yrp_buffer = read_file(*in_file);
    const auto yrp_meta   = replay::parse_replay_meta(yrp_buffer);

    // load cards.
    core_card_data::load_core_card_storage("from-sqlite3.json");

    // init the engine anyway.
    replay::init_core_engine();

    const auto messages = replay::simulate(yrp_meta);

    if (tell_mode) {
      return run_tell_mode(messages, out_file, write_to_stdout);
    } else {
      return run_dump_mode(messages, out_file, write_to_stdout);
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return -1;
  }
}

