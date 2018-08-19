#include "handle-message.h"
#include "../core-msg/unpack.h"
#include "../core-msg/dump.h"
#include "../3rd-part/core/ocgapi.h"

namespace ri::replay {

bool
next_response(long engine, buffer_ptr *buff, buffer_ptr end)
{
  if (*buff == end) {
    return false;
  }

  auto len = *((*buff)++);

  if (*buff + len > end) {
    return false;
  }

  u8 resp_buff[100];
  std::memcpy(resp_buff, *buff, len);

  set_responseb(engine, resp_buff);

  *buff += len;

  return true;
}

bool
Replayer::handle_message( Seq<core_msg::CoreMsg> *messages
                        , buffer_ptr buffer
                        , size_t len)
{
  const auto end_of_buffer = buffer + len;
  buffer_ptr pbuff = buffer;

  while (pbuff != end_of_buffer)
  {
    if (pbuff > end_of_buffer) {
      return false;
    }

    const auto msg_type = *pbuff;
    if (msg_type == MSG_RETRY) {
      return false;
    }

    const auto remain = end_of_buffer - pbuff;
    const auto msg    = core_msg::unpack_one(&pbuff, remain);

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
    }

    messages->emplace_back(std::move(msg));
  }

  return true;
}

} // namespace ri::replay
