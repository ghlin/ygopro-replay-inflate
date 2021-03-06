#pragma once

#include "interface.h"
#include "../prelude.h"

namespace ri::core_msg {

Str dump(const CoreMsg &msg);

Str dump_json(const CoreMsg &msg);

} // namespace ri::core_msg
