#pragma once

#include "../prelude.h"
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
  handle_message(buffer_ptr buffer, size_t len);
};

} // namespace ri::replay
