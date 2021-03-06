#pragma once
#include "../prelude.h"
#include "../core-msg/interface.h"

namespace ri::replay {

struct ReplayMeta;

/**
 * replays a replay.
 *
 * currently, this function just print the messages
 * returned from ocgcore
 *
 */
Seq<core_msg::CoreMsg>
simulate(const ReplayMeta &meta);

/**
 * initialize ocgcore.
 *
 * call this before `replay'
 */
void init_core_engine(const Str &ygopro_root_path);

class UnknownCodeException : public std::runtime_error {
public:
  int code;
  UnknownCodeException(int code): code(code), std::runtime_error("Unknown card") { }
};

} // namespace ri::replay
