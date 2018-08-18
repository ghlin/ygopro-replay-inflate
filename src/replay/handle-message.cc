#include "handle-message.h"
#include "../core-msg/unpack.h"
#include "../core-msg/dump.h"
#include "../core/ocgapi.h"
#include "../support.h"

namespace ri::replay {

bool
next_response(long engine, buffer_ptr *buff, buffer_ptr end)
{
  if (*buff == end) {
    RiLogE("replay-data-buffer reached end-of-buffer");

    return false;
  }

  auto len = *((*buff)++);

  if (*buff + len > end) {
    RiLogE("replay-data-buffer reached end-of-buffer");

    return false;
  }

  u8 resp_buff[100];
  std::memcpy(resp_buff, *buff, len);

  RiLogI("respond with %d bytes data", len);
  set_responseb(engine, resp_buff);

  *buff += len;

  return true;
}

bool
Replayer::handle_message(buffer_ptr buffer, size_t len)
{
  const auto end_of_buffer = buffer + len;
  buffer_ptr pbuff = buffer;

  while (pbuff != end_of_buffer)
  {
    if (pbuff > end_of_buffer) {
      RiLogE("buffer out of bound.");
      return false;
    }

    const auto msg_type = *pbuff;
    const size_t buffer_length_remain = end_of_buffer - pbuff;

    if (msg_type == MSG_RETRY) {
      return false;
    }

    if (msg_type == MSG_UPDATE_DATA) {
      RiLogI("TODO :: MSG_UPDATE_DATA");
      return true;
    }

    if (msg_type == MSG_UPDATE_CARD) {
      RiLogI("TODO :: MSG_UPDATE_CARD");
      return true;
    }

    auto save = pbuff;

    const auto msg = core_msg::unpack_one(&pbuff, buffer_length_remain);

    RiLogI("message type  = %d, span = %d, remain = %zu", msg_type, pbuff - save, buffer_length_remain);
    RiLogI(reindent("core > ", core_msg::dump(msg)));

    switch (msg_type)
    {
    case MSG_SELECT_BATTLECMD:
    case MSG_SELECT_IDLECMD:
    case MSG_SELECT_EFFECTYN:
		case MSG_SELECT_YESNO:
		case MSG_SELECT_OPTION:
		case MSG_SELECT_CARD:
		case MSG_SELECT_TRIBUTE:
		case MSG_SELECT_UNSELECT_CARD:
		case MSG_SELECT_CHAIN:
		case MSG_SELECT_PLACE:
		case MSG_SELECT_DISFIELD:
		case MSG_SELECT_POSITION:
		case MSG_SELECT_COUNTER:
		case MSG_SELECT_SUM:
		case MSG_SORT_CARD:
		case MSG_SORT_CHAIN:
		case MSG_ROCK_PAPER_SCISSORS:
		case MSG_ANNOUNCE_RACE:
		case MSG_ANNOUNCE_ATTRIB:
		case MSG_ANNOUNCE_CARD:
		case MSG_ANNOUNCE_NUMBER:
		case MSG_ANNOUNCE_CARD_FILTER:
      if (!next_response(engine, &next, &meta.data.back())) {
        return false;
      }

      break;
    }
  }

  return true;
}

} // namespace ri::replay
