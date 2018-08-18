#pragma once
#include "interface.h"

namespace ri::core_msg {

CoreMsg
unpack_one(buffer_ptr *in, size_t len);

Seq<CoreMsg>
unpack(buffer_ptr *in, size_t len);

} // namespace ri::core_msg

