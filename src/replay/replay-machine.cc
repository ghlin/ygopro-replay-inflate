#include "replay-machine.h"
#include "parse-meta.h"
#include "handle-message.h"
#include "../core-card-data/default-storage.h"
#include "../3rd-part/core/ocgapi.h"
#include "../3rd-part/core/mtrandom.h"

namespace ri::replay {

using duel_t = ptr; // long.

uint32
load_from_static_storage(uint32 code, card_data *d)
{
  const auto &card_storage = *core_card_data::default_core_card_storage();
  const auto found = card_storage.lookup.find(code);

  if (found != card_storage.lookup.cend()) {
    *d = found->second;
  } else {
    std::fprintf( stderr
                , "[ERROR] load_from_static_storage: unknown code %d\n"
                , code);

    throw std::runtime_error("load_from_static_storage: unknonw code");
  }

  return 0;
}

duel_t
setup_core_engine(int seed)
{
  mtrandom rnd;
  rnd.reset(seed);

  return create_duel(rnd.rand());
}


void
init_core_engine()
{
  set_script_reader(default_script_reader);
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

