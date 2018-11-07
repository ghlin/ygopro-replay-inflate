#include "replay-machine.h"
#include "parse-meta.h"
#include "handle-message.h"
#include "load-core-cards.h"
#include "../3rd-part/core/ocgapi.h"
#include "../3rd-part/core/mtrandom.h"

namespace ri::replay {

using duel_t = ptr; // long.

static CoreCardStorage default_core_card_storage;

uint32
load_from_static_storage(uint32 code, card_data *d)
{
  const auto found = default_core_card_storage.lookup.find(code);

  if (found != default_core_card_storage.lookup.end()) {
    *d = found->second;
  } else {
    std::fprintf( stderr
                ,  "Unknown card (of code %d)\n"
                   "This may be caused by:\n"
                   "  1) your YGOPRO is out of date, or\n"
                   "  2) the replay file contains DIY card(s) and your YGOPRO edition doesn't\n"
                   "     recognize them.\n"
                   "     If you have the right edition of YGOPRO which generates the replay,\n"
                   "     try re-run replay-inflate and pass it to -p\n"
                , code);

    throw UnknownCodeException(code);
  }

  return 0;
}

duel_t setup_core_engine(int seed)
{
  mtrandom rnd;
  rnd.reset(seed);

  return create_duel(rnd.rand());
}

/*
 * XXX: what ocgcore exposes is `byte *script_reader(const char *, int *)`
 *      it is impossible to load script from arbitrary path without
 *      this variable.
 */
static Str g_ygopro_root_path;

static
byte* read_script_from_ygopro_root_path(const char *script_name, int *slen) {
  const auto real_path = g_ygopro_root_path + "/" + script_name;

  // forward to ocgcore's default script reader.
  return default_script_reader(real_path.c_str(), slen);
}

void
init_core_engine(const Str &ygopro_root_path)
{
  if (ygopro_root_path.empty()) {
    std::fprintf( stderr
                , "[ERROR] YGOPRO_FOLDER is not set");
    throw new std::runtime_error("Option YGOPRO_FOLDER unset");
  }

  // normalize path.
  const auto last_char = ygopro_root_path.at(ygopro_root_path.size() - 1);

  g_ygopro_root_path = last_char == '/'
    ? ygopro_root_path.substr(0, ygopro_root_path.size() - 1)
    : ygopro_root_path;

  default_core_card_storage = make_core_card_storage(load_core_cards(g_ygopro_root_path));

  set_script_reader(read_script_from_ygopro_root_path);
  set_card_reader(load_from_static_storage);
  set_message_handler(default_message_handler);
}

Seq<core_msg::CoreMsg>
simulate(const ReplayMeta &meta)
{
  if (meta.header.flag & REPLAY_TAG) {
    std::fprintf( stderr
                , "[ERROR] sorry, TAG duel not supported\n");
    throw std::runtime_error("unsupported duel mode");
  }

  auto engine = setup_core_engine(meta.header.seed);

  for (int i = 0; i != 2; ++i) {
    set_player_info( engine
                   , i
                   , meta.config.start_lp
                   , meta.config.start_hand
                   , meta.config.draw_count);
  }

  for (int i = 0; i != 2; ++i) {
    for (auto c: meta.players[i].deck.main)
      new_card(engine, c, i, i, LOCATION_DECK, 0, POS_FACEDOWN_DEFENSE);
    for (auto c: meta.players[i].deck.extra)
      new_card(engine, c, i, i, LOCATION_EXTRA, 0, POS_FACEDOWN_DEFENSE);
  }

  start_duel(engine, meta.config.opt);

  u8 msg_buffer[0x1000];

  Replayer replayer(meta, engine);

  Seq<core_msg::CoreMsg> messages;

  while (true) {
    auto process_result = process(engine);
    auto len = process_result & 0xffff;

    if (len <= 0) {
      continue;
    }

    size_t msg_buff_len = get_message(engine, msg_buffer);
    if (msg_buff_len == 0) {
      continue;
    }

    auto should_continue = replayer.handle_message(&messages, msg_buffer, msg_buff_len);
    if (!should_continue) {
      break;
    }
  }

  // shutdown the engine
  end_duel(engine);

  return messages;
}

} // namespace ri::replay

