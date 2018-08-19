#pragma once
#include "../prelude.h"
#include "../core-msg/interface.h"

namespace ri::replay {

/**
 * replays a replay.
 *
 * currently, this function just print the messages
 * returned from ocgcore
 *
 */
Seq<core_msg::CoreMsg>
replay(const Buffer &replay_content);

/**
 * initialize ocgcore.
 *
 * call this before `replay'
 */
void init_core_engine();

} // namespace ri::replay
