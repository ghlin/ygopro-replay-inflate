#pragma once
#include "../prelude.h"
#include "storage.h"

namespace ri::core_card_data {

Seq<CoreCardData>
load_core_cards(const Str &file_path);

CoreCardStorage
make_core_card_storage(const Seq<CoreCardData> &cards);

} // namespace ri::core_card_data

