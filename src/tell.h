#pragma once
#include "prelude.h"
#include "core-msg/interface.h"

struct card_data;

namespace ri::story {

struct StoryTellerConfig
{
  Str player_names[2];
};

Seq<Str>
translate( const core_msg::CoreMsg &msg
         , const StoryTellerConfig &cfg);

} // namespace ri::story


