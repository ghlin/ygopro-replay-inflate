#include "dump.h"
#include "../support.h"
#include "../core/common.h"

namespace ri::core_msg {

#include "core-msg-dump.gen.inl"
#include "core-msg-dump-visitor.gen.inl"

Str
dump(const CoreMsg &msg)
{
  return std::visit(CoreMsgDumpVisitor(), msg);
}

} // namespace ri::core_msg

