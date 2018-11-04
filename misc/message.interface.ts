type MSG_RETRY = 'MSG_RETRY';
type MSG_HINT = 'MSG_HINT';
type MSG_WIN = 'MSG_WIN';
type MSG_WAITING = 'MSG_WAITING';
type MSG_START = 'MSG_START';
type MSG_SELECT_BATTLECMD = 'MSG_SELECT_BATTLECMD';
type MSG_SELECT_IDLECMD = 'MSG_SELECT_IDLECMD';
type MSG_SELECT_EFFECTYN = 'MSG_SELECT_EFFECTYN';
type MSG_SELECT_YESNO = 'MSG_SELECT_YESNO';
type MSG_SELECT_OPTION = 'MSG_SELECT_OPTION';
type MSG_SELECT_CARD = 'MSG_SELECT_CARD';
type MSG_SELECT_UNSELECT_CARD = 'MSG_SELECT_UNSELECT_CARD';
type MSG_SELECT_CHAIN = 'MSG_SELECT_CHAIN';
type MSG_SELECT_PLACE = 'MSG_SELECT_PLACE';
type MSG_SELECT_DISFIELD = 'MSG_SELECT_DISFIELD';
type MSG_SELECT_POSITION = 'MSG_SELECT_POSITION';
type MSG_SELECT_TRIBUTE = 'MSG_SELECT_TRIBUTE';
type MSG_SELECT_COUNTER = 'MSG_SELECT_COUNTER';
type MSG_SELECT_SUM = 'MSG_SELECT_SUM';
type MSG_SORT_CARD = 'MSG_SORT_CARD';
type MSG_SORT_CHAIN = 'MSG_SORT_CHAIN';
type MSG_CONFIRM_DECKTOP = 'MSG_CONFIRM_DECKTOP';
type MSG_CONFIRM_EXTRATOP = 'MSG_CONFIRM_EXTRATOP';
type MSG_CONFIRM_CARDS = 'MSG_CONFIRM_CARDS';
type MSG_SHUFFLE_DECK = 'MSG_SHUFFLE_DECK';
type MSG_REFRESH_DECK = 'MSG_REFRESH_DECK';
type MSG_SWAP_GRAVE_DECK = 'MSG_SWAP_GRAVE_DECK';
type MSG_SHUFFLE_SET_CARD = 'MSG_SHUFFLE_SET_CARD';
type MSG_SHUFFLE_HAND = 'MSG_SHUFFLE_HAND';
type MSG_SHUFFLE_EXTRA = 'MSG_SHUFFLE_EXTRA';
type MSG_REVERSE_DECK = 'MSG_REVERSE_DECK';
type MSG_DECK_TOP = 'MSG_DECK_TOP';
type MSG_NEW_TURN = 'MSG_NEW_TURN';
type MSG_NEW_PHASE = 'MSG_NEW_PHASE';
type MSG_MOVE = 'MSG_MOVE';
type MSG_POS_CHANGE = 'MSG_POS_CHANGE';
type MSG_SET = 'MSG_SET';
type MSG_SWAP = 'MSG_SWAP';
type MSG_FIELD_DISABLED = 'MSG_FIELD_DISABLED';
type MSG_SUMMONING = 'MSG_SUMMONING';
type MSG_SUMMONED = 'MSG_SUMMONED';
type MSG_SPSUMMONING = 'MSG_SPSUMMONING';
type MSG_SPSUMMONED = 'MSG_SPSUMMONED';
type MSG_FLIPSUMMONING = 'MSG_FLIPSUMMONING';
type MSG_FLIPSUMMONED = 'MSG_FLIPSUMMONED';
type MSG_CHAINING = 'MSG_CHAINING';
type MSG_CHAINED = 'MSG_CHAINED';
type MSG_CHAIN_SOLVING = 'MSG_CHAIN_SOLVING';
type MSG_CHAIN_SOLVED = 'MSG_CHAIN_SOLVED';
type MSG_CHAIN_END = 'MSG_CHAIN_END';
type MSG_CHAIN_NEGATED = 'MSG_CHAIN_NEGATED';
type MSG_CHAIN_DISABLED = 'MSG_CHAIN_DISABLED';
type MSG_CARD_SELECTED = 'MSG_CARD_SELECTED';
type MSG_RANDOM_SELECTED = 'MSG_RANDOM_SELECTED';
type MSG_BECOME_TARGET = 'MSG_BECOME_TARGET';
type MSG_DRAW = 'MSG_DRAW';
type MSG_DAMAGE = 'MSG_DAMAGE';
type MSG_RECOVER = 'MSG_RECOVER';
type MSG_LPUPDATE = 'MSG_LPUPDATE';
type MSG_PAY_LPCOST = 'MSG_PAY_LPCOST';
type MSG_EQUIP = 'MSG_EQUIP';
type MSG_UNEQUIP = 'MSG_UNEQUIP';
type MSG_CARD_TARGET = 'MSG_CARD_TARGET';
type MSG_CANCEL_TARGET = 'MSG_CANCEL_TARGET';
type MSG_ADD_COUNTER = 'MSG_ADD_COUNTER';
type MSG_REMOVE_COUNTER = 'MSG_REMOVE_COUNTER';
type MSG_ATTACK = 'MSG_ATTACK';
type MSG_BATTLE = 'MSG_BATTLE';
type MSG_ATTACK_DISABLED = 'MSG_ATTACK_DISABLED';
type MSG_DAMAGE_STEP_START = 'MSG_DAMAGE_STEP_START';
type MSG_DAMAGE_STEP_END = 'MSG_DAMAGE_STEP_END';
type MSG_MISSED_EFFECT = 'MSG_MISSED_EFFECT';
type MSG_TOSS_COIN = 'MSG_TOSS_COIN';
type MSG_TOSS_DICE = 'MSG_TOSS_DICE';
type MSG_ROCK_PAPER_SCISSORS = 'MSG_ROCK_PAPER_SCISSORS';
type MSG_HAND_RES = 'MSG_HAND_RES';
type MSG_ANNOUNCE_RACE = 'MSG_ANNOUNCE_RACE';
type MSG_ANNOUNCE_ATTRIB = 'MSG_ANNOUNCE_ATTRIB';
type MSG_ANNOUNCE_CARD = 'MSG_ANNOUNCE_CARD';
type MSG_ANNOUNCE_NUMBER = 'MSG_ANNOUNCE_NUMBER';
type MSG_ANNOUNCE_CARD_FILTER = 'MSG_ANNOUNCE_CARD_FILTER';
type MSG_CARD_HINT = 'MSG_CARD_HINT';
type MSG_PLAYER_HINT = 'MSG_PLAYER_HINT';
type MSG_MATCH_KILL = 'MSG_MATCH_KILL';
type MSG_RELOAD_FIELD = 'MSG_RELOAD_FIELD';

type MSG_TYPE =
    MSG_RETRY
  | MSG_HINT
  | MSG_WIN
  | MSG_WAITING
  | MSG_START
  | MSG_SELECT_BATTLECMD
  | MSG_SELECT_IDLECMD
  | MSG_SELECT_EFFECTYN
  | MSG_SELECT_YESNO
  | MSG_SELECT_OPTION
  | MSG_SELECT_CARD
  | MSG_SELECT_UNSELECT_CARD
  | MSG_SELECT_CHAIN
  | MSG_SELECT_PLACE
  | MSG_SELECT_DISFIELD
  | MSG_SELECT_POSITION
  | MSG_SELECT_TRIBUTE
  | MSG_SELECT_COUNTER
  | MSG_SELECT_SUM
  | MSG_SORT_CARD
  | MSG_SORT_CHAIN
  | MSG_CONFIRM_DECKTOP
  | MSG_CONFIRM_EXTRATOP
  | MSG_CONFIRM_CARDS
  | MSG_SHUFFLE_DECK
  | MSG_REFRESH_DECK
  | MSG_SWAP_GRAVE_DECK
  | MSG_SHUFFLE_SET_CARD
  | MSG_SHUFFLE_HAND
  | MSG_SHUFFLE_EXTRA
  | MSG_REVERSE_DECK
  | MSG_DECK_TOP
  | MSG_NEW_TURN
  | MSG_NEW_PHASE
  | MSG_MOVE
  | MSG_POS_CHANGE
  | MSG_SET
  | MSG_SWAP
  | MSG_FIELD_DISABLED
  | MSG_SUMMONING
  | MSG_SUMMONED
  | MSG_SPSUMMONING
  | MSG_SPSUMMONED
  | MSG_FLIPSUMMONING
  | MSG_FLIPSUMMONED
  | MSG_CHAINING
  | MSG_CHAINED
  | MSG_CHAIN_SOLVING
  | MSG_CHAIN_SOLVED
  | MSG_CHAIN_END
  | MSG_CHAIN_NEGATED
  | MSG_CHAIN_DISABLED
  | MSG_CARD_SELECTED
  | MSG_RANDOM_SELECTED
  | MSG_BECOME_TARGET
  | MSG_DRAW
  | MSG_DAMAGE
  | MSG_RECOVER
  | MSG_LPUPDATE
  | MSG_PAY_LPCOST
  | MSG_EQUIP
  | MSG_UNEQUIP
  | MSG_CARD_TARGET
  | MSG_CANCEL_TARGET
  | MSG_ADD_COUNTER
  | MSG_REMOVE_COUNTER
  | MSG_ATTACK
  | MSG_BATTLE
  | MSG_ATTACK_DISABLED
  | MSG_DAMAGE_STEP_START
  | MSG_DAMAGE_STEP_END
  | MSG_MISSED_EFFECT
  | MSG_TOSS_COIN
  | MSG_TOSS_DICE
  | MSG_ROCK_PAPER_SCISSORS
  | MSG_HAND_RES
  | MSG_ANNOUNCE_RACE
  | MSG_ANNOUNCE_ATTRIB
  | MSG_ANNOUNCE_CARD
  | MSG_ANNOUNCE_NUMBER
  | MSG_ANNOUNCE_CARD_FILTER
  | MSG_CARD_HINT
  | MSG_PLAYER_HINT
  | MSG_MATCH_KILL
  | MSG_RELOAD_FIELD;

interface IMSG_RETRY {
  type: 'MSG_RETRY';
  data: { }
}


interface IMSG_HINT {
  type: 'MSG_HINT';
  data: {
    type: number;
    player: number;
    data: number;
  }
}


interface IMSG_WIN {
  type: 'MSG_WIN';
  data: {
    player: number;
    type: number;
  }
}


interface IMSG_WAITING {
  type: 'MSG_WAITING';
  data: { }
}


interface IMSG_START {
  type: 'MSG_START';
  data: {
    player_type: number;
    player0_lp: number;
    player1_lp: number;
    player0_deck_count: number;
    player0_extra_count: number;
    player1_deck_count: number;
    player1_extra_count: number;
  }
}


interface IMSG_SELECT_BATTLECMD {
  type: 'MSG_SELECT_BATTLECMD';
  data: {
    player: number;
    candidates1: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      description: number;
    }[];
    candidates2: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
    }[];
    to_main2_phase: number;
    to_end_phase: number;
  }
}


interface IMSG_SELECT_IDLECMD {
  type: 'MSG_SELECT_IDLECMD';
  data: {
    player: number;
    summon_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
    spsummon_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
    reposition_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
    mset_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
    sset_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
    active_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      desc: number;
    }[];
    to_battle_phase: number;
    to_end_phase: number;
    can_shuffle: number;
  }
}


interface IMSG_SELECT_EFFECTYN {
  type: 'MSG_SELECT_EFFECTYN';
  data: {
    player: number;
    code: number;
    controller: number;
    location: number;
    sequence: number;
    _ignore_: number;
    desc: number;
  }
}


interface IMSG_SELECT_YESNO {
  type: 'MSG_SELECT_YESNO';
  data: {
    player: number;
    desc: number;
  }
}


interface IMSG_SELECT_OPTION {
  type: 'MSG_SELECT_OPTION';
  data: {
    player: number;
    candidates: {
      option_id: number;
    }[];
  }
}


interface IMSG_SELECT_CARD {
  type: 'MSG_SELECT_CARD';
  data: {
    player: number;
    cancelable: number;
    select_min: number;
    select_max: number;
    candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
    }[];
  }
}


interface IMSG_SELECT_UNSELECT_CARD {
  type: 'MSG_SELECT_UNSELECT_CARD';
  data: {
    player: number;
    finishable: number;
    cancelable: number;
    select_min: number;
    select_max: number;
    candidates1: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
    }[];
    candidates2: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
    }[];
  }
}


interface IMSG_SELECT_CHAIN {
  type: 'MSG_SELECT_CHAIN';
  data: {
    player: number;
    spe_count: number;
    forced: number;
    hint0: number;
    hint1: number;
    candidates: {
      flag: number;
      code: number;
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
      desc: number;
    }[];
  }
}


interface IMSG_SELECT_PLACE {
  type: 'MSG_SELECT_PLACE';
  data: {
    player: number;
    select_min: number;
    selectable_field: number;
  }
}


interface IMSG_SELECT_DISFIELD {
  type: 'MSG_SELECT_DISFIELD';
  data: {
    player: number;
    select_min: number;
    selectable_field: number;
  }
}


interface IMSG_SELECT_POSITION {
  type: 'MSG_SELECT_POSITION';
  data: {
    player: number;
    code: number;
    positions: number;
  }
}


interface IMSG_SELECT_TRIBUTE {
  type: 'MSG_SELECT_TRIBUTE';
  data: {
    player: number;
    cancelable: number;
    select_min: number;
    select_max: number;
    candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      operation_param: number;
    }[];
  }
}


interface IMSG_SELECT_COUNTER {
  type: 'MSG_SELECT_COUNTER';
  data: {
    player: number;
    select_counter_type: number;
    select_counter_count: number;
    candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      operation_param: number;
    }[];
  }
}


interface IMSG_SELECT_SUM {
  type: 'MSG_SELECT_SUM';
  data: {
    select_mode: number;
    player: number;
    select_sumval: number;
    select_min: number;
    select_max: number;
    must_select_candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      operation_param: number;
    }[];
    candidates: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
      operation_param: number;
    }[];
  }
}


interface IMSG_SORT_CARD {
  type: 'MSG_SORT_CARD';
  data: {
    player: number;
    cards: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
  }
}


interface IMSG_SORT_CHAIN {
  type: 'MSG_SORT_CHAIN';
  data: {
    player: number;
    cards: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
  }
}


interface IMSG_CONFIRM_DECKTOP {
  type: 'MSG_CONFIRM_DECKTOP';
  data: {
    player: number;
    cards: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
  }
}


interface IMSG_CONFIRM_EXTRATOP {
  type: 'MSG_CONFIRM_EXTRATOP';
  data: {
    player: number;
    cards: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
  }
}


interface IMSG_CONFIRM_CARDS {
  type: 'MSG_CONFIRM_CARDS';
  data: {
    player: number;
    cards: {
      code: number;
      controller: number;
      location: number;
      sequence: number;
    }[];
  }
}


interface IMSG_SHUFFLE_DECK {
  type: 'MSG_SHUFFLE_DECK';
  data: {
    player: number;
  }
}


interface IMSG_REFRESH_DECK {
  type: 'MSG_REFRESH_DECK';
  data: {
    player: number;
  }
}


interface IMSG_SWAP_GRAVE_DECK {
  type: 'MSG_SWAP_GRAVE_DECK';
  data: {
    player: number;
  }
}


interface IMSG_SHUFFLE_SET_CARD {
  type: 'MSG_SHUFFLE_SET_CARD';
  data: {
    location: number;
    cards1: {
      controller: number;
      location: number;
      sequence: number;
      ignore: number;
    }[];
    cards2: {
      controller: number;
      location: number;
      sequence: number;
      ignore: number;
    }[];
  }
}


interface IMSG_SHUFFLE_HAND {
  type: 'MSG_SHUFFLE_HAND';
  data: {
    player: number;
    cards: {
      code: number;
    }[];
  }
}


interface IMSG_SHUFFLE_EXTRA {
  type: 'MSG_SHUFFLE_EXTRA';
  data: {
    player: number;
    cards: {
      code: number;
    }[];
  }
}


interface IMSG_REVERSE_DECK {
  type: 'MSG_REVERSE_DECK';
  data: { }
}


interface IMSG_DECK_TOP {
  type: 'MSG_DECK_TOP';
  data: {
    player: number;
    sequence: number;
    code: number;
  }
}


interface IMSG_NEW_TURN {
  type: 'MSG_NEW_TURN';
  data: {
    player: number;
  }
}


interface IMSG_NEW_PHASE {
  type: 'MSG_NEW_PHASE';
  data: {
    phase: number;
  }
}


interface IMSG_MOVE {
  type: 'MSG_MOVE';
  data: {
    code: number;
    previous_controller: number;
    previous_location: number;
    previous_sequence: number;
    previous_position: number;
    current_controller: number;
    current_location: number;
    current_sequence: number;
    current_position: number;
    reason: number;
  }
}


interface IMSG_POS_CHANGE {
  type: 'MSG_POS_CHANGE';
  data: {
    code: number;
    current_controller: number;
    current_location: number;
    current_sequence: number;
    previous_position: number;
    current_position: number;
  }
}


interface IMSG_SET {
  type: 'MSG_SET';
  data: {
    code: number;
    current_controller: number;
    current_location: number;
    current_sequence: number;
    current_position: number;
  }
}


interface IMSG_SWAP {
  type: 'MSG_SWAP';
  data: {
    code1: number;
    controller1: number;
    location1: number;
    sequence1: number;
    position1: number;
    code2: number;
    controller2: number;
    location2: number;
    sequence2: number;
    position2: number;
  }
}


interface IMSG_FIELD_DISABLED {
  type: 'MSG_FIELD_DISABLED';
  data: {
    disabled_fields: number;
  }
}


interface IMSG_SUMMONING {
  type: 'MSG_SUMMONING';
  data: {
    code: number;
    controller: number;
    location: number;
    sequence: number;
    position: number;
  }
}


interface IMSG_SUMMONED {
  type: 'MSG_SUMMONED';
  data: { }
}


interface IMSG_SPSUMMONING {
  type: 'MSG_SPSUMMONING';
  data: {
    code: number;
    controller: number;
    location: number;
    sequence: number;
    position: number;
  }
}


interface IMSG_SPSUMMONED {
  type: 'MSG_SPSUMMONED';
  data: { }
}


interface IMSG_FLIPSUMMONING {
  type: 'MSG_FLIPSUMMONING';
  data: {
    code: number;
    controller: number;
    location: number;
    sequence: number;
    position: number;
  }
}


interface IMSG_FLIPSUMMONED {
  type: 'MSG_FLIPSUMMONED';
  data: { }
}


interface IMSG_CHAINING {
  type: 'MSG_CHAINING';
  data: {
    code: number;
    previous_chain_controller: number;
    previous_chain_location: number;
    previous_chain_sequence: number;
    subsequence: number;
    chain_controller: number;
    chain_location: number;
    chain_sequence: number;
    desc: number;
    chain_param: number;
  }
}


interface IMSG_CHAINED {
  type: 'MSG_CHAINED';
  data: {
    chain_param: number;
  }
}


interface IMSG_CHAIN_SOLVING {
  type: 'MSG_CHAIN_SOLVING';
  data: {
    chain_param: number;
  }
}


interface IMSG_CHAIN_SOLVED {
  type: 'MSG_CHAIN_SOLVED';
  data: {
    chain_param: number;
  }
}


interface IMSG_CHAIN_END {
  type: 'MSG_CHAIN_END';
  data: { }
}


interface IMSG_CHAIN_NEGATED {
  type: 'MSG_CHAIN_NEGATED';
  data: {
    chain_param: number;
  }
}


interface IMSG_CHAIN_DISABLED {
  type: 'MSG_CHAIN_DISABLED';
  data: {
    chain_param: number;
  }
}


interface IMSG_CARD_SELECTED {
  type: 'MSG_CARD_SELECTED';
  data: { }
}


interface IMSG_RANDOM_SELECTED {
  type: 'MSG_RANDOM_SELECTED';
  data: {
    player: number;
    cards: {
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
    }[];
  }
}


interface IMSG_BECOME_TARGET {
  type: 'MSG_BECOME_TARGET';
  data: {
    cards: {
      controller: number;
      location: number;
      sequence: number;
      subsequence: number;
    }[];
  }
}


interface IMSG_DRAW {
  type: 'MSG_DRAW';
  data: {
    player: number;
    cards: {
      code: number;
    }[];
  }
}


interface IMSG_DAMAGE {
  type: 'MSG_DAMAGE';
  data: {
    player: number;
    value: number;
  }
}


interface IMSG_RECOVER {
  type: 'MSG_RECOVER';
  data: {
    player: number;
    value: number;
  }
}


interface IMSG_LPUPDATE {
  type: 'MSG_LPUPDATE';
  data: {
    player: number;
    value: number;
  }
}


interface IMSG_PAY_LPCOST {
  type: 'MSG_PAY_LPCOST';
  data: {
    player: number;
    value: number;
  }
}


interface IMSG_EQUIP {
  type: 'MSG_EQUIP';
  data: {
    controller1: number;
    location1: number;
    sequence1: number;
    ignore1: number;
    controller2: number;
    location2: number;
    sequence2: number;
    ignore2: number;
  }
}


interface IMSG_UNEQUIP {
  type: 'MSG_UNEQUIP';
  data: {
    controller1: number;
    location1: number;
    sequence1: number;
    ignore1: number;
  }
}


interface IMSG_CARD_TARGET {
  type: 'MSG_CARD_TARGET';
  data: {
    controller1: number;
    location1: number;
    sequence1: number;
    ignore1: number;
    controller2: number;
    location2: number;
    sequence2: number;
    ignore2: number;
  }
}


interface IMSG_CANCEL_TARGET {
  type: 'MSG_CANCEL_TARGET';
  data: {
    controller1: number;
    location1: number;
    sequence1: number;
    ignore1: number;
    controller2: number;
    location2: number;
    sequence2: number;
    ignore2: number;
  }
}


interface IMSG_ADD_COUNTER {
  type: 'MSG_ADD_COUNTER';
  data: {
    type: number;
    controller: number;
    location: number;
    sequence: number;
    count: number;
  }
}


interface IMSG_REMOVE_COUNTER {
  type: 'MSG_REMOVE_COUNTER';
  data: {
    type: number;
    controller: number;
    location: number;
    sequence: number;
    count: number;
  }
}


interface IMSG_ATTACK {
  type: 'MSG_ATTACK';
  data: {
    atk_controller: number;
    atk_location: number;
    atk_sequence: number;
    atk_ignore: number;
    def_controller: number;
    def_location: number;
    def_sequence: number;
    def_ignore: number;
  }
}


interface IMSG_BATTLE {
  type: 'MSG_BATTLE';
  data: {
    atk_controller: number;
    atk_location: number;
    atk_sequence: number;
    atk_subsequence: number;
    atk_atkvalue: number;
    atk_defvalue: number;
    atk_ignore: number;
    def_controller: number;
    def_location: number;
    def_sequence: number;
    def_subsequence: number;
    def_atkvalue: number;
    def_defvalue: number;
    def_ignore: number;
  }
}


interface IMSG_ATTACK_DISABLED {
  type: 'MSG_ATTACK_DISABLED';
  data: { }
}


interface IMSG_DAMAGE_STEP_START {
  type: 'MSG_DAMAGE_STEP_START';
  data: { }
}


interface IMSG_DAMAGE_STEP_END {
  type: 'MSG_DAMAGE_STEP_END';
  data: { }
}


interface IMSG_MISSED_EFFECT {
  type: 'MSG_MISSED_EFFECT';
  data: {
    ignore: number;
    code: number;
  }
}


interface IMSG_TOSS_COIN {
  type: 'MSG_TOSS_COIN';
  data: {
    player: number;
    tosses: {
      value: number;
    }[];
  }
}


interface IMSG_TOSS_DICE {
  type: 'MSG_TOSS_DICE';
  data: {
    player: number;
    tosses: {
      value: number;
    }[];
  }
}


interface IMSG_ROCK_PAPER_SCISSORS {
  type: 'MSG_ROCK_PAPER_SCISSORS';
  data: {
    player: number;
  }
}


interface IMSG_HAND_RES {
  type: 'MSG_HAND_RES';
  data: {
    res: number;
  }
}


interface IMSG_ANNOUNCE_RACE {
  type: 'MSG_ANNOUNCE_RACE';
  data: {
    player: number;
    count: number;
    available: number;
  }
}


interface IMSG_ANNOUNCE_ATTRIB {
  type: 'MSG_ANNOUNCE_ATTRIB';
  data: {
    player: number;
    count: number;
    available: number;
  }
}


interface IMSG_ANNOUNCE_CARD {
  type: 'MSG_ANNOUNCE_CARD';
  data: {
    player: number;
    declarable_type: number;
  }
}


interface IMSG_ANNOUNCE_NUMBER {
  type: 'MSG_ANNOUNCE_NUMBER';
  data: {
    player: number;
    numbers: {
      value: number;
    }[];
  }
}


interface IMSG_ANNOUNCE_CARD_FILTER {
  type: 'MSG_ANNOUNCE_CARD_FILTER';
  data: {
    player: number;
    filters: {
      opcode: number;
    }[];
  }
}


interface IMSG_CARD_HINT {
  type: 'MSG_CARD_HINT';
  data: {
    controller: number;
    location: number;
    sequence: number;
    ignore: number;
    chtype: number;
    value: number;
  }
}


interface IMSG_PLAYER_HINT {
  type: 'MSG_PLAYER_HINT';
  data: {
    player: number;
    chtype: number;
    value: number;
  }
}


interface IMSG_MATCH_KILL {
  type: 'MSG_MATCH_KILL';
  data: {
    match_kill: number;
  }
}


interface IMSG_RELOAD_FIELD {
  type: 'MSG_RELOAD_FIELD';
  data: {
    duel_rule: number;
    players: {
      lp: number;
      mzone_cards: {
        value: {
          position: number;
          xyz_count: number;
        } | undefined;
      }[];
      cards: {
        value: {
          position: number;
        } | undefined;
      }[];
      deck_count: number;
      hand_count: number;
      grave_count: number;
      banish_count: number;
      extra_count: number;
      extra_pendu_count: number;
      chains: {
        code: number;
        previous_controller: number;
        previous_location: number;
        previous_sequence: number;
        previous_subsequence: number;
        current_controller: number;
        current_location: number;
        current_sequence: number;
        desc: number;
      }[];
    }[];
  }
}


type IMSG =
    IMSG_RETRY
  | IMSG_HINT
  | IMSG_WIN
  | IMSG_WAITING
  | IMSG_START
  | IMSG_SELECT_BATTLECMD
  | IMSG_SELECT_IDLECMD
  | IMSG_SELECT_EFFECTYN
  | IMSG_SELECT_YESNO
  | IMSG_SELECT_OPTION
  | IMSG_SELECT_CARD
  | IMSG_SELECT_UNSELECT_CARD
  | IMSG_SELECT_CHAIN
  | IMSG_SELECT_PLACE
  | IMSG_SELECT_DISFIELD
  | IMSG_SELECT_POSITION
  | IMSG_SELECT_TRIBUTE
  | IMSG_SELECT_COUNTER
  | IMSG_SELECT_SUM
  | IMSG_SORT_CARD
  | IMSG_SORT_CHAIN
  | IMSG_CONFIRM_DECKTOP
  | IMSG_CONFIRM_EXTRATOP
  | IMSG_CONFIRM_CARDS
  | IMSG_SHUFFLE_DECK
  | IMSG_REFRESH_DECK
  | IMSG_SWAP_GRAVE_DECK
  | IMSG_SHUFFLE_SET_CARD
  | IMSG_SHUFFLE_HAND
  | IMSG_SHUFFLE_EXTRA
  | IMSG_REVERSE_DECK
  | IMSG_DECK_TOP
  | IMSG_NEW_TURN
  | IMSG_NEW_PHASE
  | IMSG_MOVE
  | IMSG_POS_CHANGE
  | IMSG_SET
  | IMSG_SWAP
  | IMSG_FIELD_DISABLED
  | IMSG_SUMMONING
  | IMSG_SUMMONED
  | IMSG_SPSUMMONING
  | IMSG_SPSUMMONED
  | IMSG_FLIPSUMMONING
  | IMSG_FLIPSUMMONED
  | IMSG_CHAINING
  | IMSG_CHAINED
  | IMSG_CHAIN_SOLVING
  | IMSG_CHAIN_SOLVED
  | IMSG_CHAIN_END
  | IMSG_CHAIN_NEGATED
  | IMSG_CHAIN_DISABLED
  | IMSG_CARD_SELECTED
  | IMSG_RANDOM_SELECTED
  | IMSG_BECOME_TARGET
  | IMSG_DRAW
  | IMSG_DAMAGE
  | IMSG_RECOVER
  | IMSG_LPUPDATE
  | IMSG_PAY_LPCOST
  | IMSG_EQUIP
  | IMSG_UNEQUIP
  | IMSG_CARD_TARGET
  | IMSG_CANCEL_TARGET
  | IMSG_ADD_COUNTER
  | IMSG_REMOVE_COUNTER
  | IMSG_ATTACK
  | IMSG_BATTLE
  | IMSG_ATTACK_DISABLED
  | IMSG_DAMAGE_STEP_START
  | IMSG_DAMAGE_STEP_END
  | IMSG_MISSED_EFFECT
  | IMSG_TOSS_COIN
  | IMSG_TOSS_DICE
  | IMSG_ROCK_PAPER_SCISSORS
  | IMSG_HAND_RES
  | IMSG_ANNOUNCE_RACE
  | IMSG_ANNOUNCE_ATTRIB
  | IMSG_ANNOUNCE_CARD
  | IMSG_ANNOUNCE_NUMBER
  | IMSG_ANNOUNCE_CARD_FILTER
  | IMSG_CARD_HINT
  | IMSG_PLAYER_HINT
  | IMSG_MATCH_KILL
  | IMSG_RELOAD_FIELD;

const MsgTypes = {
  MSG_RETRY: 'MSG_RETRY',
  MSG_HINT: 'MSG_HINT',
  MSG_WIN: 'MSG_WIN',
  MSG_WAITING: 'MSG_WAITING',
  MSG_START: 'MSG_START',
  MSG_SELECT_BATTLECMD: 'MSG_SELECT_BATTLECMD',
  MSG_SELECT_IDLECMD: 'MSG_SELECT_IDLECMD',
  MSG_SELECT_EFFECTYN: 'MSG_SELECT_EFFECTYN',
  MSG_SELECT_YESNO: 'MSG_SELECT_YESNO',
  MSG_SELECT_OPTION: 'MSG_SELECT_OPTION',
  MSG_SELECT_CARD: 'MSG_SELECT_CARD',
  MSG_SELECT_UNSELECT_CARD: 'MSG_SELECT_UNSELECT_CARD',
  MSG_SELECT_CHAIN: 'MSG_SELECT_CHAIN',
  MSG_SELECT_PLACE: 'MSG_SELECT_PLACE',
  MSG_SELECT_DISFIELD: 'MSG_SELECT_DISFIELD',
  MSG_SELECT_POSITION: 'MSG_SELECT_POSITION',
  MSG_SELECT_TRIBUTE: 'MSG_SELECT_TRIBUTE',
  MSG_SELECT_COUNTER: 'MSG_SELECT_COUNTER',
  MSG_SELECT_SUM: 'MSG_SELECT_SUM',
  MSG_SORT_CARD: 'MSG_SORT_CARD',
  MSG_SORT_CHAIN: 'MSG_SORT_CHAIN',
  MSG_CONFIRM_DECKTOP: 'MSG_CONFIRM_DECKTOP',
  MSG_CONFIRM_EXTRATOP: 'MSG_CONFIRM_EXTRATOP',
  MSG_CONFIRM_CARDS: 'MSG_CONFIRM_CARDS',
  MSG_SHUFFLE_DECK: 'MSG_SHUFFLE_DECK',
  MSG_REFRESH_DECK: 'MSG_REFRESH_DECK',
  MSG_SWAP_GRAVE_DECK: 'MSG_SWAP_GRAVE_DECK',
  MSG_SHUFFLE_SET_CARD: 'MSG_SHUFFLE_SET_CARD',
  MSG_SHUFFLE_HAND: 'MSG_SHUFFLE_HAND',
  MSG_SHUFFLE_EXTRA: 'MSG_SHUFFLE_EXTRA',
  MSG_REVERSE_DECK: 'MSG_REVERSE_DECK',
  MSG_DECK_TOP: 'MSG_DECK_TOP',
  MSG_NEW_TURN: 'MSG_NEW_TURN',
  MSG_NEW_PHASE: 'MSG_NEW_PHASE',
  MSG_MOVE: 'MSG_MOVE',
  MSG_POS_CHANGE: 'MSG_POS_CHANGE',
  MSG_SET: 'MSG_SET',
  MSG_SWAP: 'MSG_SWAP',
  MSG_FIELD_DISABLED: 'MSG_FIELD_DISABLED',
  MSG_SUMMONING: 'MSG_SUMMONING',
  MSG_SUMMONED: 'MSG_SUMMONED',
  MSG_SPSUMMONING: 'MSG_SPSUMMONING',
  MSG_SPSUMMONED: 'MSG_SPSUMMONED',
  MSG_FLIPSUMMONING: 'MSG_FLIPSUMMONING',
  MSG_FLIPSUMMONED: 'MSG_FLIPSUMMONED',
  MSG_CHAINING: 'MSG_CHAINING',
  MSG_CHAINED: 'MSG_CHAINED',
  MSG_CHAIN_SOLVING: 'MSG_CHAIN_SOLVING',
  MSG_CHAIN_SOLVED: 'MSG_CHAIN_SOLVED',
  MSG_CHAIN_END: 'MSG_CHAIN_END',
  MSG_CHAIN_NEGATED: 'MSG_CHAIN_NEGATED',
  MSG_CHAIN_DISABLED: 'MSG_CHAIN_DISABLED',
  MSG_CARD_SELECTED: 'MSG_CARD_SELECTED',
  MSG_RANDOM_SELECTED: 'MSG_RANDOM_SELECTED',
  MSG_BECOME_TARGET: 'MSG_BECOME_TARGET',
  MSG_DRAW: 'MSG_DRAW',
  MSG_DAMAGE: 'MSG_DAMAGE',
  MSG_RECOVER: 'MSG_RECOVER',
  MSG_LPUPDATE: 'MSG_LPUPDATE',
  MSG_PAY_LPCOST: 'MSG_PAY_LPCOST',
  MSG_EQUIP: 'MSG_EQUIP',
  MSG_UNEQUIP: 'MSG_UNEQUIP',
  MSG_CARD_TARGET: 'MSG_CARD_TARGET',
  MSG_CANCEL_TARGET: 'MSG_CANCEL_TARGET',
  MSG_ADD_COUNTER: 'MSG_ADD_COUNTER',
  MSG_REMOVE_COUNTER: 'MSG_REMOVE_COUNTER',
  MSG_ATTACK: 'MSG_ATTACK',
  MSG_BATTLE: 'MSG_BATTLE',
  MSG_ATTACK_DISABLED: 'MSG_ATTACK_DISABLED',
  MSG_DAMAGE_STEP_START: 'MSG_DAMAGE_STEP_START',
  MSG_DAMAGE_STEP_END: 'MSG_DAMAGE_STEP_END',
  MSG_MISSED_EFFECT: 'MSG_MISSED_EFFECT',
  MSG_TOSS_COIN: 'MSG_TOSS_COIN',
  MSG_TOSS_DICE: 'MSG_TOSS_DICE',
  MSG_ROCK_PAPER_SCISSORS: 'MSG_ROCK_PAPER_SCISSORS',
  MSG_HAND_RES: 'MSG_HAND_RES',
  MSG_ANNOUNCE_RACE: 'MSG_ANNOUNCE_RACE',
  MSG_ANNOUNCE_ATTRIB: 'MSG_ANNOUNCE_ATTRIB',
  MSG_ANNOUNCE_CARD: 'MSG_ANNOUNCE_CARD',
  MSG_ANNOUNCE_NUMBER: 'MSG_ANNOUNCE_NUMBER',
  MSG_ANNOUNCE_CARD_FILTER: 'MSG_ANNOUNCE_CARD_FILTER',
  MSG_CARD_HINT: 'MSG_CARD_HINT',
  MSG_PLAYER_HINT: 'MSG_PLAYER_HINT',
  MSG_MATCH_KILL: 'MSG_MATCH_KILL',
  MSG_RELOAD_FIELD: 'MSG_RELOAD_FIELD'
}
