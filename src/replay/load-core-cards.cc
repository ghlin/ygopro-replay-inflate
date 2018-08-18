#include "load-core-cards.h"
#include "../nlohmann-json/json.hpp"
#include "../support.h"

#include <fstream>

namespace ri::replay {

using json_t = nlohmann::json;

card_data
load_core_card(const json_t &j)
{
  card_data c;

  c.code      = j["id"].get<u32>();
  c.alias     = j["alias"].get<u32>();
  c.setcode   = j["setcode"].get<u64>();
  c.type      = j["type"].get<u32>();
  c.level     = j["level"].get<u32>();
  c.attribute = j["attribute"].get<u32>();
  c.race      = j["race"].get<u32>();
  c.attack    = j["atk"].get<i32>();
  c.defense   = j["def"].get<i32>();

  if (c.type & TYPE_LINK) {
    c.link_marker = c.defense;
    c.defense = 0;
  } else {
    c.link_marker = 0;
  }

  c.lscale = (c.level >> 24) & 0xff;
  c.rscale = (c.level >> 16) & 0xff;
  c.level  = c.level & 0xff;

  return c;
}

Seq<card_data>
load_core_cards(const Str &file_path)
{
  std::ifstream file(file_path);
  if (!file) {
    RiPanicF("Cannot open file %s", file_path);
  }

  json_t j;
  file >> j;

  Seq<card_data> cards;
  for (auto iter = j.begin(); iter != j.end(); ++iter) {
    cards.push_back(load_core_card(iter.value()));
  }

  return cards;
}

CoreCardStorage
make_core_card_storage(const Seq<card_data> &cards)
{
  CoreCardStorage cc;
  for (const auto &c: cards) {
    cc.lookup[c.code] = c;
  }

  return cc;
}


} // namespace ri::replay
