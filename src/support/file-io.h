#pragma once

#include "../prelude.h"

namespace ri {

Buffer read_file(const Str &path);

void write_file(const Str &path, const Buffer &buffer);

} // namespace ri
