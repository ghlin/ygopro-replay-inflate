#include "parse-meta.h"
#include "../3rd-part/lzma/LzmaLib.h"

namespace ri::replay {

static_assert(sizeof (ReplayHeader) == 32);
static_assert(sizeof (ReplayDuelConfig) == 16);

Deck parse_deck(buffer_ptr *ppbuff);

Buffer
uncompress( const u8 *raw_data
          , size_t len
          , const ReplayHeader &header)
{
  if (!(header.flag & 0x1))
    return Buffer(raw_data, raw_data + len);

  size_t replay_size = header.datasize;

#define UNCOMPRESS_BUFFER_SIZE 0x10000
  if (UNCOMPRESS_BUFFER_SIZE < replay_size) {
    std::fprintf( stderr
                , "[ERROR] replay file too large! buffer size: %d, replay file size: %zu\n"
                , UNCOMPRESS_BUFFER_SIZE
                , replay_size);
    throw std::runtime_error("replay file too large!");
  }

  unsigned char uncompress_buffer[UNCOMPRESS_BUFFER_SIZE];

  // from ygopro/gframe/replay.cpp
  const auto uncompress_result = LzmaUncompress( uncompress_buffer
                                               , &replay_size
                                               , raw_data
                                               , &len
                                               , header.props
                                               , 5);

  if (uncompress_result != SZ_OK) {
    std::fprintf( stderr
                , "[ERROR] failed to uncompress replay file: %s\n"
                , uncompress_result == SZ_ERROR_DATA        ? "SZ_ERROR_DATA"
                : uncompress_result == SZ_ERROR_UNSUPPORTED ? "SZ_ERROR_UNSUPPORTED"
                : uncompress_result == SZ_ERROR_INPUT_EOF   ? "SZ_ERROR_INPUT_EOF"
                : "unknown reason");
    throw std::runtime_error("failed to uncompress replay file");
  }

  return Buffer(uncompress_buffer, uncompress_buffer + replay_size);
}

ReplayMeta
parse_replay_meta(const Buffer &buffer)
{
  const auto *raw_ptr = &buffer.front();
  ReplayHeader header = *reinterpret_cast<
    const ReplayHeader *>(raw_ptr);
  auto uncompressed_buffer = uncompress( raw_ptr + sizeof header
                                       , buffer.size() - sizeof header
                                       , header);

  header.datasize  = uncompressed_buffer.size();

  const auto nplayers = (header.flag & REPLAY_TAG)         ? 4
                      : (header.flag & REPLAY_SINGLE_MODE) ? 0
                      : 2;

  if (!nplayers) {
    std::fprintf( stderr
                , "[ERROR] replay mode unsupported\n");
    throw std::runtime_error("replay mode unspported");
  }

  Seq<ReplayPlayer> players;

  const auto *raw_data = &uncompressed_buffer.front();

  for (auto i = 0; i != nplayers; ++i) {
    players.push_back({});
    std::copy( raw_data
             , raw_data + sizeof players[i].name
             , reinterpret_cast<u8 *>(players[i].name));

    raw_data += sizeof players[i].name;
  }

  ReplayDuelConfig config = *reinterpret_cast<
    const ReplayDuelConfig *>(raw_data);

  raw_data += sizeof config;

  for (auto i = 0; i != nplayers; ++i)
    players[i].deck = parse_deck(&raw_data);

  const auto *raw_data_end = &uncompressed_buffer.back();
  return { header
         , config
         , players
         , Buffer(raw_data, raw_data_end)
         };
}

CardList
parse_card_list(buffer_ptr *ppbuff)
{
  i32 count = *reinterpret_cast<const i32 *>(*ppbuff);

  CardList cards;
  for (int i = 0; i != count; ++i) {
    i32 id = *reinterpret_cast<const i32 *>(*ppbuff += 4);
    cards.push_back(id);
  }

  *ppbuff += 4;

  return cards;
}

Deck
parse_deck(buffer_ptr *ppbuff)
{
  CardList main = parse_card_list(ppbuff);
  CardList extra = parse_card_list(ppbuff);

  return { main, extra };
}

} // namespace ri::replay

