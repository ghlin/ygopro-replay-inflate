#pragma once
#include "../prelude.h"
#include "../3rd-part/core/card.h"

namespace ri::core_card_data {

struct CoreCardData: card_data
{
  Str name;
  Str desc;
};

struct CoreCardStorage
{
  Map<u32, CoreCardData> lookup;
};

} // namespace ri::core_card_data

