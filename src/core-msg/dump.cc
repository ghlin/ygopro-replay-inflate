#include "dump.h"
#include "../3rd-part/core/common.h"
#include <sstream>
#include <iomanip>

namespace ri::core_msg {

template <typename T>
static inline
Str
format_value(T value)
{
  std::stringstream builder;

  // C++'s stream format manip is awful!
  builder
    << "0x"
    << std::setfill('0')
    << std::setw(2 * sizeof value)
    << std::hex
    << static_cast<int>(value)
    << " / "
    << std::dec
    << static_cast<int>(value);

  return builder.str();
}

#include "core-msg-dump.gen.inl"
#include "core-msg-dump-visitor.gen.inl"

Str
dump(const CoreMsg &msg)
{
  return std::visit(CoreMsgDumpVisitor(), msg);
}

#include "core-msg-dump-json.gen.inl"
#include "core-msg-dump-json-visitor.gen.inl"

Str
dump_json(const CoreMsg &msg)
{
  return std::visit(CoreMsgDumpJsonVisitor(), msg);
}

} // namespace ri::core_msg

