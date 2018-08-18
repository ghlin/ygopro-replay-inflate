#pragma once
#include "../prelude.h"

namespace ri::replay {

/**
 * replays a replay.
 *
 * currently, this function just print the messages
 * returned from ocgcore
 *
 */
void replay(const Buffer &replay_content);

/**
 * initialize ocgcore.
 *
 * call this before `replay'
 */
void init_core_engine();

} // namespace ri::replay
