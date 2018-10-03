#pragma once

#include "storage.h"

namespace ri::core_card_data {

/**
 * the core-card data.
 */
const CoreCardStorage *default_core_card_storage();

/**
 * load core-card.
 */
void load_core_card_storage(const Str &path);

} // namespace ri::core_card_data

