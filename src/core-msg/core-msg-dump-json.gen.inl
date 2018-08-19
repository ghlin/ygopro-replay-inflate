/* !!! Generated code, DO NOT EDIT !!! */


std::string
dump_json_CoreMsg_SHUFFLE_SET_CARD(const CoreMsg_SHUFFLE_SET_CARD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SHUFFLE_SET_CARD\", \"data\":";
  dump += "{";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"cards1\": [";
  for (auto iter = msg.cards1.begin(); iter != msg.cards1.end(); ++iter) {
    if (iter != msg.cards1.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"ignore\": " + std::to_string(dumping.ignore);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"cards2\": [";
  for (auto iter = msg.cards2.begin(); iter != msg.cards2.end(); ++iter) {
    if (iter != msg.cards2.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"ignore\": " + std::to_string(dumping.ignore);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_RETRY(const CoreMsg_RETRY &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_RETRY\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_HINT(const CoreMsg_HINT &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_HINT\", \"data\":";
  dump += "{";
  dump += "\"type\": " + std::to_string(msg.type);
  dump += ",";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"data\": " + std::to_string(msg.data);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_WIN(const CoreMsg_WIN &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_WIN\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"type\": " + std::to_string(msg.type);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_WAITING(const CoreMsg_WAITING &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_WAITING\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_START(const CoreMsg_START &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_START\", \"data\":";
  dump += "{";
  dump += "\"player_type\": " + std::to_string(msg.player_type);
  dump += ",";
  dump += "\"player0_lp\": " + std::to_string(msg.player0_lp);
  dump += ",";
  dump += "\"player1_lp\": " + std::to_string(msg.player1_lp);
  dump += ",";
  dump += "\"player0_deck_count\": " + std::to_string(msg.player0_deck_count);
  dump += ",";
  dump += "\"player0_extra_count\": " + std::to_string(msg.player0_extra_count);
  dump += ",";
  dump += "\"player1_deck_count\": " + std::to_string(msg.player1_deck_count);
  dump += ",";
  dump += "\"player1_extra_count\": " + std::to_string(msg.player1_extra_count);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_BATTLECMD(const CoreMsg_SELECT_BATTLECMD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_BATTLECMD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"candidates1\": [";
  for (auto iter = msg.candidates1.begin(); iter != msg.candidates1.end(); ++iter) {
    if (iter != msg.candidates1.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"description\": " + std::to_string(dumping.description);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"candidates2\": [";
  for (auto iter = msg.candidates2.begin(); iter != msg.candidates2.end(); ++iter) {
    if (iter != msg.candidates2.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"to_main2_phase\": " + std::to_string(msg.to_main2_phase);
  dump += ",";
  dump += "\"to_end_phase\": " + std::to_string(msg.to_end_phase);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_IDLECMD(const CoreMsg_SELECT_IDLECMD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_IDLECMD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"summon_candidates\": [";
  for (auto iter = msg.summon_candidates.begin(); iter != msg.summon_candidates.end(); ++iter) {
    if (iter != msg.summon_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"spsummon_candidates\": [";
  for (auto iter = msg.spsummon_candidates.begin(); iter != msg.spsummon_candidates.end(); ++iter) {
    if (iter != msg.spsummon_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"reposition_candidates\": [";
  for (auto iter = msg.reposition_candidates.begin(); iter != msg.reposition_candidates.end(); ++iter) {
    if (iter != msg.reposition_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"mset_candidates\": [";
  for (auto iter = msg.mset_candidates.begin(); iter != msg.mset_candidates.end(); ++iter) {
    if (iter != msg.mset_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"sset_candidates\": [";
  for (auto iter = msg.sset_candidates.begin(); iter != msg.sset_candidates.end(); ++iter) {
    if (iter != msg.sset_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"active_candidates\": [";
  for (auto iter = msg.active_candidates.begin(); iter != msg.active_candidates.end(); ++iter) {
    if (iter != msg.active_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"desc\": " + std::to_string(dumping.desc);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"to_battle_phase\": " + std::to_string(msg.to_battle_phase);
  dump += ",";
  dump += "\"to_end_phase\": " + std::to_string(msg.to_end_phase);
  dump += ",";
  dump += "\"can_shuffle\": " + std::to_string(msg.can_shuffle);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_EFFECTYN(const CoreMsg_SELECT_EFFECTYN &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_EFFECTYN\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"_ignore_\": " + std::to_string(msg._ignore_);
  dump += ",";
  dump += "\"desc\": " + std::to_string(msg.desc);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_YESNO(const CoreMsg_SELECT_YESNO &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_YESNO\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"desc\": " + std::to_string(msg.desc);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_OPTION(const CoreMsg_SELECT_OPTION &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_OPTION\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"candidates\": [";
  for (auto iter = msg.candidates.begin(); iter != msg.candidates.end(); ++iter) {
    if (iter != msg.candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"option_id\": " + std::to_string(dumping.option_id);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_CARD(const CoreMsg_SELECT_CARD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_CARD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cancelable\": " + std::to_string(msg.cancelable);
  dump += ",";
  dump += "\"select_min\": " + std::to_string(msg.select_min);
  dump += ",";
  dump += "\"select_max\": " + std::to_string(msg.select_max);
  dump += ",";
  dump += "\"candidates\": [";
  for (auto iter = msg.candidates.begin(); iter != msg.candidates.end(); ++iter) {
    if (iter != msg.candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_UNSELECT_CARD(const CoreMsg_SELECT_UNSELECT_CARD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_UNSELECT_CARD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"finishable\": " + std::to_string(msg.finishable);
  dump += ",";
  dump += "\"cancelable\": " + std::to_string(msg.cancelable);
  dump += ",";
  dump += "\"select_min\": " + std::to_string(msg.select_min);
  dump += ",";
  dump += "\"select_max\": " + std::to_string(msg.select_max);
  dump += ",";
  dump += "\"candidates1\": [";
  for (auto iter = msg.candidates1.begin(); iter != msg.candidates1.end(); ++iter) {
    if (iter != msg.candidates1.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"candidates2\": [";
  for (auto iter = msg.candidates2.begin(); iter != msg.candidates2.end(); ++iter) {
    if (iter != msg.candidates2.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_CHAIN(const CoreMsg_SELECT_CHAIN &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_CHAIN\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"spe_count\": " + std::to_string(msg.spe_count);
  dump += ",";
  dump += "\"forced\": " + std::to_string(msg.forced);
  dump += ",";
  dump += "\"hint0\": " + std::to_string(msg.hint0);
  dump += ",";
  dump += "\"hint1\": " + std::to_string(msg.hint1);
  dump += ",";
  dump += "\"candidates\": [";
  for (auto iter = msg.candidates.begin(); iter != msg.candidates.end(); ++iter) {
    if (iter != msg.candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"flag\": " + std::to_string(dumping.flag);
    dump += ",";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += ",";
    dump += "\"desc\": " + std::to_string(dumping.desc);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_PLACE(const CoreMsg_SELECT_PLACE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_PLACE\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"select_min\": " + std::to_string(msg.select_min);
  dump += ",";
  dump += "\"selectable_field\": " + std::to_string(msg.selectable_field);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_DISFIELD(const CoreMsg_SELECT_DISFIELD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_DISFIELD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"select_min\": " + std::to_string(msg.select_min);
  dump += ",";
  dump += "\"selectable_field\": " + std::to_string(msg.selectable_field);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_POSITION(const CoreMsg_SELECT_POSITION &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_POSITION\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"positions\": " + std::to_string(msg.positions);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_TRIBUTE(const CoreMsg_SELECT_TRIBUTE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_TRIBUTE\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cancelable\": " + std::to_string(msg.cancelable);
  dump += ",";
  dump += "\"select_min\": " + std::to_string(msg.select_min);
  dump += ",";
  dump += "\"select_max\": " + std::to_string(msg.select_max);
  dump += ",";
  dump += "\"candidates\": [";
  for (auto iter = msg.candidates.begin(); iter != msg.candidates.end(); ++iter) {
    if (iter != msg.candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"operation_param\": " + std::to_string(dumping.operation_param);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_COUNTER(const CoreMsg_SELECT_COUNTER &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_COUNTER\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"select_counter_type\": " + std::to_string(msg.select_counter_type);
  dump += ",";
  dump += "\"select_counter_count\": " + std::to_string(msg.select_counter_count);
  dump += ",";
  dump += "\"candidates\": [";
  for (auto iter = msg.candidates.begin(); iter != msg.candidates.end(); ++iter) {
    if (iter != msg.candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"operation_param\": " + std::to_string(dumping.operation_param);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SELECT_SUM(const CoreMsg_SELECT_SUM &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SELECT_SUM\", \"data\":";
  dump += "{";
  dump += "\"select_mode\": " + std::to_string(msg.select_mode);
  dump += ",";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"select_sumval\": " + std::to_string(msg.select_sumval);
  dump += ",";
  dump += "\"select_min\": " + std::to_string(msg.select_min);
  dump += ",";
  dump += "\"select_max\": " + std::to_string(msg.select_max);
  dump += ",";
  dump += "\"must_select_candidates\": [";
  for (auto iter = msg.must_select_candidates.begin(); iter != msg.must_select_candidates.end(); ++iter) {
    if (iter != msg.must_select_candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"operation_param\": " + std::to_string(dumping.operation_param);
    dump += "}";
  }
  dump += "]";
  dump += ",";
  dump += "\"candidates\": [";
  for (auto iter = msg.candidates.begin(); iter != msg.candidates.end(); ++iter) {
    if (iter != msg.candidates.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"operation_param\": " + std::to_string(dumping.operation_param);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SORT_CARD(const CoreMsg_SORT_CARD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SORT_CARD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SORT_CHAIN(const CoreMsg_SORT_CHAIN &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SORT_CHAIN\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CONFIRM_DECKTOP(const CoreMsg_CONFIRM_DECKTOP &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CONFIRM_DECKTOP\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CONFIRM_EXTRATOP(const CoreMsg_CONFIRM_EXTRATOP &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CONFIRM_EXTRATOP\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CONFIRM_CARDS(const CoreMsg_CONFIRM_CARDS &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CONFIRM_CARDS\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += ",";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SHUFFLE_DECK(const CoreMsg_SHUFFLE_DECK &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SHUFFLE_DECK\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_REFRESH_DECK(const CoreMsg_REFRESH_DECK &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_REFRESH_DECK\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SWAP_GRAVE_DECK(const CoreMsg_SWAP_GRAVE_DECK &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SWAP_GRAVE_DECK\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SHUFFLE_HAND(const CoreMsg_SHUFFLE_HAND &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SHUFFLE_HAND\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SHUFFLE_EXTRA(const CoreMsg_SHUFFLE_EXTRA &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SHUFFLE_EXTRA\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_REVERSE_DECK(const CoreMsg_REVERSE_DECK &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_REVERSE_DECK\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_DECK_TOP(const CoreMsg_DECK_TOP &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_DECK_TOP\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_NEW_TURN(const CoreMsg_NEW_TURN &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_NEW_TURN\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_NEW_PHASE(const CoreMsg_NEW_PHASE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_NEW_PHASE\", \"data\":";
  dump += "{";
  dump += "\"phase\": " + std::to_string(msg.phase);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_MOVE(const CoreMsg_MOVE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_MOVE\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"previous_controller\": " + std::to_string(msg.previous_controller);
  dump += ",";
  dump += "\"previous_location\": " + std::to_string(msg.previous_location);
  dump += ",";
  dump += "\"previous_sequence\": " + std::to_string(msg.previous_sequence);
  dump += ",";
  dump += "\"previous_position\": " + std::to_string(msg.previous_position);
  dump += ",";
  dump += "\"current_controller\": " + std::to_string(msg.current_controller);
  dump += ",";
  dump += "\"current_location\": " + std::to_string(msg.current_location);
  dump += ",";
  dump += "\"current_sequence\": " + std::to_string(msg.current_sequence);
  dump += ",";
  dump += "\"current_position\": " + std::to_string(msg.current_position);
  dump += ",";
  dump += "\"reason\": " + std::to_string(msg.reason);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_POS_CHANGE(const CoreMsg_POS_CHANGE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_POS_CHANGE\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"current_controller\": " + std::to_string(msg.current_controller);
  dump += ",";
  dump += "\"current_location\": " + std::to_string(msg.current_location);
  dump += ",";
  dump += "\"current_sequence\": " + std::to_string(msg.current_sequence);
  dump += ",";
  dump += "\"previous_position\": " + std::to_string(msg.previous_position);
  dump += ",";
  dump += "\"current_position\": " + std::to_string(msg.current_position);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SET(const CoreMsg_SET &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SET\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"current_controller\": " + std::to_string(msg.current_controller);
  dump += ",";
  dump += "\"current_location\": " + std::to_string(msg.current_location);
  dump += ",";
  dump += "\"current_sequence\": " + std::to_string(msg.current_sequence);
  dump += ",";
  dump += "\"current_position\": " + std::to_string(msg.current_position);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SWAP(const CoreMsg_SWAP &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SWAP\", \"data\":";
  dump += "{";
  dump += "\"code1\": " + std::to_string(msg.code1);
  dump += ",";
  dump += "\"controller1\": " + std::to_string(msg.controller1);
  dump += ",";
  dump += "\"location1\": " + std::to_string(msg.location1);
  dump += ",";
  dump += "\"sequence1\": " + std::to_string(msg.sequence1);
  dump += ",";
  dump += "\"position1\": " + std::to_string(msg.position1);
  dump += ",";
  dump += "\"code2\": " + std::to_string(msg.code2);
  dump += ",";
  dump += "\"controller2\": " + std::to_string(msg.controller2);
  dump += ",";
  dump += "\"location2\": " + std::to_string(msg.location2);
  dump += ",";
  dump += "\"sequence2\": " + std::to_string(msg.sequence2);
  dump += ",";
  dump += "\"position2\": " + std::to_string(msg.position2);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_FIELD_DISABLED(const CoreMsg_FIELD_DISABLED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_FIELD_DISABLED\", \"data\":";
  dump += "{";
  dump += "\"disabled_fields\": " + std::to_string(msg.disabled_fields);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SUMMONING(const CoreMsg_SUMMONING &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SUMMONING\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"position\": " + std::to_string(msg.position);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SUMMONED(const CoreMsg_SUMMONED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SUMMONED\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SPSUMMONING(const CoreMsg_SPSUMMONING &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SPSUMMONING\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"position\": " + std::to_string(msg.position);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_SPSUMMONED(const CoreMsg_SPSUMMONED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_SPSUMMONED\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_FLIPSUMMONING(const CoreMsg_FLIPSUMMONING &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_FLIPSUMMONING\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"position\": " + std::to_string(msg.position);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_FLIPSUMMONED(const CoreMsg_FLIPSUMMONED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_FLIPSUMMONED\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAINING(const CoreMsg_CHAINING &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAINING\", \"data\":";
  dump += "{";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += ",";
  dump += "\"previous_chain_controller\": " + std::to_string(msg.previous_chain_controller);
  dump += ",";
  dump += "\"previous_chain_location\": " + std::to_string(msg.previous_chain_location);
  dump += ",";
  dump += "\"previous_chain_sequence\": " + std::to_string(msg.previous_chain_sequence);
  dump += ",";
  dump += "\"subsequence\": " + std::to_string(msg.subsequence);
  dump += ",";
  dump += "\"chain_controller\": " + std::to_string(msg.chain_controller);
  dump += ",";
  dump += "\"chain_location\": " + std::to_string(msg.chain_location);
  dump += ",";
  dump += "\"chain_sequence\": " + std::to_string(msg.chain_sequence);
  dump += ",";
  dump += "\"desc\": " + std::to_string(msg.desc);
  dump += ",";
  dump += "\"chain_param\": " + std::to_string(msg.chain_param);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAINED(const CoreMsg_CHAINED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAINED\", \"data\":";
  dump += "{";
  dump += "\"chain_param\": " + std::to_string(msg.chain_param);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAIN_SOLVING(const CoreMsg_CHAIN_SOLVING &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAIN_SOLVING\", \"data\":";
  dump += "{";
  dump += "\"chain_param\": " + std::to_string(msg.chain_param);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAIN_SOLVED(const CoreMsg_CHAIN_SOLVED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAIN_SOLVED\", \"data\":";
  dump += "{";
  dump += "\"chain_param\": " + std::to_string(msg.chain_param);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAIN_END(const CoreMsg_CHAIN_END &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAIN_END\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAIN_NEGATED(const CoreMsg_CHAIN_NEGATED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAIN_NEGATED\", \"data\":";
  dump += "{";
  dump += "\"chain_param\": " + std::to_string(msg.chain_param);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CHAIN_DISABLED(const CoreMsg_CHAIN_DISABLED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CHAIN_DISABLED\", \"data\":";
  dump += "{";
  dump += "\"chain_param\": " + std::to_string(msg.chain_param);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CARD_SELECTED(const CoreMsg_CARD_SELECTED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CARD_SELECTED\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_RANDOM_SELECTED(const CoreMsg_RANDOM_SELECTED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_RANDOM_SELECTED\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_BECOME_TARGET(const CoreMsg_BECOME_TARGET &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_BECOME_TARGET\", \"data\":";
  dump += "{";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"controller\": " + std::to_string(dumping.controller);
    dump += ",";
    dump += "\"location\": " + std::to_string(dumping.location);
    dump += ",";
    dump += "\"sequence\": " + std::to_string(dumping.sequence);
    dump += ",";
    dump += "\"subsequence\": " + std::to_string(dumping.subsequence);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_DRAW(const CoreMsg_DRAW &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_DRAW\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"cards\": [";
  for (auto iter = msg.cards.begin(); iter != msg.cards.end(); ++iter) {
    if (iter != msg.cards.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"code\": " + std::to_string(dumping.code);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_DAMAGE(const CoreMsg_DAMAGE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_DAMAGE\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"value\": " + std::to_string(msg.value);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_RECOVER(const CoreMsg_RECOVER &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_RECOVER\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"value\": " + std::to_string(msg.value);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_LPUPDATE(const CoreMsg_LPUPDATE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_LPUPDATE\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"value\": " + std::to_string(msg.value);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_PAY_LPCOST(const CoreMsg_PAY_LPCOST &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_PAY_LPCOST\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"value\": " + std::to_string(msg.value);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_EQUIP(const CoreMsg_EQUIP &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_EQUIP\", \"data\":";
  dump += "{";
  dump += "\"controller1\": " + std::to_string(msg.controller1);
  dump += ",";
  dump += "\"location1\": " + std::to_string(msg.location1);
  dump += ",";
  dump += "\"sequence1\": " + std::to_string(msg.sequence1);
  dump += ",";
  dump += "\"ignore1\": " + std::to_string(msg.ignore1);
  dump += ",";
  dump += "\"controller2\": " + std::to_string(msg.controller2);
  dump += ",";
  dump += "\"location2\": " + std::to_string(msg.location2);
  dump += ",";
  dump += "\"sequence2\": " + std::to_string(msg.sequence2);
  dump += ",";
  dump += "\"ignore2\": " + std::to_string(msg.ignore2);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_UNEQUIP(const CoreMsg_UNEQUIP &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_UNEQUIP\", \"data\":";
  dump += "{";
  dump += "\"controller1\": " + std::to_string(msg.controller1);
  dump += ",";
  dump += "\"location1\": " + std::to_string(msg.location1);
  dump += ",";
  dump += "\"sequence1\": " + std::to_string(msg.sequence1);
  dump += ",";
  dump += "\"ignore1\": " + std::to_string(msg.ignore1);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CARD_TARGET(const CoreMsg_CARD_TARGET &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CARD_TARGET\", \"data\":";
  dump += "{";
  dump += "\"controller1\": " + std::to_string(msg.controller1);
  dump += ",";
  dump += "\"location1\": " + std::to_string(msg.location1);
  dump += ",";
  dump += "\"sequence1\": " + std::to_string(msg.sequence1);
  dump += ",";
  dump += "\"ignore1\": " + std::to_string(msg.ignore1);
  dump += ",";
  dump += "\"controller2\": " + std::to_string(msg.controller2);
  dump += ",";
  dump += "\"location2\": " + std::to_string(msg.location2);
  dump += ",";
  dump += "\"sequence2\": " + std::to_string(msg.sequence2);
  dump += ",";
  dump += "\"ignore2\": " + std::to_string(msg.ignore2);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CANCEL_TARGET(const CoreMsg_CANCEL_TARGET &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CANCEL_TARGET\", \"data\":";
  dump += "{";
  dump += "\"controller1\": " + std::to_string(msg.controller1);
  dump += ",";
  dump += "\"location1\": " + std::to_string(msg.location1);
  dump += ",";
  dump += "\"sequence1\": " + std::to_string(msg.sequence1);
  dump += ",";
  dump += "\"ignore1\": " + std::to_string(msg.ignore1);
  dump += ",";
  dump += "\"controller2\": " + std::to_string(msg.controller2);
  dump += ",";
  dump += "\"location2\": " + std::to_string(msg.location2);
  dump += ",";
  dump += "\"sequence2\": " + std::to_string(msg.sequence2);
  dump += ",";
  dump += "\"ignore2\": " + std::to_string(msg.ignore2);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ADD_COUNTER(const CoreMsg_ADD_COUNTER &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ADD_COUNTER\", \"data\":";
  dump += "{";
  dump += "\"type\": " + std::to_string(msg.type);
  dump += ",";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"count\": " + std::to_string(msg.count);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_REMOVE_COUNTER(const CoreMsg_REMOVE_COUNTER &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_REMOVE_COUNTER\", \"data\":";
  dump += "{";
  dump += "\"type\": " + std::to_string(msg.type);
  dump += ",";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"count\": " + std::to_string(msg.count);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ATTACK(const CoreMsg_ATTACK &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ATTACK\", \"data\":";
  dump += "{";
  dump += "\"atk_controller\": " + std::to_string(msg.atk_controller);
  dump += ",";
  dump += "\"atk_location\": " + std::to_string(msg.atk_location);
  dump += ",";
  dump += "\"atk_sequence\": " + std::to_string(msg.atk_sequence);
  dump += ",";
  dump += "\"atk_ignore\": " + std::to_string(msg.atk_ignore);
  dump += ",";
  dump += "\"def_controller\": " + std::to_string(msg.def_controller);
  dump += ",";
  dump += "\"def_location\": " + std::to_string(msg.def_location);
  dump += ",";
  dump += "\"def_sequence\": " + std::to_string(msg.def_sequence);
  dump += ",";
  dump += "\"def_ignore\": " + std::to_string(msg.def_ignore);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_BATTLE(const CoreMsg_BATTLE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_BATTLE\", \"data\":";
  dump += "{";
  dump += "\"atk_controller\": " + std::to_string(msg.atk_controller);
  dump += ",";
  dump += "\"atk_location\": " + std::to_string(msg.atk_location);
  dump += ",";
  dump += "\"atk_sequence\": " + std::to_string(msg.atk_sequence);
  dump += ",";
  dump += "\"atk_subsequence\": " + std::to_string(msg.atk_subsequence);
  dump += ",";
  dump += "\"atk_atkvalue\": " + std::to_string(msg.atk_atkvalue);
  dump += ",";
  dump += "\"atk_defvalue\": " + std::to_string(msg.atk_defvalue);
  dump += ",";
  dump += "\"atk_ignore\": " + std::to_string(msg.atk_ignore);
  dump += ",";
  dump += "\"def_controller\": " + std::to_string(msg.def_controller);
  dump += ",";
  dump += "\"def_location\": " + std::to_string(msg.def_location);
  dump += ",";
  dump += "\"def_sequence\": " + std::to_string(msg.def_sequence);
  dump += ",";
  dump += "\"def_subsequence\": " + std::to_string(msg.def_subsequence);
  dump += ",";
  dump += "\"def_atkvalue\": " + std::to_string(msg.def_atkvalue);
  dump += ",";
  dump += "\"def_defvalue\": " + std::to_string(msg.def_defvalue);
  dump += ",";
  dump += "\"def_ignore\": " + std::to_string(msg.def_ignore);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ATTACK_DISABLED(const CoreMsg_ATTACK_DISABLED &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ATTACK_DISABLED\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_DAMAGE_STEP_START(const CoreMsg_DAMAGE_STEP_START &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_DAMAGE_STEP_START\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_DAMAGE_STEP_END(const CoreMsg_DAMAGE_STEP_END &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_DAMAGE_STEP_END\", \"data\":";
  dump += "{";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_MISSED_EFFECT(const CoreMsg_MISSED_EFFECT &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_MISSED_EFFECT\", \"data\":";
  dump += "{";
  dump += "\"ignore\": " + std::to_string(msg.ignore);
  dump += ",";
  dump += "\"code\": " + std::to_string(msg.code);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_TOSS_COIN(const CoreMsg_TOSS_COIN &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_TOSS_COIN\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"count\": [";
  for (auto iter = msg.count.begin(); iter != msg.count.end(); ++iter) {
    if (iter != msg.count.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"value\": " + std::to_string(dumping.value);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_TOSS_DICE(const CoreMsg_TOSS_DICE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_TOSS_DICE\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"count\": [";
  for (auto iter = msg.count.begin(); iter != msg.count.end(); ++iter) {
    if (iter != msg.count.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"value\": " + std::to_string(dumping.value);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ROCK_PAPER_SCISSORS(const CoreMsg_ROCK_PAPER_SCISSORS &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ROCK_PAPER_SCISSORS\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_HAND_RES(const CoreMsg_HAND_RES &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_HAND_RES\", \"data\":";
  dump += "{";
  dump += "\"res\": " + std::to_string(msg.res);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ANNOUNCE_RACE(const CoreMsg_ANNOUNCE_RACE &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ANNOUNCE_RACE\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"count\": " + std::to_string(msg.count);
  dump += ",";
  dump += "\"available\": " + std::to_string(msg.available);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ANNOUNCE_ATTRIB(const CoreMsg_ANNOUNCE_ATTRIB &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ANNOUNCE_ATTRIB\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"count\": " + std::to_string(msg.count);
  dump += ",";
  dump += "\"available\": " + std::to_string(msg.available);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ANNOUNCE_CARD(const CoreMsg_ANNOUNCE_CARD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ANNOUNCE_CARD\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"declarable_type\": " + std::to_string(msg.declarable_type);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ANNOUNCE_NUMBER(const CoreMsg_ANNOUNCE_NUMBER &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ANNOUNCE_NUMBER\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"count\": [";
  for (auto iter = msg.count.begin(); iter != msg.count.end(); ++iter) {
    if (iter != msg.count.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"value\": " + std::to_string(dumping.value);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_ANNOUNCE_CARD_FILTER(const CoreMsg_ANNOUNCE_CARD_FILTER &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_ANNOUNCE_CARD_FILTER\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"filters\": [";
  for (auto iter = msg.filters.begin(); iter != msg.filters.end(); ++iter) {
    if (iter != msg.filters.begin()) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"opcode\": " + std::to_string(dumping.opcode);
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_CARD_HINT(const CoreMsg_CARD_HINT &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_CARD_HINT\", \"data\":";
  dump += "{";
  dump += "\"controller\": " + std::to_string(msg.controller);
  dump += ",";
  dump += "\"location\": " + std::to_string(msg.location);
  dump += ",";
  dump += "\"sequence\": " + std::to_string(msg.sequence);
  dump += ",";
  dump += "\"ignore\": " + std::to_string(msg.ignore);
  dump += ",";
  dump += "\"chtype\": " + std::to_string(msg.chtype);
  dump += ",";
  dump += "\"value\": " + std::to_string(msg.value);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_PLAYER_HINT(const CoreMsg_PLAYER_HINT &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_PLAYER_HINT\", \"data\":";
  dump += "{";
  dump += "\"player\": " + std::to_string(msg.player);
  dump += ",";
  dump += "\"chtype\": " + std::to_string(msg.chtype);
  dump += ",";
  dump += "\"value\": " + std::to_string(msg.value);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_MATCH_KILL(const CoreMsg_MATCH_KILL &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_MATCH_KILL\", \"data\":";
  dump += "{";
  dump += "\"match_kill\": " + std::to_string(msg.match_kill);
  dump += "}";

  dump += "}";
  return dump;
}


std::string
dump_json_CoreMsg_RELOAD_FIELD(const CoreMsg_RELOAD_FIELD &msg) {
  (void)msg;
  std::string dump;
  dump += "{ \"type\": \"MSG_RELOAD_FIELD\", \"data\":";
  dump += "{";
  dump += "\"duel_rule\": " + std::to_string(msg.duel_rule);
  dump += ",";
  dump += "\"players\": [";
  for (auto iter = std::begin(msg.players); iter != std::end(msg.players); ++iter) {
    if (iter != std::begin(msg.players)) dump += ",";
    const auto dumping = *iter;
    dump += "{";
    dump += "\"lp\": " + std::to_string(dumping.lp);
    dump += ",";
    dump += "\"mzone_cards\": [";
    for (auto iter = std::begin(dumping.mzone_cards); iter != std::end(dumping.mzone_cards); ++iter) {
      if (iter != std::begin(dumping.mzone_cards)) dump += ",";
      const auto dumping = *iter;
      dump += "{";
      dump += "\"value\": ";
      if (dumping.value) {
        const auto some = *(dumping.value);
        dump += "{";
        dump += "\"position\": " + std::to_string(some.position);
        dump += ",";
        dump += "\"xyz_count\": " + std::to_string(some.xyz_count);
        dump += "}";
      } else {
        dump += "null";
      }
      dump += "}";
    }
    dump += "]";
    dump += ",";
    dump += "\"cards\": [";
    for (auto iter = std::begin(dumping.cards); iter != std::end(dumping.cards); ++iter) {
      if (iter != std::begin(dumping.cards)) dump += ",";
      const auto dumping = *iter;
      dump += "{";
      dump += "\"value\": ";
      if (dumping.value) {
        const auto some = *(dumping.value);
        dump += "{";
        dump += "\"position\": " + std::to_string(some.position);
        dump += "}";
      } else {
        dump += "null";
      }
      dump += "}";
    }
    dump += "]";
    dump += ",";
    dump += "\"deck_count\": " + std::to_string(dumping.deck_count);
    dump += ",";
    dump += "\"hand_count\": " + std::to_string(dumping.hand_count);
    dump += ",";
    dump += "\"grave_count\": " + std::to_string(dumping.grave_count);
    dump += ",";
    dump += "\"banish_count\": " + std::to_string(dumping.banish_count);
    dump += ",";
    dump += "\"extra_count\": " + std::to_string(dumping.extra_count);
    dump += ",";
    dump += "\"extra_pendu_count\": " + std::to_string(dumping.extra_pendu_count);
    dump += ",";
    dump += "\"chains\": [";
    for (auto iter = dumping.chains.begin(); iter != dumping.chains.end(); ++iter) {
      if (iter != dumping.chains.begin()) dump += ",";
      const auto dumping = *iter;
      dump += "{";
      dump += "\"code\": " + std::to_string(dumping.code);
      dump += ",";
      dump += "\"previous_controller\": " + std::to_string(dumping.previous_controller);
      dump += ",";
      dump += "\"previous_location\": " + std::to_string(dumping.previous_location);
      dump += ",";
      dump += "\"previous_sequence\": " + std::to_string(dumping.previous_sequence);
      dump += ",";
      dump += "\"previous_subsequence\": " + std::to_string(dumping.previous_subsequence);
      dump += ",";
      dump += "\"current_controller\": " + std::to_string(dumping.current_controller);
      dump += ",";
      dump += "\"current_location\": " + std::to_string(dumping.current_location);
      dump += ",";
      dump += "\"current_sequence\": " + std::to_string(dumping.current_sequence);
      dump += ",";
      dump += "\"desc\": " + std::to_string(dumping.desc);
      dump += "}";
    }
    dump += "]";
    dump += "}";
  }
  dump += "]";
  dump += "}";

  dump += "}";
  return dump;
}

