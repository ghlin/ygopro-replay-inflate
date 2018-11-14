switch (msg_type) {
  case MSG_RETRY: {
    return { unpack_CoreMsg_RETRY(in, end) };
  }
  case MSG_HINT: {
    return { unpack_CoreMsg_HINT(in, end) };
  }
  case MSG_WIN: {
    return { unpack_CoreMsg_WIN(in, end) };
  }
  case MSG_WAITING: {
    return { unpack_CoreMsg_WAITING(in, end) };
  }
  case MSG_START: {
    return { unpack_CoreMsg_START(in, end) };
  }
  case MSG_SELECT_BATTLECMD: {
    return { unpack_CoreMsg_SELECT_BATTLECMD(in, end) };
  }
  case MSG_SELECT_IDLECMD: {
    return { unpack_CoreMsg_SELECT_IDLECMD(in, end) };
  }
  case MSG_SELECT_EFFECTYN: {
    return { unpack_CoreMsg_SELECT_EFFECTYN(in, end) };
  }
  case MSG_SELECT_YESNO: {
    return { unpack_CoreMsg_SELECT_YESNO(in, end) };
  }
  case MSG_SELECT_OPTION: {
    return { unpack_CoreMsg_SELECT_OPTION(in, end) };
  }
  case MSG_SELECT_CARD: {
    return { unpack_CoreMsg_SELECT_CARD(in, end) };
  }
  case MSG_SELECT_UNSELECT_CARD: {
    return { unpack_CoreMsg_SELECT_UNSELECT_CARD(in, end) };
  }
  case MSG_SELECT_CHAIN: {
    return { unpack_CoreMsg_SELECT_CHAIN(in, end) };
  }
  case MSG_SELECT_PLACE: {
    return { unpack_CoreMsg_SELECT_PLACE(in, end) };
  }
  case MSG_SELECT_DISFIELD: {
    return { unpack_CoreMsg_SELECT_DISFIELD(in, end) };
  }
  case MSG_SELECT_POSITION: {
    return { unpack_CoreMsg_SELECT_POSITION(in, end) };
  }
  case MSG_SELECT_TRIBUTE: {
    return { unpack_CoreMsg_SELECT_TRIBUTE(in, end) };
  }
  case MSG_SELECT_COUNTER: {
    return { unpack_CoreMsg_SELECT_COUNTER(in, end) };
  }
  case MSG_SELECT_SUM: {
    return { unpack_CoreMsg_SELECT_SUM(in, end) };
  }
  case MSG_SORT_CARD: {
    return { unpack_CoreMsg_SORT_CARD(in, end) };
  }
  case MSG_SORT_CHAIN: {
    return { unpack_CoreMsg_SORT_CHAIN(in, end) };
  }
  case MSG_CONFIRM_DECKTOP: {
    return { unpack_CoreMsg_CONFIRM_DECKTOP(in, end) };
  }
  case MSG_CONFIRM_EXTRATOP: {
    return { unpack_CoreMsg_CONFIRM_EXTRATOP(in, end) };
  }
  case MSG_CONFIRM_CARDS: {
    return { unpack_CoreMsg_CONFIRM_CARDS(in, end) };
  }
  case MSG_SHUFFLE_DECK: {
    return { unpack_CoreMsg_SHUFFLE_DECK(in, end) };
  }
  case MSG_REFRESH_DECK: {
    return { unpack_CoreMsg_REFRESH_DECK(in, end) };
  }
  case MSG_SWAP_GRAVE_DECK: {
    return { unpack_CoreMsg_SWAP_GRAVE_DECK(in, end) };
  }
  case MSG_SHUFFLE_SET_CARD: {
    return { unpack_CoreMsg_SHUFFLE_SET_CARD(in, end) };
  }
  case MSG_SHUFFLE_HAND: {
    return { unpack_CoreMsg_SHUFFLE_HAND(in, end) };
  }
  case MSG_SHUFFLE_EXTRA: {
    return { unpack_CoreMsg_SHUFFLE_EXTRA(in, end) };
  }
  case MSG_REVERSE_DECK: {
    return { unpack_CoreMsg_REVERSE_DECK(in, end) };
  }
  case MSG_DECK_TOP: {
    return { unpack_CoreMsg_DECK_TOP(in, end) };
  }
  case MSG_NEW_TURN: {
    return { unpack_CoreMsg_NEW_TURN(in, end) };
  }
  case MSG_NEW_PHASE: {
    return { unpack_CoreMsg_NEW_PHASE(in, end) };
  }
  case MSG_MOVE: {
    return { unpack_CoreMsg_MOVE(in, end) };
  }
  case MSG_POS_CHANGE: {
    return { unpack_CoreMsg_POS_CHANGE(in, end) };
  }
  case MSG_SET: {
    return { unpack_CoreMsg_SET(in, end) };
  }
  case MSG_SWAP: {
    return { unpack_CoreMsg_SWAP(in, end) };
  }
  case MSG_FIELD_DISABLED: {
    return { unpack_CoreMsg_FIELD_DISABLED(in, end) };
  }
  case MSG_SUMMONING: {
    return { unpack_CoreMsg_SUMMONING(in, end) };
  }
  case MSG_SUMMONED: {
    return { unpack_CoreMsg_SUMMONED(in, end) };
  }
  case MSG_SPSUMMONING: {
    return { unpack_CoreMsg_SPSUMMONING(in, end) };
  }
  case MSG_SPSUMMONED: {
    return { unpack_CoreMsg_SPSUMMONED(in, end) };
  }
  case MSG_FLIPSUMMONING: {
    return { unpack_CoreMsg_FLIPSUMMONING(in, end) };
  }
  case MSG_FLIPSUMMONED: {
    return { unpack_CoreMsg_FLIPSUMMONED(in, end) };
  }
  case MSG_CHAINING: {
    return { unpack_CoreMsg_CHAINING(in, end) };
  }
  case MSG_CHAINED: {
    return { unpack_CoreMsg_CHAINED(in, end) };
  }
  case MSG_CHAIN_SOLVING: {
    return { unpack_CoreMsg_CHAIN_SOLVING(in, end) };
  }
  case MSG_CHAIN_SOLVED: {
    return { unpack_CoreMsg_CHAIN_SOLVED(in, end) };
  }
  case MSG_CHAIN_END: {
    return { unpack_CoreMsg_CHAIN_END(in, end) };
  }
  case MSG_CHAIN_NEGATED: {
    return { unpack_CoreMsg_CHAIN_NEGATED(in, end) };
  }
  case MSG_CHAIN_DISABLED: {
    return { unpack_CoreMsg_CHAIN_DISABLED(in, end) };
  }
  case MSG_CARD_SELECTED: {
    return { unpack_CoreMsg_CARD_SELECTED(in, end) };
  }
  case MSG_RANDOM_SELECTED: {
    return { unpack_CoreMsg_RANDOM_SELECTED(in, end) };
  }
  case MSG_BECOME_TARGET: {
    return { unpack_CoreMsg_BECOME_TARGET(in, end) };
  }
  case MSG_DRAW: {
    return { unpack_CoreMsg_DRAW(in, end) };
  }
  case MSG_DAMAGE: {
    return { unpack_CoreMsg_DAMAGE(in, end) };
  }
  case MSG_RECOVER: {
    return { unpack_CoreMsg_RECOVER(in, end) };
  }
  case MSG_LPUPDATE: {
    return { unpack_CoreMsg_LPUPDATE(in, end) };
  }
  case MSG_PAY_LPCOST: {
    return { unpack_CoreMsg_PAY_LPCOST(in, end) };
  }
  case MSG_EQUIP: {
    return { unpack_CoreMsg_EQUIP(in, end) };
  }
  case MSG_UNEQUIP: {
    return { unpack_CoreMsg_UNEQUIP(in, end) };
  }
  case MSG_CARD_TARGET: {
    return { unpack_CoreMsg_CARD_TARGET(in, end) };
  }
  case MSG_CANCEL_TARGET: {
    return { unpack_CoreMsg_CANCEL_TARGET(in, end) };
  }
  case MSG_ADD_COUNTER: {
    return { unpack_CoreMsg_ADD_COUNTER(in, end) };
  }
  case MSG_REMOVE_COUNTER: {
    return { unpack_CoreMsg_REMOVE_COUNTER(in, end) };
  }
  case MSG_ATTACK: {
    return { unpack_CoreMsg_ATTACK(in, end) };
  }
  case MSG_BATTLE: {
    return { unpack_CoreMsg_BATTLE(in, end) };
  }
  case MSG_ATTACK_DISABLED: {
    return { unpack_CoreMsg_ATTACK_DISABLED(in, end) };
  }
  case MSG_DAMAGE_STEP_START: {
    return { unpack_CoreMsg_DAMAGE_STEP_START(in, end) };
  }
  case MSG_DAMAGE_STEP_END: {
    return { unpack_CoreMsg_DAMAGE_STEP_END(in, end) };
  }
  case MSG_MISSED_EFFECT: {
    return { unpack_CoreMsg_MISSED_EFFECT(in, end) };
  }
  case MSG_TOSS_COIN: {
    return { unpack_CoreMsg_TOSS_COIN(in, end) };
  }
  case MSG_TOSS_DICE: {
    return { unpack_CoreMsg_TOSS_DICE(in, end) };
  }
  case MSG_ROCK_PAPER_SCISSORS: {
    return { unpack_CoreMsg_ROCK_PAPER_SCISSORS(in, end) };
  }
  case MSG_HAND_RES: {
    return { unpack_CoreMsg_HAND_RES(in, end) };
  }
  case MSG_ANNOUNCE_RACE: {
    return { unpack_CoreMsg_ANNOUNCE_RACE(in, end) };
  }
  case MSG_ANNOUNCE_ATTRIB: {
    return { unpack_CoreMsg_ANNOUNCE_ATTRIB(in, end) };
  }
  case MSG_ANNOUNCE_CARD: {
    return { unpack_CoreMsg_ANNOUNCE_CARD(in, end) };
  }
  case MSG_ANNOUNCE_NUMBER: {
    return { unpack_CoreMsg_ANNOUNCE_NUMBER(in, end) };
  }
  case MSG_ANNOUNCE_CARD_FILTER: {
    return { unpack_CoreMsg_ANNOUNCE_CARD_FILTER(in, end) };
  }
  case MSG_CARD_HINT: {
    return { unpack_CoreMsg_CARD_HINT(in, end) };
  }
  case MSG_PLAYER_HINT: {
    return { unpack_CoreMsg_PLAYER_HINT(in, end) };
  }
  case MSG_MATCH_KILL: {
    return { unpack_CoreMsg_MATCH_KILL(in, end) };
  }
  case MSG_RELOAD_FIELD: {
    return { unpack_CoreMsg_RELOAD_FIELD(in, end) };
  }

  default: {
    HANDLE_UNKNOWN_MSG
  }
}