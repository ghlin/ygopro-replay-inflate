/* !!! Generated code, DO NOT EDIT !!! */

static inline std::string dump_CoreMsg_RETRY(const CoreMsg_RETRY &msg) {
  (void)msg;
  std::string dump = "[[MSG_RETRY]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_HINT(const CoreMsg_HINT &msg) {
  (void)msg;
  std::string dump = "[[MSG_HINT]]\n";
  dump += "\n  type   :: u8  = " + format_value(msg.type);
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  data   :: u32 = " + format_value(msg.data);
  return dump;
}

static inline std::string dump_CoreMsg_WIN(const CoreMsg_WIN &msg) {
  (void)msg;
  std::string dump = "[[MSG_WIN]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  type   :: u8  = " + format_value(msg.type);
  return dump;
}

static inline std::string dump_CoreMsg_WAITING(const CoreMsg_WAITING &msg) {
  (void)msg;
  std::string dump = "[[MSG_WAITING]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_START(const CoreMsg_START &msg) {
  (void)msg;
  std::string dump = "[[MSG_START]]\n";
  dump += "\n  player_type         :: u8  = " + format_value(msg.player_type);
  dump += "\n  player0_lp          :: u32 = " + format_value(msg.player0_lp);
  dump += "\n  player1_lp          :: u32 = " + format_value(msg.player1_lp);
  dump += "\n  player0_deck_count  :: u16 = " + format_value(msg.player0_deck_count);
  dump += "\n  player0_extra_count :: u16 = " + format_value(msg.player0_extra_count);
  dump += "\n  player1_deck_count  :: u16 = " + format_value(msg.player1_deck_count);
  dump += "\n  player1_extra_count :: u16 = " + format_value(msg.player1_extra_count);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_BATTLECMD(const CoreMsg_SELECT_BATTLECMD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_BATTLECMD]]\n";
  dump += "\n  player         :: u8  = " + format_value(msg.player);
  dump += "\n  candidates1    :: Candidate1[" + std::to_string(msg.candidates1.size()) + "] =";
  for (const auto &it: msg.candidates1) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format_value(it.code);
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    description :: u32 = " + format_value(it.description);
    dump += "\n  }";
  }
  dump += "\n  candidates2    :: Candidate2[" + std::to_string(msg.candidates2.size()) + "] =";
  for (const auto &it: msg.candidates2) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format_value(it.code);
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n  }";
  }
  dump += "\n  to_main2_phase :: u8  = " + format_value(msg.to_main2_phase);
  dump += "\n  to_end_phase   :: u8  = " + format_value(msg.to_end_phase);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_IDLECMD(const CoreMsg_SELECT_IDLECMD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_IDLECMD]]\n";
  dump += "\n  player                :: u8  = " + format_value(msg.player);
  dump += "\n  summon_candidates     :: Candidate[" + std::to_string(msg.summon_candidates.size()) + "] =";
  for (const auto &it: msg.summon_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  dump += "\n  spsummon_candidates   :: Candidate[" + std::to_string(msg.spsummon_candidates.size()) + "] =";
  for (const auto &it: msg.spsummon_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  dump += "\n  reposition_candidates :: Candidate[" + std::to_string(msg.reposition_candidates.size()) + "] =";
  for (const auto &it: msg.reposition_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  dump += "\n  mset_candidates       :: Candidate[" + std::to_string(msg.mset_candidates.size()) + "] =";
  for (const auto &it: msg.mset_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  dump += "\n  sset_candidates       :: Candidate[" + std::to_string(msg.sset_candidates.size()) + "] =";
  for (const auto &it: msg.sset_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  dump += "\n  active_candidates     :: ActiveCandidate[" + std::to_string(msg.active_candidates.size()) + "] =";
  for (const auto &it: msg.active_candidates) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n    desc       :: u32 = " + format_value(it.desc);
    dump += "\n  }";
  }
  dump += "\n  to_battle_phase       :: u8  = " + format_value(msg.to_battle_phase);
  dump += "\n  to_end_phase          :: u8  = " + format_value(msg.to_end_phase);
  dump += "\n  can_shuffle           :: u8  = " + format_value(msg.can_shuffle);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_EFFECTYN(const CoreMsg_SELECT_EFFECTYN &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_EFFECTYN]]\n";
  dump += "\n  player     :: u8  = " + format_value(msg.player);
  dump += "\n  code       :: u32 = " + format_value(msg.code);
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  _ignore_   :: u8  = " + format_value(msg._ignore_);
  dump += "\n  desc       :: u32 = " + format_value(msg.desc);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_YESNO(const CoreMsg_SELECT_YESNO &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_YESNO]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  desc   :: u32 = " + format_value(msg.desc);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_OPTION(const CoreMsg_SELECT_OPTION &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_OPTION]]\n";
  dump += "\n  player     :: u8  = " + format_value(msg.player);
  dump += "\n  candidates :: Candidate[" + std::to_string(msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    option_id :: u8  = " + format_value(it.option_id);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_CARD(const CoreMsg_SELECT_CARD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_CARD]]\n";
  dump += "\n  player     :: u8  = " + format_value(msg.player);
  dump += "\n  cancelable :: u8  = " + format_value(msg.cancelable);
  dump += "\n  select_min :: u8  = " + format_value(msg.select_min);
  dump += "\n  select_max :: u8  = " + format_value(msg.select_max);
  dump += "\n  candidates :: Candidate[" + std::to_string(msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format_value(it.code);
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_UNSELECT_CARD(const CoreMsg_SELECT_UNSELECT_CARD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_UNSELECT_CARD]]\n";
  dump += "\n  player      :: u8  = " + format_value(msg.player);
  dump += "\n  finishable  :: u8  = " + format_value(msg.finishable);
  dump += "\n  cancelable  :: u8  = " + format_value(msg.cancelable);
  dump += "\n  select_min  :: u8  = " + format_value(msg.select_min);
  dump += "\n  select_max  :: u8  = " + format_value(msg.select_max);
  dump += "\n  candidates1 :: Candidate1[" + std::to_string(msg.candidates1.size()) + "] =";
  for (const auto &it: msg.candidates1) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format_value(it.code);
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n  }";
  }
  dump += "\n  candidates2 :: Candidate2[" + std::to_string(msg.candidates2.size()) + "] =";
  for (const auto &it: msg.candidates2) {
    dump += "\n  {";
    dump += "\n    code        :: u32 = " + format_value(it.code);
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_CHAIN(const CoreMsg_SELECT_CHAIN &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_CHAIN]]\n";
  dump += "\n  player     :: u8  = " + format_value(msg.player);
  dump += "\n  spe_count  :: u8  = " + format_value(msg.spe_count);
  dump += "\n  forced     :: u8  = " + format_value(msg.forced);
  dump += "\n  hint0      :: u32 = " + format_value(msg.hint0);
  dump += "\n  hint1      :: u32 = " + format_value(msg.hint1);
  dump += "\n  candidates :: Candidate[" + std::to_string(msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    flag        :: u8  = " + format_value(it.flag);
    dump += "\n    code        :: u32 = " + format_value(it.code);
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n    desc        :: u32 = " + format_value(it.desc);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_PLACE(const CoreMsg_SELECT_PLACE &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_PLACE]]\n";
  dump += "\n  player           :: u8  = " + format_value(msg.player);
  dump += "\n  select_min       :: u8  = " + format_value(msg.select_min);
  dump += "\n  selectable_field :: u32 = " + format_value(msg.selectable_field);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_DISFIELD(const CoreMsg_SELECT_DISFIELD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_DISFIELD]]\n";
  dump += "\n  player           :: u8  = " + format_value(msg.player);
  dump += "\n  select_min       :: u8  = " + format_value(msg.select_min);
  dump += "\n  selectable_field :: u32 = " + format_value(msg.selectable_field);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_POSITION(const CoreMsg_SELECT_POSITION &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_POSITION]]\n";
  dump += "\n  player    :: u8  = " + format_value(msg.player);
  dump += "\n  code      :: u32 = " + format_value(msg.code);
  dump += "\n  positions :: u8  = " + format_value(msg.positions);
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_TRIBUTE(const CoreMsg_SELECT_TRIBUTE &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_TRIBUTE]]\n";
  dump += "\n  player     :: u8  = " + format_value(msg.player);
  dump += "\n  cancelable :: u8  = " + format_value(msg.cancelable);
  dump += "\n  select_min :: u8  = " + format_value(msg.select_min);
  dump += "\n  select_max :: u8  = " + format_value(msg.select_max);
  dump += "\n  candidates :: Candidate[" + std::to_string(msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format_value(it.code);
    dump += "\n    controller      :: u8  = " + format_value(it.controller);
    dump += "\n    location        :: u8  = " + format_value(it.location);
    dump += "\n    sequence        :: u8  = " + format_value(it.sequence);
    dump += "\n    operation_param :: u8  = " + format_value(it.operation_param);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_COUNTER(const CoreMsg_SELECT_COUNTER &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_COUNTER]]\n";
  dump += "\n  player               :: u8  = " + format_value(msg.player);
  dump += "\n  select_counter_type  :: u16 = " + format_value(msg.select_counter_type);
  dump += "\n  select_counter_count :: u16 = " + format_value(msg.select_counter_count);
  dump += "\n  candidates           :: Candidate[" + std::to_string(msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format_value(it.code);
    dump += "\n    controller      :: u8  = " + format_value(it.controller);
    dump += "\n    location        :: u8  = " + format_value(it.location);
    dump += "\n    sequence        :: u8  = " + format_value(it.sequence);
    dump += "\n    operation_param :: u16 = " + format_value(it.operation_param);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SELECT_SUM(const CoreMsg_SELECT_SUM &msg) {
  (void)msg;
  std::string dump = "[[MSG_SELECT_SUM]]\n";
  dump += "\n  select_mode            :: u8  = " + format_value(msg.select_mode);
  dump += "\n  player                 :: u8  = " + format_value(msg.player);
  dump += "\n  select_sumval          :: u32 = " + format_value(msg.select_sumval);
  dump += "\n  select_min             :: u8  = " + format_value(msg.select_min);
  dump += "\n  select_max             :: u8  = " + format_value(msg.select_max);
  dump += "\n  must_select_candidates :: MustSelect[" + std::to_string(msg.must_select_candidates.size()) + "] =";
  for (const auto &it: msg.must_select_candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format_value(it.code);
    dump += "\n    controller      :: u8  = " + format_value(it.controller);
    dump += "\n    location        :: u8  = " + format_value(it.location);
    dump += "\n    sequence        :: u8  = " + format_value(it.sequence);
    dump += "\n    operation_param :: u32 = " + format_value(it.operation_param);
    dump += "\n  }";
  }
  dump += "\n  candidates             :: Candidate[" + std::to_string(msg.candidates.size()) + "] =";
  for (const auto &it: msg.candidates) {
    dump += "\n  {";
    dump += "\n    code            :: u32 = " + format_value(it.code);
    dump += "\n    controller      :: u8  = " + format_value(it.controller);
    dump += "\n    location        :: u8  = " + format_value(it.location);
    dump += "\n    sequence        :: u8  = " + format_value(it.sequence);
    dump += "\n    operation_param :: u32 = " + format_value(it.operation_param);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SORT_CARD(const CoreMsg_SORT_CARD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SORT_CARD]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SORT_CHAIN(const CoreMsg_SORT_CHAIN &msg) {
  (void)msg;
  std::string dump = "[[MSG_SORT_CHAIN]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CONFIRM_DECKTOP(const CoreMsg_CONFIRM_DECKTOP &msg) {
  (void)msg;
  std::string dump = "[[MSG_CONFIRM_DECKTOP]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CONFIRM_EXTRATOP(const CoreMsg_CONFIRM_EXTRATOP &msg) {
  (void)msg;
  std::string dump = "[[MSG_CONFIRM_EXTRATOP]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CONFIRM_CARDS(const CoreMsg_CONFIRM_CARDS &msg) {
  (void)msg;
  std::string dump = "[[MSG_CONFIRM_CARDS]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code       :: u32 = " + format_value(it.code);
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_DECK(const CoreMsg_SHUFFLE_DECK &msg) {
  (void)msg;
  std::string dump = "[[MSG_SHUFFLE_DECK]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_REFRESH_DECK(const CoreMsg_REFRESH_DECK &msg) {
  (void)msg;
  std::string dump = "[[MSG_REFRESH_DECK]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_SWAP_GRAVE_DECK(const CoreMsg_SWAP_GRAVE_DECK &msg) {
  (void)msg;
  std::string dump = "[[MSG_SWAP_GRAVE_DECK]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_SET_CARD(const CoreMsg_SHUFFLE_SET_CARD &msg) {
  (void)msg;
  std::string dump = "[[MSG_SHUFFLE_SET_CARD]]\n";
  dump += "\n  location :: u8  = " + format_value(msg.location);
  dump += "\n  cards1   :: Card[" + std::to_string(msg.cards1.size()) + "] =";
  for (const auto &it: msg.cards1) {
    dump += "\n  {";
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n    ignore     :: u8  = " + format_value(it.ignore);
    dump += "\n  }";
  }
  dump += "\n  cards2   :: Card[" + std::to_string(msg.cards2.size()) + "] =";
  for (const auto &it: msg.cards2) {
    dump += "\n  {";
    dump += "\n    controller :: u8  = " + format_value(it.controller);
    dump += "\n    location   :: u8  = " + format_value(it.location);
    dump += "\n    sequence   :: u8  = " + format_value(it.sequence);
    dump += "\n    ignore     :: u8  = " + format_value(it.ignore);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_HAND(const CoreMsg_SHUFFLE_HAND &msg) {
  (void)msg;
  std::string dump = "[[MSG_SHUFFLE_HAND]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code :: u32 = " + format_value(it.code);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_SHUFFLE_EXTRA(const CoreMsg_SHUFFLE_EXTRA &msg) {
  (void)msg;
  std::string dump = "[[MSG_SHUFFLE_EXTRA]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code :: u32 = " + format_value(it.code);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_REVERSE_DECK(const CoreMsg_REVERSE_DECK &msg) {
  (void)msg;
  std::string dump = "[[MSG_REVERSE_DECK]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_DECK_TOP(const CoreMsg_DECK_TOP &msg) {
  (void)msg;
  std::string dump = "[[MSG_DECK_TOP]]\n";
  dump += "\n  player   :: u8  = " + format_value(msg.player);
  dump += "\n  sequence :: u8  = " + format_value(msg.sequence);
  dump += "\n  code     :: u32 = " + format_value(msg.code);
  return dump;
}

static inline std::string dump_CoreMsg_NEW_TURN(const CoreMsg_NEW_TURN &msg) {
  (void)msg;
  std::string dump = "[[MSG_NEW_TURN]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_NEW_PHASE(const CoreMsg_NEW_PHASE &msg) {
  (void)msg;
  std::string dump = "[[MSG_NEW_PHASE]]\n";
  dump += "\n  phase :: u16 = " + format_value(msg.phase);
  return dump;
}

static inline std::string dump_CoreMsg_MOVE(const CoreMsg_MOVE &msg) {
  (void)msg;
  std::string dump = "[[MSG_MOVE]]\n";
  dump += "\n  code                :: u32 = " + format_value(msg.code);
  dump += "\n  previous_controller :: u8  = " + format_value(msg.previous_controller);
  dump += "\n  previous_location   :: u8  = " + format_value(msg.previous_location);
  dump += "\n  previous_sequence   :: u8  = " + format_value(msg.previous_sequence);
  dump += "\n  previous_position   :: u8  = " + format_value(msg.previous_position);
  dump += "\n  current_controller  :: u8  = " + format_value(msg.current_controller);
  dump += "\n  current_location    :: u8  = " + format_value(msg.current_location);
  dump += "\n  current_sequence    :: u8  = " + format_value(msg.current_sequence);
  dump += "\n  current_position    :: u8  = " + format_value(msg.current_position);
  dump += "\n  reason              :: u32 = " + format_value(msg.reason);
  return dump;
}

static inline std::string dump_CoreMsg_POS_CHANGE(const CoreMsg_POS_CHANGE &msg) {
  (void)msg;
  std::string dump = "[[MSG_POS_CHANGE]]\n";
  dump += "\n  code               :: u32 = " + format_value(msg.code);
  dump += "\n  current_controller :: u8  = " + format_value(msg.current_controller);
  dump += "\n  current_location   :: u8  = " + format_value(msg.current_location);
  dump += "\n  current_sequence   :: u8  = " + format_value(msg.current_sequence);
  dump += "\n  previous_position  :: u8  = " + format_value(msg.previous_position);
  dump += "\n  current_position   :: u8  = " + format_value(msg.current_position);
  return dump;
}

static inline std::string dump_CoreMsg_SET(const CoreMsg_SET &msg) {
  (void)msg;
  std::string dump = "[[MSG_SET]]\n";
  dump += "\n  code               :: u32 = " + format_value(msg.code);
  dump += "\n  current_controller :: u8  = " + format_value(msg.current_controller);
  dump += "\n  current_location   :: u8  = " + format_value(msg.current_location);
  dump += "\n  current_sequence   :: u8  = " + format_value(msg.current_sequence);
  dump += "\n  current_position   :: u8  = " + format_value(msg.current_position);
  return dump;
}

static inline std::string dump_CoreMsg_SWAP(const CoreMsg_SWAP &msg) {
  (void)msg;
  std::string dump = "[[MSG_SWAP]]\n";
  dump += "\n  code1       :: u32 = " + format_value(msg.code1);
  dump += "\n  controller1 :: u8  = " + format_value(msg.controller1);
  dump += "\n  location1   :: u8  = " + format_value(msg.location1);
  dump += "\n  sequence1   :: u8  = " + format_value(msg.sequence1);
  dump += "\n  position1   :: u8  = " + format_value(msg.position1);
  dump += "\n  code2       :: u32 = " + format_value(msg.code2);
  dump += "\n  controller2 :: u8  = " + format_value(msg.controller2);
  dump += "\n  location2   :: u8  = " + format_value(msg.location2);
  dump += "\n  sequence2   :: u8  = " + format_value(msg.sequence2);
  dump += "\n  position2   :: u8  = " + format_value(msg.position2);
  return dump;
}

static inline std::string dump_CoreMsg_FIELD_DISABLED(const CoreMsg_FIELD_DISABLED &msg) {
  (void)msg;
  std::string dump = "[[MSG_FIELD_DISABLED]]\n";
  dump += "\n  disabled_fields :: u32 = " + format_value(msg.disabled_fields);
  return dump;
}

static inline std::string dump_CoreMsg_SUMMONING(const CoreMsg_SUMMONING &msg) {
  (void)msg;
  std::string dump = "[[MSG_SUMMONING]]\n";
  dump += "\n  code       :: u32 = " + format_value(msg.code);
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  position   :: u8  = " + format_value(msg.position);
  return dump;
}

static inline std::string dump_CoreMsg_SUMMONED(const CoreMsg_SUMMONED &msg) {
  (void)msg;
  std::string dump = "[[MSG_SUMMONED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_SPSUMMONING(const CoreMsg_SPSUMMONING &msg) {
  (void)msg;
  std::string dump = "[[MSG_SPSUMMONING]]\n";
  dump += "\n  code       :: u32 = " + format_value(msg.code);
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  position   :: u8  = " + format_value(msg.position);
  return dump;
}

static inline std::string dump_CoreMsg_SPSUMMONED(const CoreMsg_SPSUMMONED &msg) {
  (void)msg;
  std::string dump = "[[MSG_SPSUMMONED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_FLIPSUMMONING(const CoreMsg_FLIPSUMMONING &msg) {
  (void)msg;
  std::string dump = "[[MSG_FLIPSUMMONING]]\n";
  dump += "\n  code       :: u32 = " + format_value(msg.code);
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  position   :: u8  = " + format_value(msg.position);
  return dump;
}

static inline std::string dump_CoreMsg_FLIPSUMMONED(const CoreMsg_FLIPSUMMONED &msg) {
  (void)msg;
  std::string dump = "[[MSG_FLIPSUMMONED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_CHAINING(const CoreMsg_CHAINING &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAINING]]\n";
  dump += "\n  code                      :: u32 = " + format_value(msg.code);
  dump += "\n  previous_chain_controller :: u8  = " + format_value(msg.previous_chain_controller);
  dump += "\n  previous_chain_location   :: u8  = " + format_value(msg.previous_chain_location);
  dump += "\n  previous_chain_sequence   :: u8  = " + format_value(msg.previous_chain_sequence);
  dump += "\n  subsequence               :: u8  = " + format_value(msg.subsequence);
  dump += "\n  chain_controller          :: u8  = " + format_value(msg.chain_controller);
  dump += "\n  chain_location            :: u8  = " + format_value(msg.chain_location);
  dump += "\n  chain_sequence            :: u8  = " + format_value(msg.chain_sequence);
  dump += "\n  desc                      :: u32 = " + format_value(msg.desc);
  dump += "\n  chain_param               :: u8  = " + format_value(msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAINED(const CoreMsg_CHAINED &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAINED]]\n";
  dump += "\n  chain_param :: u8  = " + format_value(msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_SOLVING(const CoreMsg_CHAIN_SOLVING &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAIN_SOLVING]]\n";
  dump += "\n  chain_param :: u8  = " + format_value(msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_SOLVED(const CoreMsg_CHAIN_SOLVED &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAIN_SOLVED]]\n";
  dump += "\n  chain_param :: u8  = " + format_value(msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_END(const CoreMsg_CHAIN_END &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAIN_END]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_NEGATED(const CoreMsg_CHAIN_NEGATED &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAIN_NEGATED]]\n";
  dump += "\n  chain_param :: u8  = " + format_value(msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CHAIN_DISABLED(const CoreMsg_CHAIN_DISABLED &msg) {
  (void)msg;
  std::string dump = "[[MSG_CHAIN_DISABLED]]\n";
  dump += "\n  chain_param :: u8  = " + format_value(msg.chain_param);
  return dump;
}

static inline std::string dump_CoreMsg_CARD_SELECTED(const CoreMsg_CARD_SELECTED &msg) {
  (void)msg;
  std::string dump = "[[MSG_CARD_SELECTED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_RANDOM_SELECTED(const CoreMsg_RANDOM_SELECTED &msg) {
  (void)msg;
  std::string dump = "[[MSG_RANDOM_SELECTED]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_BECOME_TARGET(const CoreMsg_BECOME_TARGET &msg) {
  (void)msg;
  std::string dump = "[[MSG_BECOME_TARGET]]\n";
  dump += "\n  cards :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    controller  :: u8  = " + format_value(it.controller);
    dump += "\n    location    :: u8  = " + format_value(it.location);
    dump += "\n    sequence    :: u8  = " + format_value(it.sequence);
    dump += "\n    subsequence :: u8  = " + format_value(it.subsequence);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_DRAW(const CoreMsg_DRAW &msg) {
  (void)msg;
  std::string dump = "[[MSG_DRAW]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  cards  :: Card[" + std::to_string(msg.cards.size()) + "] =";
  for (const auto &it: msg.cards) {
    dump += "\n  {";
    dump += "\n    code :: u32 = " + format_value(it.code);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_DAMAGE(const CoreMsg_DAMAGE &msg) {
  (void)msg;
  std::string dump = "[[MSG_DAMAGE]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  value  :: u32 = " + format_value(msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_RECOVER(const CoreMsg_RECOVER &msg) {
  (void)msg;
  std::string dump = "[[MSG_RECOVER]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  value  :: u32 = " + format_value(msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_LPUPDATE(const CoreMsg_LPUPDATE &msg) {
  (void)msg;
  std::string dump = "[[MSG_LPUPDATE]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  value  :: u32 = " + format_value(msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_PAY_LPCOST(const CoreMsg_PAY_LPCOST &msg) {
  (void)msg;
  std::string dump = "[[MSG_PAY_LPCOST]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  value  :: u32 = " + format_value(msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_EQUIP(const CoreMsg_EQUIP &msg) {
  (void)msg;
  std::string dump = "[[MSG_EQUIP]]\n";
  dump += "\n  controller1 :: u8  = " + format_value(msg.controller1);
  dump += "\n  location1   :: u8  = " + format_value(msg.location1);
  dump += "\n  sequence1   :: u8  = " + format_value(msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format_value(msg.ignore1);
  dump += "\n  controller2 :: u8  = " + format_value(msg.controller2);
  dump += "\n  location2   :: u8  = " + format_value(msg.location2);
  dump += "\n  sequence2   :: u8  = " + format_value(msg.sequence2);
  dump += "\n  ignore2     :: u8  = " + format_value(msg.ignore2);
  return dump;
}

static inline std::string dump_CoreMsg_UNEQUIP(const CoreMsg_UNEQUIP &msg) {
  (void)msg;
  std::string dump = "[[MSG_UNEQUIP]]\n";
  dump += "\n  controller1 :: u8  = " + format_value(msg.controller1);
  dump += "\n  location1   :: u8  = " + format_value(msg.location1);
  dump += "\n  sequence1   :: u8  = " + format_value(msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format_value(msg.ignore1);
  return dump;
}

static inline std::string dump_CoreMsg_CARD_TARGET(const CoreMsg_CARD_TARGET &msg) {
  (void)msg;
  std::string dump = "[[MSG_CARD_TARGET]]\n";
  dump += "\n  controller1 :: u8  = " + format_value(msg.controller1);
  dump += "\n  location1   :: u8  = " + format_value(msg.location1);
  dump += "\n  sequence1   :: u8  = " + format_value(msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format_value(msg.ignore1);
  dump += "\n  controller2 :: u8  = " + format_value(msg.controller2);
  dump += "\n  location2   :: u8  = " + format_value(msg.location2);
  dump += "\n  sequence2   :: u8  = " + format_value(msg.sequence2);
  dump += "\n  ignore2     :: u8  = " + format_value(msg.ignore2);
  return dump;
}

static inline std::string dump_CoreMsg_CANCEL_TARGET(const CoreMsg_CANCEL_TARGET &msg) {
  (void)msg;
  std::string dump = "[[MSG_CANCEL_TARGET]]\n";
  dump += "\n  controller1 :: u8  = " + format_value(msg.controller1);
  dump += "\n  location1   :: u8  = " + format_value(msg.location1);
  dump += "\n  sequence1   :: u8  = " + format_value(msg.sequence1);
  dump += "\n  ignore1     :: u8  = " + format_value(msg.ignore1);
  dump += "\n  controller2 :: u8  = " + format_value(msg.controller2);
  dump += "\n  location2   :: u8  = " + format_value(msg.location2);
  dump += "\n  sequence2   :: u8  = " + format_value(msg.sequence2);
  dump += "\n  ignore2     :: u8  = " + format_value(msg.ignore2);
  return dump;
}

static inline std::string dump_CoreMsg_ADD_COUNTER(const CoreMsg_ADD_COUNTER &msg) {
  (void)msg;
  std::string dump = "[[MSG_ADD_COUNTER]]\n";
  dump += "\n  type       :: u16 = " + format_value(msg.type);
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  count      :: u16 = " + format_value(msg.count);
  return dump;
}

static inline std::string dump_CoreMsg_REMOVE_COUNTER(const CoreMsg_REMOVE_COUNTER &msg) {
  (void)msg;
  std::string dump = "[[MSG_REMOVE_COUNTER]]\n";
  dump += "\n  type       :: u16 = " + format_value(msg.type);
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  count      :: u16 = " + format_value(msg.count);
  return dump;
}

static inline std::string dump_CoreMsg_ATTACK(const CoreMsg_ATTACK &msg) {
  (void)msg;
  std::string dump = "[[MSG_ATTACK]]\n";
  dump += "\n  atk_controller :: u8  = " + format_value(msg.atk_controller);
  dump += "\n  atk_location   :: u8  = " + format_value(msg.atk_location);
  dump += "\n  atk_sequence   :: u8  = " + format_value(msg.atk_sequence);
  dump += "\n  atk_ignore     :: u8  = " + format_value(msg.atk_ignore);
  dump += "\n  def_controller :: u8  = " + format_value(msg.def_controller);
  dump += "\n  def_location   :: u8  = " + format_value(msg.def_location);
  dump += "\n  def_sequence   :: u8  = " + format_value(msg.def_sequence);
  dump += "\n  def_ignore     :: u8  = " + format_value(msg.def_ignore);
  return dump;
}

static inline std::string dump_CoreMsg_BATTLE(const CoreMsg_BATTLE &msg) {
  (void)msg;
  std::string dump = "[[MSG_BATTLE]]\n";
  dump += "\n  atk_controller  :: u8  = " + format_value(msg.atk_controller);
  dump += "\n  atk_location    :: u8  = " + format_value(msg.atk_location);
  dump += "\n  atk_sequence    :: u8  = " + format_value(msg.atk_sequence);
  dump += "\n  atk_subsequence :: u8  = " + format_value(msg.atk_subsequence);
  dump += "\n  atk_atkvalue    :: u32 = " + format_value(msg.atk_atkvalue);
  dump += "\n  atk_defvalue    :: u32 = " + format_value(msg.atk_defvalue);
  dump += "\n  atk_ignore      :: u8  = " + format_value(msg.atk_ignore);
  dump += "\n  def_controller  :: u8  = " + format_value(msg.def_controller);
  dump += "\n  def_location    :: u8  = " + format_value(msg.def_location);
  dump += "\n  def_sequence    :: u8  = " + format_value(msg.def_sequence);
  dump += "\n  def_subsequence :: u8  = " + format_value(msg.def_subsequence);
  dump += "\n  def_atkvalue    :: u32 = " + format_value(msg.def_atkvalue);
  dump += "\n  def_defvalue    :: u32 = " + format_value(msg.def_defvalue);
  dump += "\n  def_ignore      :: u8  = " + format_value(msg.def_ignore);
  return dump;
}

static inline std::string dump_CoreMsg_ATTACK_DISABLED(const CoreMsg_ATTACK_DISABLED &msg) {
  (void)msg;
  std::string dump = "[[MSG_ATTACK_DISABLED]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_DAMAGE_STEP_START(const CoreMsg_DAMAGE_STEP_START &msg) {
  (void)msg;
  std::string dump = "[[MSG_DAMAGE_STEP_START]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_DAMAGE_STEP_END(const CoreMsg_DAMAGE_STEP_END &msg) {
  (void)msg;
  std::string dump = "[[MSG_DAMAGE_STEP_END]]\n";
  return dump;
}

static inline std::string dump_CoreMsg_MISSED_EFFECT(const CoreMsg_MISSED_EFFECT &msg) {
  (void)msg;
  std::string dump = "[[MSG_MISSED_EFFECT]]\n";
  dump += "\n  ignore :: u32 = " + format_value(msg.ignore);
  dump += "\n  code   :: u32 = " + format_value(msg.code);
  return dump;
}

static inline std::string dump_CoreMsg_TOSS_COIN(const CoreMsg_TOSS_COIN &msg) {
  (void)msg;
  std::string dump = "[[MSG_TOSS_COIN]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  tosses :: Result[" + std::to_string(msg.tosses.size()) + "] =";
  for (const auto &it: msg.tosses) {
    dump += "\n  {";
    dump += "\n    value :: u8  = " + format_value(it.value);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_TOSS_DICE(const CoreMsg_TOSS_DICE &msg) {
  (void)msg;
  std::string dump = "[[MSG_TOSS_DICE]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  tosses :: Result[" + std::to_string(msg.tosses.size()) + "] =";
  for (const auto &it: msg.tosses) {
    dump += "\n  {";
    dump += "\n    value :: u8  = " + format_value(it.value);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_ROCK_PAPER_SCISSORS(const CoreMsg_ROCK_PAPER_SCISSORS &msg) {
  (void)msg;
  std::string dump = "[[MSG_ROCK_PAPER_SCISSORS]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  return dump;
}

static inline std::string dump_CoreMsg_HAND_RES(const CoreMsg_HAND_RES &msg) {
  (void)msg;
  std::string dump = "[[MSG_HAND_RES]]\n";
  dump += "\n  res :: u8  = " + format_value(msg.res);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_RACE(const CoreMsg_ANNOUNCE_RACE &msg) {
  (void)msg;
  std::string dump = "[[MSG_ANNOUNCE_RACE]]\n";
  dump += "\n  player    :: u8  = " + format_value(msg.player);
  dump += "\n  count     :: u8  = " + format_value(msg.count);
  dump += "\n  available :: u32 = " + format_value(msg.available);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_ATTRIB(const CoreMsg_ANNOUNCE_ATTRIB &msg) {
  (void)msg;
  std::string dump = "[[MSG_ANNOUNCE_ATTRIB]]\n";
  dump += "\n  player    :: u8  = " + format_value(msg.player);
  dump += "\n  count     :: u8  = " + format_value(msg.count);
  dump += "\n  available :: u32 = " + format_value(msg.available);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_CARD(const CoreMsg_ANNOUNCE_CARD &msg) {
  (void)msg;
  std::string dump = "[[MSG_ANNOUNCE_CARD]]\n";
  dump += "\n  player          :: u8  = " + format_value(msg.player);
  dump += "\n  declarable_type :: u32 = " + format_value(msg.declarable_type);
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_NUMBER(const CoreMsg_ANNOUNCE_NUMBER &msg) {
  (void)msg;
  std::string dump = "[[MSG_ANNOUNCE_NUMBER]]\n";
  dump += "\n  player  :: u8  = " + format_value(msg.player);
  dump += "\n  numbers :: Announce[" + std::to_string(msg.numbers.size()) + "] =";
  for (const auto &it: msg.numbers) {
    dump += "\n  {";
    dump += "\n    value :: u32 = " + format_value(it.value);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_ANNOUNCE_CARD_FILTER(const CoreMsg_ANNOUNCE_CARD_FILTER &msg) {
  (void)msg;
  std::string dump = "[[MSG_ANNOUNCE_CARD_FILTER]]\n";
  dump += "\n  player  :: u8  = " + format_value(msg.player);
  dump += "\n  filters :: Filter[" + std::to_string(msg.filters.size()) + "] =";
  for (const auto &it: msg.filters) {
    dump += "\n  {";
    dump += "\n    opcode :: u32 = " + format_value(it.opcode);
    dump += "\n  }";
  }
  return dump;
}

static inline std::string dump_CoreMsg_CARD_HINT(const CoreMsg_CARD_HINT &msg) {
  (void)msg;
  std::string dump = "[[MSG_CARD_HINT]]\n";
  dump += "\n  controller :: u8  = " + format_value(msg.controller);
  dump += "\n  location   :: u8  = " + format_value(msg.location);
  dump += "\n  sequence   :: u8  = " + format_value(msg.sequence);
  dump += "\n  ignore     :: u8  = " + format_value(msg.ignore);
  dump += "\n  chtype     :: u8  = " + format_value(msg.chtype);
  dump += "\n  value      :: u32 = " + format_value(msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_PLAYER_HINT(const CoreMsg_PLAYER_HINT &msg) {
  (void)msg;
  std::string dump = "[[MSG_PLAYER_HINT]]\n";
  dump += "\n  player :: u8  = " + format_value(msg.player);
  dump += "\n  chtype :: u8  = " + format_value(msg.chtype);
  dump += "\n  value  :: u32 = " + format_value(msg.value);
  return dump;
}

static inline std::string dump_CoreMsg_MATCH_KILL(const CoreMsg_MATCH_KILL &msg) {
  (void)msg;
  std::string dump = "[[MSG_MATCH_KILL]]\n";
  dump += "\n  match_kill :: u32 = " + format_value(msg.match_kill);
  return dump;
}

static inline std::string dump_CoreMsg_RELOAD_FIELD(const CoreMsg_RELOAD_FIELD &msg) {
  (void)msg;
  std::string dump = "[[MSG_RELOAD_FIELD]]\n";
  dump += "\n  duel_rule :: u8  = " + format_value(msg.duel_rule);
  dump += "\n  players   :: PlayersField[4] =";
  for (unsigned i = 0; i != 4; ++i) {
    dump += "\n  {";
    dump += "\n    lp                :: u32 = " + format_value(msg.players[i].lp);
    dump += "\n    mzone_cards       :: MCard[7] =";
    for (unsigned i = 0; i != 7; ++i) {
      dump += "\n    {";
      dump += "\n      value :: MValue(" + std::string("%s", msg.players[i].mzone_cards[i].value ? "Yes" : "No") + ") =";
      if (msg.players[i].mzone_cards[i].value) {
        dump += "\n      {";
        dump += "\n        position  :: u8  = " + format_value((*(msg.players[i].mzone_cards[i].value)).position);
        dump += "\n        xyz_count :: u8  = " + format_value((*(msg.players[i].mzone_cards[i].value)).xyz_count);
        dump += "\n      }";
      }
      dump += "\n    }";
    }
    dump += "\n    cards             :: Card[8] =";
    for (unsigned i = 0; i != 8; ++i) {
      dump += "\n    {";
      dump += "\n      value :: Value(" + std::string("%s", msg.players[i].cards[i].value ? "Yes" : "No") + ") =";
      if (msg.players[i].cards[i].value) {
        dump += "\n      {";
        dump += "\n        position :: u8  = " + format_value((*(msg.players[i].cards[i].value)).position);
        dump += "\n      }";
      }
      dump += "\n    }";
    }
    dump += "\n    deck_count        :: u8  = " + format_value(msg.players[i].deck_count);
    dump += "\n    hand_count        :: u8  = " + format_value(msg.players[i].hand_count);
    dump += "\n    grave_count       :: u8  = " + format_value(msg.players[i].grave_count);
    dump += "\n    banish_count      :: u8  = " + format_value(msg.players[i].banish_count);
    dump += "\n    extra_count       :: u8  = " + format_value(msg.players[i].extra_count);
    dump += "\n    extra_pendu_count :: u8  = " + format_value(msg.players[i].extra_pendu_count);
    dump += "\n    chains            :: Chain[" + std::to_string(msg.players[i].chains.size()) + "] =";
    for (const auto &it: msg.players[i].chains) {
      dump += "\n    {";
      dump += "\n      code                 :: u32 = " + format_value(it.code);
      dump += "\n      previous_controller  :: u8  = " + format_value(it.previous_controller);
      dump += "\n      previous_location    :: u8  = " + format_value(it.previous_location);
      dump += "\n      previous_sequence    :: u8  = " + format_value(it.previous_sequence);
      dump += "\n      previous_subsequence :: u8  = " + format_value(it.previous_subsequence);
      dump += "\n      current_controller   :: u8  = " + format_value(it.current_controller);
      dump += "\n      current_location     :: u8  = " + format_value(it.current_location);
      dump += "\n      current_sequence     :: u8  = " + format_value(it.current_sequence);
      dump += "\n      desc                 :: u32 = " + format_value(it.desc);
      dump += "\n    }";
    }
    dump += "\n  }";
  }
  return dump;
}

