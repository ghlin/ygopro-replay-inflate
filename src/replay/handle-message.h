#pragma once

#include "../prelude.h"
#include "../core-msg/interface.h"
#include "parse-meta.h"

namespace ri::replay {

struct Replayer
{
  ReplayMeta meta;
  long       engine;
  buffer_ptr next;

  Replayer( const ReplayMeta &meta
          , long  engine)
    : meta(meta), engine(engine)
  {
    next = &meta.data.front();
  }

  bool
  handle_message(Seq<core_msg::CoreMsg> *messages, buffer_ptr buffer, size_t len);
};

} // namespace ri::replay
