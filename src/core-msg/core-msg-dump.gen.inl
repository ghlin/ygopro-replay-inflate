/* !!! Generated code, DO NOT EDIT !!! */

static inline std::string dump_CoreMsg_SHUFFLE_SET_CARD(const CoreMsg_SHUFFLE_SET_CARD &msg) {
  std::string dump = "[[MSG_SHUFFLE_SET_CARD]]\n";
  dump += "\n  location :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  cards1   :: Card[" + format("%zu", msg.cards1.size()) + "] =";
  for (const auto &it: msg.cards1) {
    dump += "\n  {";
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    ignore     :: u8  = " + format("%3d / %02x", it.ignore, it.ignore);
    dump += "\n  }";
  }
  dump += "\n  cards2   :: Card[" + format("%zu", msg.cards2.size()) + "] =";
  for (const auto &it: msg.cards2) {
    dump += "\n  {";
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    ignore     :: u8  = " + format("%3d / %02x", it.ignore, it.ignore);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_RETRY(const CoreMsg_RETRY &msg) {
  std::string dump = "[[MSG_RETRY]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_HINT(const CoreMsg_HINT &msg) {
  std::string dump = "[[MSG_HINT]]\n";
  dump += "\n  type   :: u8  = " + format("%3d / %02x", msg.type, msg.type);
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  data   :: u32 = " + format("%3d / %02x", msg.data, msg.data);
  return dump;
}

static inline std::string dump_CoreMsg_WIN(const CoreMsg_WIN &msg) {
  std::string dump = "[[MSG_WIN]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  type   :: u8  = " + format("%3d / %02x", msg.type, msg.type);
  return dump;
}

static inline std::string dump_CoreMsg_WAITING(const CoreMsg_WAITING &msg) {
  std::string dump = "[[MSG_WAITING]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_START(const CoreMsg_START &msg) {
  std::string dump = "[[MSG_START]]\n";
  dump += "\n  player_type         :: u8  = " + format("%3d / %02x", msg.player_type, msg.player_type);
  dump += "\n  player0_lp          :: u32 = " + format("%3d / %02x", msg.player0_lp, msg.player0_lp);
  dump += "\n  player1_lp          :: u32 = " + format("%3d / %02x", msg.player1_lp, msg.player1_lp);
  dump += "\n  player0_deck_count  :: u16 = " + format("%3d / %02x", msg.player0_deck_count, msg.player0_deck_count);
  dump += "\n  player0_extra_count :: u16 = " + format("%3d / %02x", msg.player0_extra_count, msg.player0_extra_count);
  dump += "\n  player1_deck_count  :: u16 = " + format("%3d / %02x", msg.player1_deck_count, msg.player1_deck_count);
  dump += "\n  player1_extra_count :: u16 = " + format("%3d / %02x", msg.player1_extra_count, msg.player1_extra_count);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_BATTLECMD(const CoreMsg_SELECT_BATTLECMD &msg) {
  std::string dump = "[[MSG_SELECT_BATTLECMD]]\n";
  dump += "\n  player         :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  candidates1    :: Candidate1[" + format("%zu", msg.candidates1.size()) + "] =";
  for (const auto &it: msg.candidates1) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    description :: u32 = " + format("%3d / %02x", it.description, it.description);
    dump += "\n  }";
  }
  dump += "\n  candidates2    :: Candidate2[" + format("%zu", msg.candidates2.size()) + "] =";
  for (const auto &it: msg.candidates2) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  to_main2_phase :: u8  = " + format("%3d / %02x", msg.to_main2_phase, msg.to_main2_phase);
  dump += "\n  to_end_phase   :: u8  = " + format("%3d / %02x", msg.to_end_phase, msg.to_end_phase);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_IDLECMD(const CoreMsg_SELECT_IDLECMD &msg) {
  std::string dump = "[[MSG_SELECT_IDLECMD]]\n";
  dump += "\n  player                :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  summon_candidates     :: Candidate[" + format("%zu", msg.summon_candidates.size()) + "] =";
  for (const auto &it: msg.summon_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  spsummon_candidates   :: Candidate[" + format("%zu", msg.spsummon_candidates.size()) + "] =";
  for (const auto &it: msg.spsummon_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  reposition_candidates :: Candidate[" + format("%zu", msg.reposition_candidates.size()) + "] =";
  for (const auto &it: msg.reposition_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  mset_candidates       :: Candidate[" + format("%zu", msg.mset_candidates.size()) + "] =";
  for (const auto &it: msg.mset_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  sset_candidates       :: Candidate[" + format("%zu", msg.sset_candidates.size()) + "] =";
  for (const auto &it: msg.sset_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  active_candidates     :: Candidate[" + format("%zu", msg.active_candidates.size()) + "] =";
  for (const auto &it: msg.active_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  dump += "\n  to_battle_phase       :: u8  = " + format("%3d / %02x", msg.to_battle_phase, msg.to_battle_phase);
  dump += "\n  to_end_phase          :: u8  = " + format("%3d / %02x", msg.to_end_phase, msg.to_end_phase);
  dump += "\n  can_shuffle           :: u8  = " + format("%3d / %02x", msg.can_shuffle, msg.can_shuffle);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_EFFECTYN(const CoreMsg_SELECT_EFFECTYN &msg) {
  std::string dump = "[[MSG_SELECT_EFFECTYN]]\n";
  dump += "\n  player     :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  code       :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  _ignore_   :: u8  = " + format("%3d / %02x", msg._ignore_, msg._ignore_);
  dump += "\n  desc       :: u32 = " + format("%3d / %02x", msg.desc, msg.desc);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_YESNO(const CoreMsg_SELECT_YESNO &msg) {
  std::string dump = "[[MSG_SELECT_YESNO]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  desc   :: u32 = " + format("%3d / %02x", msg.desc, msg.desc);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_OPTION(const CoreMsg_SELECT_OPTION &msg) {
  std::string dump = "[[MSG_SELECT_OPTION]]\n";
  dump += "\n  player     :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  candidates :: Candidate[" + format("%zu", msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    option_id :: u8  = " + format("%3d / %02x", it.option_id, it.option_id);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_CARD(const CoreMsg_SELECT_CARD &msg) {
  std::string dump = "[[MSG_SELECT_CARD]]\n";
  dump += "\n  player     :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cancelable :: u8  = " + format("%3d / %02x", msg.cancelable, msg.cancelable);
  dump += "\n  select_min :: u8  = " + format("%3d / %02x", msg.select_min, msg.select_min);
  dump += "\n  select_max :: u8  = " + format("%3d / %02x", msg.select_max, msg.select_max);
  dump += "\n  candidates :: Candidate[" + format("%zu", msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    subsequence :: u8  = " + format("%3d / %02x", it.subsequence, it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_UNSELECT_CARD(const CoreMsg_SELECT_UNSELECT_CARD &msg) {
  std::string dump = "[[MSG_SELECT_UNSELECT_CARD]]\n";
  dump += "\n  player      :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  finishable  :: u8  = " + format("%3d / %02x", msg.finishable, msg.finishable);
  dump += "\n  cancelable  :: u8  = " + format("%3d / %02x", msg.cancelable, msg.cancelable);
  dump += "\n  select_min  :: u8  = " + format("%3d / %02x", msg.select_min, msg.select_min);
  dump += "\n  select_max  :: u8  = " + format("%3d / %02x", msg.select_max, msg.select_max);
  dump += "\n  candidates1 :: Candidate1[" + format("%zu", msg.candidates1.size()) + "] =";
  for (const auto &it: msg.candidates1) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    subsequence :: u8  = " + format("%3d / %02x", it.subsequence, it.subsequence);
    dump += "\n  }";
  }
  dump += "\n  candidates2 :: Candidate2[" + format("%zu", msg.candidates2.size()) + "] =";
  for (const auto &it: msg.candidates2) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    subsequence :: u8  = " + format("%3d / %02x", it.subsequence, it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_CHAIN(const CoreMsg_SELECT_CHAIN &msg) {
  std::string dump = "[[MSG_SELECT_CHAIN]]\n";
  dump += "\n  player     :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  spe_count  :: u8  = " + format("%3d / %02x", msg.spe_count, msg.spe_count);
  dump += "\n  forced     :: u8  = " + format("%3d / %02x", msg.forced, msg.forced);
  dump += "\n  hint0      :: u32 = " + format("%3d / %02x", msg.hint0, msg.hint0);
  dump += "\n  hint1      :: u32 = " + format("%3d / %02x", msg.hint1, msg.hint1);
  dump += "\n  candidates :: Candidate[" + format("%zu", msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    flag        :: u8  = " + format("%3d / %02x", it.flag, it.flag);
    dump += "\n    code        :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    subsequence :: u8  = " + format("%3d / %02x", it.subsequence, it.subsequence);
    dump += "\n    desc        :: u32 = " + format("%3d / %02x", it.desc, it.desc);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_PLACE(const CoreMsg_SELECT_PLACE &msg) {
  std::string dump = "[[MSG_SELECT_PLACE]]\n";
  dump += "\n  player           :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  select_min       :: u8  = " + format("%3d / %02x", msg.select_min, msg.select_min);
  dump += "\n  selectable_field :: u32 = " + format("%3d / %02x", msg.selectable_field, msg.selectable_field);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_DISFIELD(const CoreMsg_SELECT_DISFIELD &msg) {
  std::string dump = "[[MSG_SELECT_DISFIELD]]\n";
  dump += "\n  player           :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  select_min       :: u8  = " + format("%3d / %02x", msg.select_min, msg.select_min);
  dump += "\n  selectable_field :: u32 = " + format("%3d / %02x", msg.selectable_field, msg.selectable_field);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_POSITION(const CoreMsg_SELECT_POSITION &msg) {
  std::string dump = "[[MSG_SELECT_POSITION]]\n";
  dump += "\n  player    :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  code      :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  positions :: u8  = " + format("%3d / %02x", msg.positions, msg.positions);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_TRIBUTE(const CoreMsg_SELECT_TRIBUTE &msg) {
  std::string dump = "[[MSG_SELECT_TRIBUTE]]\n";
  dump += "\n  player     :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cancelable :: u8  = " + format("%3d / %02x", msg.cancelable, msg.cancelable);
  dump += "\n  select_min :: u8  = " + format("%3d / %02x", msg.select_min, msg.select_min);
  dump += "\n  select_max :: u8  = " + format("%3d / %02x", msg.select_max, msg.select_max);
  dump += "\n  candidates :: Candidate[" + format("%zu", msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller      :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location        :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence        :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    operation_param :: u8  = " + format("%3d / %02x", it.operation_param, it.operation_param);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_COUNTER(const CoreMsg_SELECT_COUNTER &msg) {
  std::string dump = "[[MSG_SELECT_COUNTER]]\n";
  dump += "\n  player               :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  select_counter_type  :: u16 = " + format("%3d / %02x", msg.select_counter_type, msg.select_counter_type);
  dump += "\n  select_counter_count :: u16 = " + format("%3d / %02x", msg.select_counter_count, msg.select_counter_count);
  dump += "\n  candidates           :: Candidate[" + format("%zu", msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller      :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location        :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence        :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    operation_param :: u16 = " + format("%3d / %02x", it.operation_param, it.operation_param);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_SUM(const CoreMsg_SELECT_SUM &msg) {
  std::string dump = "[[MSG_SELECT_SUM]]\n";
  dump += "\n  select_mode            :: u8  = " + format("%3d / %02x", msg.select_mode, msg.select_mode);
  dump += "\n  player                 :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  select_sumval          :: u32 = " + format("%3d / %02x", msg.select_sumval, msg.select_sumval);
  dump += "\n  select_min             :: u8  = " + format("%3d / %02x", msg.select_min, msg.select_min);
  dump += "\n  select_max             :: u8  = " + format("%3d / %02x", msg.select_max, msg.select_max);
  dump += "\n  must_select_candidates :: MustSelect[" + format("%zu", msg.must_select_candidates.size()) + "] =";
  for (const auto &it: msg.must_select_candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller      :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location        :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence        :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    operation_param :: u32 = " + format("%3d / %02x", it.operation_param, it.operation_param);
    dump += "\n  }";
  }
  dump += "\n  candidates             :: Candidate[" + format("%zu", msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller      :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location        :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence        :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    operation_param :: u32 = " + format("%3d / %02x", it.operation_param, it.operation_param);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SORT_CARD(const CoreMsg_SORT_CARD &msg) {
  std::string dump = "[[MSG_SORT_CARD]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SORT_CHAIN(const CoreMsg_SORT_CHAIN &msg) {
  std::string dump = "[[MSG_SORT_CHAIN]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CONFIRM_DECKTOP(const CoreMsg_CONFIRM_DECKTOP &msg) {
  std::string dump = "[[MSG_CONFIRM_DECKTOP]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CONFIRM_EXTRATOP(const CoreMsg_CONFIRM_EXTRATOP &msg) {
  std::string dump = "[[MSG_CONFIRM_EXTRATOP]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CONFIRM_CARDS(const CoreMsg_CONFIRM_CARDS &msg) {
  std::string dump = "[[MSG_CONFIRM_CARDS]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n    controller :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location   :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence   :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_DECK(const CoreMsg_SHUFFLE_DECK &msg) {
  std::string dump = "[[MSG_SHUFFLE_DECK]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_REFRESH_DECK(const CoreMsg_REFRESH_DECK &msg) {
  std::string dump = "[[MSG_REFRESH_DECK]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_SWAP_GRAVE_DECK(const CoreMsg_SWAP_GRAVE_DECK &msg) {
  std::string dump = "[[MSG_SWAP_GRAVE_DECK]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_HAND(const CoreMsg_SHUFFLE_HAND &msg) {
  std::string dump = "[[MSG_SHUFFLE_HAND]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count  :: u8  = " + format("%3d / %02x", msg.count, msg.count);
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_EXTRA(const CoreMsg_SHUFFLE_EXTRA &msg) {
  std::string dump = "[[MSG_SHUFFLE_EXTRA]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count  :: u8  = " + format("%3d / %02x", msg.count, msg.count);
  return dump;
}

static inline std::string dump_CoreMsg_REVERSE_DECK(const CoreMsg_REVERSE_DECK &msg) {
  std::string dump = "[[MSG_REVERSE_DECK]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_DECK_TOP(const CoreMsg_DECK_TOP &msg) {
  std::string dump = "[[MSG_DECK_TOP]]\n";
  dump += "\n  player   :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  sequence :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  code     :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  return dump;
}

static inline std::string dump_CoreMsg_NEW_TURN(const CoreMsg_NEW_TURN &msg) {
  std::string dump = "[[MSG_NEW_TURN]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_NEW_PHASE(const CoreMsg_NEW_PHASE &msg) {
  std::string dump = "[[MSG_NEW_PHASE]]\n";
  dump += "\n  phase :: u16 = " + format("%3d / %02x", msg.phase, msg.phase);
  return dump;
}

static inline std::string dump_CoreMsg_MOVE(const CoreMsg_MOVE &msg) {
  std::string dump = "[[MSG_MOVE]]\n";
  dump += "\n  code                :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  previous_controller :: u8  = " + format("%3d / %02x", msg.previous_controller, msg.previous_controller);
  dump += "\n  previous_location   :: u8  = " + format("%3d / %02x", msg.previous_location, msg.previous_location);
  dump += "\n  previous_sequence   :: u8  = " + format("%3d / %02x", msg.previous_sequence, msg.previous_sequence);
  dump += "\n  previous_position   :: u8  = " + format("%3d / %02x", msg.previous_position, msg.previous_position);
  dump += "\n  current_controller  :: u8  = " + format("%3d / %02x", msg.current_controller, msg.current_controller);
  dump += "\n  current_location    :: u8  = " + format("%3d / %02x", msg.current_location, msg.current_location);
  dump += "\n  current_sequence    :: u8  = " + format("%3d / %02x", msg.current_sequence, msg.current_sequence);
  dump += "\n  current_position    :: u8  = " + format("%3d / %02x", msg.current_position, msg.current_position);
  dump += "\n  reason              :: u32 = " + format("%3d / %02x", msg.reason, msg.reason);
  return dump;
}

static inline std::string dump_CoreMsg_POS_CHANGE(const CoreMsg_POS_CHANGE &msg) {
  std::string dump = "[[MSG_POS_CHANGE]]\n";
  dump += "\n  code               :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  current_controller :: u8  = " + format("%3d / %02x", msg.current_controller, msg.current_controller);
  dump += "\n  current_location   :: u8  = " + format("%3d / %02x", msg.current_location, msg.current_location);
  dump += "\n  current_sequence   :: u8  = " + format("%3d / %02x", msg.current_sequence, msg.current_sequence);
  dump += "\n  previous_position  :: u8  = " + format("%3d / %02x", msg.previous_position, msg.previous_position);
  dump += "\n  current_position   :: u8  = " + format("%3d / %02x", msg.current_position, msg.current_position);
  return dump;
}

static inline std::string dump_CoreMsg_SET(const CoreMsg_SET &msg) {
  std::string dump = "[[MSG_SET]]\n";
  dump += "\n  code               :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  current_controller :: u8  = " + format("%3d / %02x", msg.current_controller, msg.current_controller);
  dump += "\n  current_location   :: u8  = " + format("%3d / %02x", msg.current_location, msg.current_location);
  dump += "\n  current_sequence   :: u8  = " + format("%3d / %02x", msg.current_sequence, msg.current_sequence);
  dump += "\n  current_position   :: u8  = " + format("%3d / %02x", msg.current_position, msg.current_position);
  return dump;
}

static inline std::string dump_CoreMsg_SWAP(const CoreMsg_SWAP &msg) {
  std::string dump = "[[MSG_SWAP]]\n";
  dump += "\n  code1       :: u32 = " + format("%3d / %02x", msg.code1, msg.code1);
  dump += "\n  controller1 :: u8  = " + format("%3d / %02x", msg.controller1, msg.controller1);
  dump += "\n  location1   :: u8  = " + format("%3d / %02x", msg.location1, msg.location1);
  dump += "\n  sequence1   :: u8  = " + format("%3d / %02x", msg.sequence1, msg.sequence1);
  dump += "\n  position1   :: u8  = " + format("%3d / %02x", msg.position1, msg.position1);
  dump += "\n  code2       :: u32 = " + format("%3d / %02x", msg.code2, msg.code2);
  dump += "\n  controller2 :: u8  = " + format("%3d / %02x", msg.controller2, msg.controller2);
  dump += "\n  location2   :: u8  = " + format("%3d / %02x", msg.location2, msg.location2);
  dump += "\n  sequence2   :: u8  = " + format("%3d / %02x", msg.sequence2, msg.sequence2);
  dump += "\n  position2   :: u8  = " + format("%3d / %02x", msg.position2, msg.position2);
  return dump;
}

static inline std::string dump_CoreMsg_FIELD_DISABLED(const CoreMsg_FIELD_DISABLED &msg) {
  std::string dump = "[[MSG_FIELD_DISABLED]]\n";
  dump += "\n  disabled_fields :: u32 = " + format("%3d / %02x", msg.disabled_fields, msg.disabled_fields);
  return dump;
}

static inline std::string dump_CoreMsg_SUMMONING(const CoreMsg_SUMMONING &msg) {
  std::string dump = "[[MSG_SUMMONING]]\n";
  dump += "\n  code       :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  position   :: u8  = " + format("%3d / %02x", msg.position, msg.position);
  return dump;
}

static inline std::string dump_CoreMsg_SUMMONED(const CoreMsg_SUMMONED &msg) {
  std::string dump = "[[MSG_SUMMONED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_SPSUMMONING(const CoreMsg_SPSUMMONING &msg) {
  std::string dump = "[[MSG_SPSUMMONING]]\n";
  dump += "\n  code       :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  position   :: u8  = " + format("%3d / %02x", msg.position, msg.position);
  return dump;
}

static inline std::string dump_CoreMsg_SPSUMMONED(const CoreMsg_SPSUMMONED &msg) {
  std::string dump = "[[MSG_SPSUMMONED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_FLIPSUMMONING(const CoreMsg_FLIPSUMMONING &msg) {
  std::string dump = "[[MSG_FLIPSUMMONING]]\n";
  dump += "\n  code       :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  position   :: u8  = " + format("%3d / %02x", msg.position, msg.position);
  return dump;
}

static inline std::string dump_CoreMsg_FLIPSUMMONED(const CoreMsg_FLIPSUMMONED &msg) {
  std::string dump = "[[MSG_FLIPSUMMONED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_CHAINING(const CoreMsg_CHAINING &msg) {
  std::string dump = "[[MSG_CHAINING]]\n";
  dump += "\n  code                      :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  dump += "\n  previous_chain_controller :: u8  = " + format("%3d / %02x", msg.previous_chain_controller, msg.previous_chain_controller);
  dump += "\n  previous_chain_location   :: u8  = " + format("%3d / %02x", msg.previous_chain_location, msg.previous_chain_location);
  dump += "\n  previous_chain_sequence   :: u8  = " + format("%3d / %02x", msg.previous_chain_sequence, msg.previous_chain_sequence);
  dump += "\n  subsequence               :: u8  = " + format("%3d / %02x", msg.subsequence, msg.subsequence);
  dump += "\n  chain_controller          :: u8  = " + format("%3d / %02x", msg.chain_controller, msg.chain_controller);
  dump += "\n  chain_location            :: u8  = " + format("%3d / %02x", msg.chain_location, msg.chain_location);
  dump += "\n  chain_sequence            :: u8  = " + format("%3d / %02x", msg.chain_sequence, msg.chain_sequence);
  dump += "\n  desc                      :: u32 = " + format("%3d / %02x", msg.desc, msg.desc);
  dump += "\n  chain_param               :: u8  = " + format("%3d / %02x", msg.chain_param, msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAINED(const CoreMsg_CHAINED &msg) {
  std::string dump = "[[MSG_CHAINED]]\n";
  dump += "\n  chain_param :: u8  = " + format("%3d / %02x", msg.chain_param, msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_SOLVING(const CoreMsg_CHAIN_SOLVING &msg) {
  std::string dump = "[[MSG_CHAIN_SOLVING]]\n";
  dump += "\n  chain_param :: u8  = " + format("%3d / %02x", msg.chain_param, msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_SOLVED(const CoreMsg_CHAIN_SOLVED &msg) {
  std::string dump = "[[MSG_CHAIN_SOLVED]]\n";
  dump += "\n  chain_param :: u8  = " + format("%3d / %02x", msg.chain_param, msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_END(const CoreMsg_CHAIN_END &msg) {
  std::string dump = "[[MSG_CHAIN_END]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_NEGATED(const CoreMsg_CHAIN_NEGATED &msg) {
  std::string dump = "[[MSG_CHAIN_NEGATED]]\n";
  dump += "\n  chain_param :: u8  = " + format("%3d / %02x", msg.chain_param, msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_DISABLED(const CoreMsg_CHAIN_DISABLED &msg) {
  std::string dump = "[[MSG_CHAIN_DISABLED]]\n";
  dump += "\n  chain_param :: u8  = " + format("%3d / %02x", msg.chain_param, msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CARD_SELECTED(const CoreMsg_CARD_SELECTED &msg) {
  std::string dump = "[[MSG_CARD_SELECTED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_RANDOM_SELECTED(const CoreMsg_RANDOM_SELECTED &msg) {
  std::string dump = "[[MSG_RANDOM_SELECTED]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    subsequence :: u8  = " + format("%3d / %02x", it.subsequence, it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_BECOME_TARGET(const CoreMsg_BECOME_TARGET &msg) {
  std::string dump = "[[MSG_BECOME_TARGET]]\n";
  dump += "\n  cards :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    controller  :: u8  = " + format("%3d / %02x", it.controller, it.controller);
    dump += "\n    location    :: u8  = " + format("%3d / %02x", it.location, it.location);
    dump += "\n    sequence    :: u8  = " + format("%3d / %02x", it.sequence, it.sequence);
    dump += "\n    subsequence :: u8  = " + format("%3d / %02x", it.subsequence, it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_DRAW(const CoreMsg_DRAW &msg) {
  std::string dump = "[[MSG_DRAW]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  cards  :: Card[" + format("%zu", msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code :: u32 = " + format("%3d / %02x", it.code, it.code);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_DAMAGE(const CoreMsg_DAMAGE &msg) {
  std::string dump = "[[MSG_DAMAGE]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  value  :: u32 = " + format("%3d / %02x", msg.value, msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_RECOVER(const CoreMsg_RECOVER &msg) {
  std::string dump = "[[MSG_RECOVER]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  value  :: u32 = " + format("%3d / %02x", msg.value, msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_LPUPDATE(const CoreMsg_LPUPDATE &msg) {
  std::string dump = "[[MSG_LPUPDATE]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  value  :: u32 = " + format("%3d / %02x", msg.value, msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_PAY_LPCOST(const CoreMsg_PAY_LPCOST &msg) {
  std::string dump = "[[MSG_PAY_LPCOST]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  value  :: u32 = " + format("%3d / %02x", msg.value, msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_EQUIP(const CoreMsg_EQUIP &msg) {
  std::string dump = "[[MSG_EQUIP]]\n";
  dump += "\n  controller1 :: u8  = " + format("%3d / %02x", msg.controller1, msg.controller1);
  dump += "\n  location1   :: u8  = " + format("%3d / %02x", msg.location1, msg.location1);
  dump += "\n  sequence1   :: u8  = " + format("%3d / %02x", msg.sequence1, msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format("%3d / %02x", msg.ignore1, msg.ignore1);
  dump += "\n  controller2 :: u8  = " + format("%3d / %02x", msg.controller2, msg.controller2);
  dump += "\n  location2   :: u8  = " + format("%3d / %02x", msg.location2, msg.location2);
  dump += "\n  sequence2   :: u8  = " + format("%3d / %02x", msg.sequence2, msg.sequence2);
  dump += "\n  ignore2     :: u8  = " + format("%3d / %02x", msg.ignore2, msg.ignore2);
  return dump;
}

static inline std::string dump_CoreMsg_UNEQUIP(const CoreMsg_UNEQUIP &msg) {
  std::string dump = "[[MSG_UNEQUIP]]\n";
  dump += "\n  controller1 :: u8  = " + format("%3d / %02x", msg.controller1, msg.controller1);
  dump += "\n  location1   :: u8  = " + format("%3d / %02x", msg.location1, msg.location1);
  dump += "\n  sequence1   :: u8  = " + format("%3d / %02x", msg.sequence1, msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format("%3d / %02x", msg.ignore1, msg.ignore1);
  return dump;
}

static inline std::string dump_CoreMsg_CARD_TARGET(const CoreMsg_CARD_TARGET &msg) {
  std::string dump = "[[MSG_CARD_TARGET]]\n";
  dump += "\n  controller1 :: u8  = " + format("%3d / %02x", msg.controller1, msg.controller1);
  dump += "\n  location1   :: u8  = " + format("%3d / %02x", msg.location1, msg.location1);
  dump += "\n  sequence1   :: u8  = " + format("%3d / %02x", msg.sequence1, msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format("%3d / %02x", msg.ignore1, msg.ignore1);
  dump += "\n  controller2 :: u8  = " + format("%3d / %02x", msg.controller2, msg.controller2);
  dump += "\n  location2   :: u8  = " + format("%3d / %02x", msg.location2, msg.location2);
  dump += "\n  sequence2   :: u8  = " + format("%3d / %02x", msg.sequence2, msg.sequence2);
  dump += "\n  ignore2     :: u8  = " + format("%3d / %02x", msg.ignore2, msg.ignore2);
  return dump;
}

static inline std::string dump_CoreMsg_CANCEL_TARGET(const CoreMsg_CANCEL_TARGET &msg) {
  std::string dump = "[[MSG_CANCEL_TARGET]]\n";
  dump += "\n  controller1 :: u8  = " + format("%3d / %02x", msg.controller1, msg.controller1);
  dump += "\n  location1   :: u8  = " + format("%3d / %02x", msg.location1, msg.location1);
  dump += "\n  sequence1   :: u8  = " + format("%3d / %02x", msg.sequence1, msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format("%3d / %02x", msg.ignore1, msg.ignore1);
  dump += "\n  controller2 :: u8  = " + format("%3d / %02x", msg.controller2, msg.controller2);
  dump += "\n  location2   :: u8  = " + format("%3d / %02x", msg.location2, msg.location2);
  dump += "\n  sequence2   :: u8  = " + format("%3d / %02x", msg.sequence2, msg.sequence2);
  dump += "\n  ignore2     :: u8  = " + format("%3d / %02x", msg.ignore2, msg.ignore2);
  return dump;
}

static inline std::string dump_CoreMsg_ADD_COUNTER(const CoreMsg_ADD_COUNTER &msg) {
  std::string dump = "[[MSG_ADD_COUNTER]]\n";
  dump += "\n  type       :: u16 = " + format("%3d / %02x", msg.type, msg.type);
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  count      :: u16 = " + format("%3d / %02x", msg.count, msg.count);
  return dump;
}

static inline std::string dump_CoreMsg_REMOVE_COUNTER(const CoreMsg_REMOVE_COUNTER &msg) {
  std::string dump = "[[MSG_REMOVE_COUNTER]]\n";
  dump += "\n  type       :: u16 = " + format("%3d / %02x", msg.type, msg.type);
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  count      :: u16 = " + format("%3d / %02x", msg.count, msg.count);
  return dump;
}

static inline std::string dump_CoreMsg_ATTACK(const CoreMsg_ATTACK &msg) {
  std::string dump = "[[MSG_ATTACK]]\n";
  dump += "\n  atk_controller :: u8  = " + format("%3d / %02x", msg.atk_controller, msg.atk_controller);
  dump += "\n  atk_location   :: u8  = " + format("%3d / %02x", msg.atk_location, msg.atk_location);
  dump += "\n  atk_sequence   :: u8  = " + format("%3d / %02x", msg.atk_sequence, msg.atk_sequence);
  dump += "\n  atk_ignore     :: u8  = " + format("%3d / %02x", msg.atk_ignore, msg.atk_ignore);
  dump += "\n  def_controller :: u8  = " + format("%3d / %02x", msg.def_controller, msg.def_controller);
  dump += "\n  def_location   :: u8  = " + format("%3d / %02x", msg.def_location, msg.def_location);
  dump += "\n  def_sequence   :: u8  = " + format("%3d / %02x", msg.def_sequence, msg.def_sequence);
  dump += "\n  def_ignore     :: u8  = " + format("%3d / %02x", msg.def_ignore, msg.def_ignore);
  return dump;
}

static inline std::string dump_CoreMsg_BATTLE(const CoreMsg_BATTLE &msg) {
  std::string dump = "[[MSG_BATTLE]]\n";
  dump += "\n  atk_controller :: u8  = " + format("%3d / %02x", msg.atk_controller, msg.atk_controller);
  dump += "\n  atk_location   :: u8  = " + format("%3d / %02x", msg.atk_location, msg.atk_location);
  dump += "\n  atk_sequence   :: u8  = " + format("%3d / %02x", msg.atk_sequence, msg.atk_sequence);
  dump += "\n  atk_atkvalue   :: u32 = " + format("%3d / %02x", msg.atk_atkvalue, msg.atk_atkvalue);
  dump += "\n  atk_defvalue   :: u32 = " + format("%3d / %02x", msg.atk_defvalue, msg.atk_defvalue);
  dump += "\n  atk_ignore     :: u8  = " + format("%3d / %02x", msg.atk_ignore, msg.atk_ignore);
  dump += "\n  def_controller :: u8  = " + format("%3d / %02x", msg.def_controller, msg.def_controller);
  dump += "\n  def_location   :: u8  = " + format("%3d / %02x", msg.def_location, msg.def_location);
  dump += "\n  def_sequence   :: u8  = " + format("%3d / %02x", msg.def_sequence, msg.def_sequence);
  dump += "\n  def_atkvalue   :: u32 = " + format("%3d / %02x", msg.def_atkvalue, msg.def_atkvalue);
  dump += "\n  def_defvalue   :: u32 = " + format("%3d / %02x", msg.def_defvalue, msg.def_defvalue);
  dump += "\n  def_ignore     :: u8  = " + format("%3d / %02x", msg.def_ignore, msg.def_ignore);
  return dump;
}

static inline std::string dump_CoreMsg_ATTACK_DISABLED(const CoreMsg_ATTACK_DISABLED &msg) {
  std::string dump = "[[MSG_ATTACK_DISABLED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_DAMAGE_STEP_START(const CoreMsg_DAMAGE_STEP_START &msg) {
  std::string dump = "[[MSG_DAMAGE_STEP_START]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_DAMAGE_STEP_END(const CoreMsg_DAMAGE_STEP_END &msg) {
  std::string dump = "[[MSG_DAMAGE_STEP_END]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_MISSED_EFFECT(const CoreMsg_MISSED_EFFECT &msg) {
  std::string dump = "[[MSG_MISSED_EFFECT]]\n";
  dump += "\n  ignore :: u32 = " + format("%3d / %02x", msg.ignore, msg.ignore);
  dump += "\n  code   :: u32 = " + format("%3d / %02x", msg.code, msg.code);
  return dump;
}

static inline std::string dump_CoreMsg_TOSS_COIN(const CoreMsg_TOSS_COIN &msg) {
  std::string dump = "[[MSG_TOSS_COIN]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count  :: Result[" + format("%zu", msg.count.size()) + "] =";
  for (const auto &it: msg.count) {
    dump += "\n  {";
    dump += "\n    value :: u8  = " + format("%3d / %02x", it.value, it.value);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_TOSS_DICE(const CoreMsg_TOSS_DICE &msg) {
  std::string dump = "[[MSG_TOSS_DICE]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count  :: Result[" + format("%zu", msg.count.size()) + "] =";
  for (const auto &it: msg.count) {
    dump += "\n  {";
    dump += "\n    value :: u8  = " + format("%3d / %02x", it.value, it.value);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_ROCK_PAPER_SCISSORS(const CoreMsg_ROCK_PAPER_SCISSORS &msg) {
  std::string dump = "[[MSG_ROCK_PAPER_SCISSORS]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_HAND_RES(const CoreMsg_HAND_RES &msg) {
  std::string dump = "[[MSG_HAND_RES]]\n";
  dump += "\n  res :: u8  = " + format("%3d / %02x", msg.res, msg.res);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_RACE(const CoreMsg_ANNOUNCE_RACE &msg) {
  std::string dump = "[[MSG_ANNOUNCE_RACE]]\n";
  dump += "\n  player    :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count     :: u8  = " + format("%3d / %02x", msg.count, msg.count);
  dump += "\n  available :: u32 = " + format("%3d / %02x", msg.available, msg.available);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_ATTRIB(const CoreMsg_ANNOUNCE_ATTRIB &msg) {
  std::string dump = "[[MSG_ANNOUNCE_ATTRIB]]\n";
  dump += "\n  player    :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count     :: u8  = " + format("%3d / %02x", msg.count, msg.count);
  dump += "\n  available :: u32 = " + format("%3d / %02x", msg.available, msg.available);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_CARD(const CoreMsg_ANNOUNCE_CARD &msg) {
  std::string dump = "[[MSG_ANNOUNCE_CARD]]\n";
  dump += "\n  player          :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  declarable_type :: u32 = " + format("%3d / %02x", msg.declarable_type, msg.declarable_type);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_NUMBER(const CoreMsg_ANNOUNCE_NUMBER &msg) {
  std::string dump = "[[MSG_ANNOUNCE_NUMBER]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  count  :: Announce[" + format("%zu", msg.count.size()) + "] =";
  for (const auto &it: msg.count) {
    dump += "\n  {";
    dump += "\n    value :: u32 = " + format("%3d / %02x", it.value, it.value);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_CARD_FILTER(const CoreMsg_ANNOUNCE_CARD_FILTER &msg) {
  std::string dump = "[[MSG_ANNOUNCE_CARD_FILTER]]\n";
  dump += "\n  player  :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  filters :: Filter[" + format("%zu", msg.filters.size()) + "] =";
  for (const auto &it: msg.filters) {
    dump += "\n  {";
    dump += "\n    opcode :: u32 = " + format("%3d / %02x", it.opcode, it.opcode);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CARD_HINT(const CoreMsg_CARD_HINT &msg) {
  std::string dump = "[[MSG_CARD_HINT]]\n";
  dump += "\n  controller :: u8  = " + format("%3d / %02x", msg.controller, msg.controller);
  dump += "\n  location   :: u8  = " + format("%3d / %02x", msg.location, msg.location);
  dump += "\n  sequence   :: u8  = " + format("%3d / %02x", msg.sequence, msg.sequence);
  dump += "\n  ignore     :: u8  = " + format("%3d / %02x", msg.ignore, msg.ignore);
  dump += "\n  chtype     :: u8  = " + format("%3d / %02x", msg.chtype, msg.chtype);
  dump += "\n  value      :: u32 = " + format("%3d / %02x", msg.value, msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_PLAYER_HINT(const CoreMsg_PLAYER_HINT &msg) {
  std::string dump = "[[MSG_PLAYER_HINT]]\n";
  dump += "\n  player :: u8  = " + format("%3d / %02x", msg.player, msg.player);
  dump += "\n  chtype :: u8  = " + format("%3d / %02x", msg.chtype, msg.chtype);
  dump += "\n  value  :: u32 = " + format("%3d / %02x", msg.value, msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_MATCH_KILL(const CoreMsg_MATCH_KILL &msg) {
  std::string dump = "[[MSG_MATCH_KILL]]\n";
  dump += "\n  match_kill :: u32 = " + format("%3d / %02x", msg.match_kill, msg.match_kill);
  return dump;
}

static inline std::string dump_CoreMsg_RELOAD_FIELD(const CoreMsg_RELOAD_FIELD &msg) {
  std::string dump = "[[MSG_RELOAD_FIELD]]\n";
  dump += "\n  duel_rule :: u8  = " + format("%3d / %02x", msg.duel_rule, msg.duel_rule);
  dump += "\n  players   :: PlayersField[4] =";
  for (unsigned i = 0; i != 4; ++i) {
    dump += "\n  {";
    dump += "\n    lp                :: u32 = " + format("%3d / %02x", msg.players[i].lp, msg.players[i].lp);
    dump += "\n    mzone_cards       :: MCard[7] =";
    for (unsigned i = 0; i != 7; ++i) {
      dump += "\n    {";
      dump += "\n      value :: MValue(" + format("%s", msg.players[i].mzone_cards[i].value ? "Yes" : "No") + ") =";
      if (msg.players[i].mzone_cards[i].value) {
        dump += "\n      {";
        dump += "\n        position  :: u8  = " + format("%3d / %02x", (*(msg.players[i].mzone_cards[i].value)).position, (*(msg.players[i].mzone_cards[i].value)).position);
        dump += "\n        xyz_count :: u8  = " + format("%3d / %02x", (*(msg.players[i].mzone_cards[i].value)).xyz_count, (*(msg.players[i].mzone_cards[i].value)).xyz_count);
        dump += "\n      }";
      }
      dump += "\n    }";
    }
    dump += "\n    cards             :: Card[8] =";
    for (unsigned i = 0; i != 8; ++i) {
      dump += "\n    {";
      dump += "\n      value :: Value(" + format("%s", msg.players[i].cards[i].value ? "Yes" : "No") + ") =";
      if (msg.players[i].cards[i].value) {
        dump += "\n      {";
        dump += "\n        position :: u8  = " + format("%3d / %02x", (*(msg.players[i].cards[i].value)).position, (*(msg.players[i].cards[i].value)).position);
        dump += "\n      }";
      }
      dump += "\n    }";
    }
    dump += "\n    deck_count        :: u8  = " + format("%3d / %02x", msg.players[i].deck_count, msg.players[i].deck_count);
    dump += "\n    hand_count        :: u8  = " + format("%3d / %02x", msg.players[i].hand_count, msg.players[i].hand_count);
    dump += "\n    grave_count       :: u8  = " + format("%3d / %02x", msg.players[i].grave_count, msg.players[i].grave_count);
    dump += "\n    banish_count      :: u8  = " + format("%3d / %02x", msg.players[i].banish_count, msg.players[i].banish_count);
    dump += "\n    extra_count       :: u8  = " + format("%3d / %02x", msg.players[i].extra_count, msg.players[i].extra_count);
    dump += "\n    extra_pendu_count :: u8  = " + format("%3d / %02x", msg.players[i].extra_pendu_count, msg.players[i].extra_pendu_count);
    dump += "\n    chains            :: Chain[" + format("%zu", msg.players[i].chains.size()) + "] =";
    for (const auto &it: msg.players[i].chains) {
      dump += "\n    {";
      dump += "\n      code                 :: u32 = " + format("%3d / %02x", it.code, it.code);
      dump += "\n      previous_controller  :: u8  = " + format("%3d / %02x", it.previous_controller, it.previous_controller);
      dump += "\n      previous_location    :: u8  = " + format("%3d / %02x", it.previous_location, it.previous_location);
      dump += "\n      previous_sequence    :: u8  = " + format("%3d / %02x", it.previous_sequence, it.previous_sequence);
      dump += "\n      previous_subsequence :: u8  = " + format("%3d / %02x", it.previous_subsequence, it.previous_subsequence);
      dump += "\n      current_controller   :: u8  = " + format("%3d / %02x", it.current_controller, it.current_controller);
      dump += "\n      current_location     :: u8  = " + format("%3d / %02x", it.current_location, it.current_location);
      dump += "\n      current_sequence     :: u8  = " + format("%3d / %02x", it.current_sequence, it.current_sequence);
      dump += "\n      desc                 :: u32 = " + format("%3d / %02x", it.desc, it.desc);
      dump += "\n    }";
    }
    dump += "\n  }";
  }
  return dump;
}

