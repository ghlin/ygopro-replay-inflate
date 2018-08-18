#pragma once
#include "../prelude/stdalias.h"

namespace ri::ygo_data {

struct StaticCard
{
  u32 id;
  Str name;
  Str description;
  u8  type;
  u8  kind;
  u8  ot;

  /* for monster cards */
  u8   attribute     = 0;
  u8   star          = 0;
  u16  atk           = 0;
  u16  def           = 0;
  u8   pendulumscale = 0;
  u8   link_markers  = 0;
  bool is_normal     = false;
  bool is_effect     = false;
  bool is_ritual     = false;
  bool is_toon       = false;
  bool is_spirit     = false;
  bool is_union      = false;
  bool is_fusion     = false;
  bool is_dual       = false;
  bool is_tunner     = false;
  bool is_synchro    = false;
  bool is_flip       = false;
  bool is_xyz        = false;
  bool is_pendulum   = false;
};

} // namespace ri::ygo_data
