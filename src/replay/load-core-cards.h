#pragma once
#include "../prelude.h"
#include "../core/card.h"

namespace ri::replay {

Seq<card_data>
load_core_cards(const Str &file_path);

struct CoreCardStorage
{
  Map<u32, card_data> lookup;
};

CoreCardStorage
make_core_card_storage(const Seq<card_data> &cards);

} // namespace ri::replay

