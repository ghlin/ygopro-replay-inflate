#include "default-storage.h"
#include "load.h"

namespace ri::core_card_data {

static CoreCardStorage the_default_core_card_storage;

const CoreCardStorage *
default_core_card_storage()
{
  return &the_default_core_card_storage;
}

void
load_core_card_storage(const Str &path)
{
  the_default_core_card_storage =
    make_core_card_storage(load_core_cards("from-sqlite3.json"));
}

} // namespace ri::core_card_data
