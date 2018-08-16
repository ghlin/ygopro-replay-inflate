#include "support.h"
#include "core/ocgapi.h"
#include "replay/parse-meta.h"

namespace ri {

int main(attr_unused const Str_List &args)
{
  const auto replay_file_path = args[1];
  const auto replay_file_content = read_file(replay_file_path);
  const auto replay_meta = parse_replay_meta(replay_file_content);

  const auto format_str = R"(
    replay_file:            %s
    replay_file_size:       %zu
    ---
    replay.header.datasize: %zu
    replay.buffer.size:     %zu
    ---
    replay.header.id:       %08x
    replay.header.flag:     %08x
    replay.header.version:  %08x
    ---
    replay.players.[0].deck.main.size:  %d
    replay.players.[0].deck.extra.size: %d
    replay.players.[1].deck.main.size:  %d
    replay.players.[1].deck.extra.size: %d)";

  RiLogI( format_str
        , replay_file_path
        , replay_file_content.size()
        , replay_meta.header.datasize
        , replay_meta.data.size()
        , replay_meta.header.id
        , replay_meta.header.flag
        , replay_meta.header.version
        , replay_meta.players[0].deck.main.size()
        , replay_meta.players[0].deck.extra.size()
        , replay_meta.players[1].deck.main.size()
        , replay_meta.players[1].deck.extra.size());

  return 0;
}

} // namespace ri

