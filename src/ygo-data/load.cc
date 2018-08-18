#include "load.h"

#include "../support.h"
#include "../nlohmann-json/json.hpp"
#include <fstream>

namespace ri::ygo_data {

using json_t =  nlohmann::json;

void
read_json_from_file(json_t &j, const Str &file)
{
  std::ifstream file_stream(file);

  if (!file_stream) {
    RiPanicF("Cannot open file %s", file);
  }

  file_stream >> j;
}

void
read_json_from_string(json_t &j, const Str &source)
{
  j = nlohmann::json::parse(source);
}

StaticCard
load_card_from_json_object(const json_t &j)
{
  StaticCard c;
  c.id          = std::stoi(j["id"].get<Str>());
  c.name        = j["name"].get<Str>();
  c.description = j["description"].get<Str>();
  c.type        = j["_type"].get<u8>();
  c.kind        = j["_kind"].get<u8>();
  c.ot          = 0;

  if (c.kind == 1) {
    c.attribute     = j["_attribute"].get<u8>();
    c.star          = j["star"].get<u8>();
    c.atk           = j["atk"].get<u16>();
    c.def           = j["def"].get<u16>();
    c.pendulumscale = j["pendulumscale"].get<u8>();
    c.link_markers  = 0;
#define READ_FIELD(n) c.is_##n = (j.count("_" #n) != 0)
    (RiTranslate( READ_FIELD
                , normal
                , effect
                , ritual
                , toon
                , spirit
                , union
                , fusion
                , dual));
    (RiTranslate( READ_FIELD
                , tunner
                , synchro
                , flip
                , xyz
                , pendulum));
  }

  return c;
}

Seq<StaticCard>
load_all_from_json(const json_t &j)
{
  Seq<StaticCard> allcards;
  for (auto iter = j.begin(); iter != j.end(); ++iter) {
    RiLogI("loading card %s", iter.key());
    allcards.push_back(load_card_from_json_object(iter.value()));
  }

  RiLogI("total: %zu cards", allcards.size());

  return allcards;
}

Seq<StaticCard>
load_from_json(const Str &json_string)
{
  json_t j;
  read_json_from_string(j, json_string);
  return load_all_from_json(j);
}

Seq<StaticCard>
load_from_json_file(const Str &json_file)
{
  json_t j;
  read_json_from_file(j, json_file);
  return load_all_from_json(j);
}


} // namespace ri::ygo_data

