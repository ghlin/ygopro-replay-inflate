#pragma once

#include "static-card.h"
#include "../prelude.h"

namespace ri::ygo_data {

Seq<StaticCard>
load_from_json(const Str &json_string);

Seq<StaticCard>
load_from_json_file(const Str &json_file);

} // namespace ri::ygo_data

