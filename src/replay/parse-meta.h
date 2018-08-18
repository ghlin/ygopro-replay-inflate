#pragma once

#include "../prelude.h"

namespace ri::replay {

using CardList = Seq<i32>;

struct Deck
{
  CardList main, extra;
};

struct ReplayPlayer
{
  u16  name[20];
  Deck deck;
};


// from ygopro/gframe/replay.h
#define REPLAY_COMPRESSED 0x1
// from ygopro/gframe/replay.h
#define REPLAY_TAG 0x2
// from ygopro/gframe/replay.h
#define REPLAY_DECODED 0x4
// from ygopro/gframe/replay.h
#define REPLAY_SINGLE_MODE 0x8

// from ygopro/gframe/replay.h
struct ReplayHeader {
  unsigned int id;
  unsigned int version;
  unsigned int flag;
  unsigned int seed;
  unsigned int datasize;
  unsigned int hash;
  unsigned char props[8];
};

struct ReplayDuelConfig {
  int start_lp;
  int start_hand;
  int draw_count;
  int opt;
};

struct ReplayMeta {
  ReplayHeader      header;
  ReplayDuelConfig  config;
  Seq<ReplayPlayer> players;

  /**
   * data section (uncompressed if necessary).
   */
  Buffer           data;
};

ReplayMeta
parse_replay_meta(const Buffer &buffer);

} // namespace ri::replay

