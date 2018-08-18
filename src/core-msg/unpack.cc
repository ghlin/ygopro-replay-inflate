#include "unpack.h"
#include "../support.h"
#include "../core/common.h"

namespace ri::core_msg {

template <typename X>
static inline
X
buffer_next( buffer_ptr *in
           , buffer_ptr  end
           , const char *label
           , unsigned    line
           , const char *func)
{
  const auto span = sizeof (X);
  if (end < *in + span) {
    RiPanicF( "end of buffer reached when parsing %s\n"
              "                           in file %s\n"
              "                           at line %d"
            , label
            , func
            , line);
  }

  auto x = *reinterpret_cast<const X *>(*in);
  *in += span;
  return x;
}

#include "core-msg-unpack.gen.inl"

CoreMsg
unpack_one(buffer_ptr *in, size_t len)
{
  const auto end = *in + len;
  auto msg_type = buffer_next<u8>(in, end, "(msg_type / u8)", __LINE__, __func__);
#define HANDLE_UNKNOWN_MSG \
  RiPanicF("Unknown message: %02x (%d)", msg_type, msg_type);

#include "core-msg-switch.gen.inl"

  RiPanicF("unexpected end");
}

Seq<CoreMsg>
unpack(buffer_ptr *in, size_t len)
{
  Seq<CoreMsg> messages;

  while (len) {
    const auto mark = *in;
    messages.emplace_back(unpack_one(in, len));
    size_t span = *in - mark;
    len = span > len ? 0 : len - span;
  }

  return messages;
}

} // namespace ri::core_msg
