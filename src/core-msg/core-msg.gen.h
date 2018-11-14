struct CoreMsg_RETRY {
};

struct CoreMsg_HINT {
  u8  type;
  u8  player;
  u32 data;
};

struct CoreMsg_WIN {
  u8  player;
  u8  type;
};

struct CoreMsg_WAITING {
};

struct CoreMsg_START {
  u8  player_type;
  u32 player0_lp;
  u32 player1_lp;
  u16 player0_deck_count;
  u16 player0_extra_count;
  u16 player1_deck_count;
  u16 player1_extra_count;
};

struct CoreMsg_SELECT_BATTLECMD {
  u8  player;
  struct Candidate1 {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u32 description;
  };
  std::vector<Candidate1> candidates1;
  struct Candidate2 {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
  };
  std::vector<Candidate2> candidates2;
  u8  to_main2_phase;
  u8  to_end_phase;
};

struct CoreMsg_SELECT_IDLECMD {
  u8  player;
  struct Candidate {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
  };
  std::vector<Candidate> summon_candidates;
  // already defined Candidate
  std::vector<Candidate> spsummon_candidates;
  // already defined Candidate
  std::vector<Candidate> reposition_candidates;
  // already defined Candidate
  std::vector<Candidate> mset_candidates;
  // already defined Candidate
  std::vector<Candidate> sset_candidates;
  struct ActiveCandidate {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u32 desc;
  };
  std::vector<ActiveCandidate> active_candidates;
  u8  to_battle_phase;
  u8  to_end_phase;
  u8  can_shuffle;
};

struct CoreMsg_SELECT_EFFECTYN {
  u8  player;
  u32 code;
  u8  controller;
  u8  location;
  u8  sequence;
  u8  _ignore_;
  u32 desc;
};

struct CoreMsg_SELECT_YESNO {
  u8  player;
  u32 desc;
};

struct CoreMsg_SELECT_OPTION {
  u8  player;
  struct Candidate {
    u32 option_id;
  };
  std::vector<Candidate> candidates;
};

struct CoreMsg_SELECT_CARD {
  u8  player;
  u8  cancelable;
  u8  select_min;
  u8  select_max;
  struct Candidate {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
  };
  std::vector<Candidate> candidates;
};

struct CoreMsg_SELECT_UNSELECT_CARD {
  u8  player;
  u8  finishable;
  u8  cancelable;
  u8  select_min;
  u8  select_max;
  struct Candidate1 {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
  };
  std::vector<Candidate1> candidates1;
  struct Candidate2 {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
  };
  std::vector<Candidate2> candidates2;
};

struct CoreMsg_SELECT_CHAIN {
  u8  player;
  u8  spe_count;
  u8  forced;
  u32 hint0;
  u32 hint1;
  struct Candidate {
    u8  flag;
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
    u32 desc;
  };
  std::vector<Candidate> candidates;
};

struct CoreMsg_SELECT_PLACE {
  u8  player;
  u8  select_min;
  u32 selectable_field;
};

struct CoreMsg_SELECT_DISFIELD {
  u8  player;
  u8  select_min;
  u32 selectable_field;
};

struct CoreMsg_SELECT_POSITION {
  u8  player;
  u32 code;
  u8  positions;
};

struct CoreMsg_SELECT_TRIBUTE {
  u8  player;
  u8  cancelable;
  u8  select_min;
  u8  select_max;
  struct Candidate {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u8  operation_param;
  };
  std::vector<Candidate> candidates;
};

struct CoreMsg_SELECT_COUNTER {
  u8  player;
  u16 select_counter_type;
  u16 select_counter_count;
  struct Candidate {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u16 operation_param;
  };
  std::vector<Candidate> candidates;
};

struct CoreMsg_SELECT_SUM {
  u8  select_mode;
  u8  player;
  u32 select_sumval;
  u8  select_min;
  u8  select_max;
  struct MustSelect {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u32 operation_param;
  };
  std::vector<MustSelect> must_select_candidates;
  struct Candidate {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
    u32 operation_param;
  };
  std::vector<Candidate> candidates;
};

struct CoreMsg_SORT_CARD {
  u8  player;
  struct Card {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_SORT_CHAIN {
  u8  player;
  struct Card {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_CONFIRM_DECKTOP {
  u8  player;
  struct Card {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_CONFIRM_EXTRATOP {
  u8  player;
  struct Card {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_CONFIRM_CARDS {
  u8  player;
  struct Card {
    u32 code;
    u8  controller;
    u8  location;
    u8  sequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_SHUFFLE_DECK {
  u8  player;
};

struct CoreMsg_REFRESH_DECK {
  u8  player;
};

struct CoreMsg_SWAP_GRAVE_DECK {
  u8  player;
};

struct CoreMsg_SHUFFLE_SET_CARD {
  u8  location;
  struct Card {
    u8  controller;
    u8  location;
    u8  sequence;
    u8  ignore;
  };
  std::vector<Card> cards1;
  // already defined Card
  std::vector<Card> cards2;
};

struct CoreMsg_SHUFFLE_HAND {
  u8  player;
  struct Card {
    u32 code;
  };
  std::vector<Card> cards;
};

struct CoreMsg_SHUFFLE_EXTRA {
  u8  player;
  struct Card {
    u32 code;
  };
  std::vector<Card> cards;
};

struct CoreMsg_REVERSE_DECK {
};

struct CoreMsg_DECK_TOP {
  u8  player;
  u8  sequence;
  u32 code;
};

struct CoreMsg_NEW_TURN {
  u8  player;
};

struct CoreMsg_NEW_PHASE {
  u16 phase;
};

struct CoreMsg_MOVE {
  u32 code;
  u8  previous_controller;
  u8  previous_location;
  u8  previous_sequence;
  u8  previous_position;
  u8  current_controller;
  u8  current_location;
  u8  current_sequence;
  u8  current_position;
  u32 reason;
};

struct CoreMsg_POS_CHANGE {
  u32 code;
  u8  current_controller;
  u8  current_location;
  u8  current_sequence;
  u8  previous_position;
  u8  current_position;
};

struct CoreMsg_SET {
  u32 code;
  u8  current_controller;
  u8  current_location;
  u8  current_sequence;
  u8  current_position;
};

struct CoreMsg_SWAP {
  u32 code1;
  u8  controller1;
  u8  location1;
  u8  sequence1;
  u8  position1;
  u32 code2;
  u8  controller2;
  u8  location2;
  u8  sequence2;
  u8  position2;
};

struct CoreMsg_FIELD_DISABLED {
  u32 disabled_fields;
};

struct CoreMsg_SUMMONING {
  u32 code;
  u8  controller;
  u8  location;
  u8  sequence;
  u8  position;
};

struct CoreMsg_SUMMONED {
};

struct CoreMsg_SPSUMMONING {
  u32 code;
  u8  controller;
  u8  location;
  u8  sequence;
  u8  position;
};

struct CoreMsg_SPSUMMONED {
};

struct CoreMsg_FLIPSUMMONING {
  u32 code;
  u8  controller;
  u8  location;
  u8  sequence;
  u8  position;
};

struct CoreMsg_FLIPSUMMONED {
};

struct CoreMsg_CHAINING {
  u32 code;
  u8  previous_chain_controller;
  u8  previous_chain_location;
  u8  previous_chain_sequence;
  u8  subsequence;
  u8  chain_controller;
  u8  chain_location;
  u8  chain_sequence;
  u32 desc;
  u8  chain_param;
};

struct CoreMsg_CHAINED {
  u8  chain_param;
};

struct CoreMsg_CHAIN_SOLVING {
  u8  chain_param;
};

struct CoreMsg_CHAIN_SOLVED {
  u8  chain_param;
};

struct CoreMsg_CHAIN_END {
};

struct CoreMsg_CHAIN_NEGATED {
  u8  chain_param;
};

struct CoreMsg_CHAIN_DISABLED {
  u8  chain_param;
};

struct CoreMsg_CARD_SELECTED {
};

struct CoreMsg_RANDOM_SELECTED {
  u8  player;
  struct Card {
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_BECOME_TARGET {
  struct Card {
    u8  controller;
    u8  location;
    u8  sequence;
    u8  subsequence;
  };
  std::vector<Card> cards;
};

struct CoreMsg_DRAW {
  u8  player;
  struct Card {
    u32 code;
  };
  std::vector<Card> cards;
};

struct CoreMsg_DAMAGE {
  u8  player;
  u32 value;
};

struct CoreMsg_RECOVER {
  u8  player;
  u32 value;
};

struct CoreMsg_LPUPDATE {
  u8  player;
  u32 value;
};

struct CoreMsg_PAY_LPCOST {
  u8  player;
  u32 value;
};

struct CoreMsg_EQUIP {
  u8  controller1;
  u8  location1;
  u8  sequence1;
  u8  ignore1;
  u8  controller2;
  u8  location2;
  u8  sequence2;
  u8  ignore2;
};

struct CoreMsg_UNEQUIP {
  u8  controller1;
  u8  location1;
  u8  sequence1;
  u8  ignore1;
};

struct CoreMsg_CARD_TARGET {
  u8  controller1;
  u8  location1;
  u8  sequence1;
  u8  ignore1;
  u8  controller2;
  u8  location2;
  u8  sequence2;
  u8  ignore2;
};

struct CoreMsg_CANCEL_TARGET {
  u8  controller1;
  u8  location1;
  u8  sequence1;
  u8  ignore1;
  u8  controller2;
  u8  location2;
  u8  sequence2;
  u8  ignore2;
};

struct CoreMsg_ADD_COUNTER {
  u16 type;
  u8  controller;
  u8  location;
  u8  sequence;
  u16 count;
};

struct CoreMsg_REMOVE_COUNTER {
  u16 type;
  u8  controller;
  u8  location;
  u8  sequence;
  u16 count;
};

struct CoreMsg_ATTACK {
  u8  atk_controller;
  u8  atk_location;
  u8  atk_sequence;
  u8  atk_ignore;
  u8  def_controller;
  u8  def_location;
  u8  def_sequence;
  u8  def_ignore;
};

struct CoreMsg_BATTLE {
  u8  atk_controller;
  u8  atk_location;
  u8  atk_sequence;
  u8  atk_subsequence;
  u32 atk_atkvalue;
  u32 atk_defvalue;
  u8  atk_ignore;
  u8  def_controller;
  u8  def_location;
  u8  def_sequence;
  u8  def_subsequence;
  u32 def_atkvalue;
  u32 def_defvalue;
  u8  def_ignore;
};

struct CoreMsg_ATTACK_DISABLED {
};

struct CoreMsg_DAMAGE_STEP_START {
};

struct CoreMsg_DAMAGE_STEP_END {
};

struct CoreMsg_MISSED_EFFECT {
  u32 ignore;
  u32 code;
};

struct CoreMsg_TOSS_COIN {
  u8  player;
  struct Result {
    u8  value;
  };
  std::vector<Result> tosses;
};

struct CoreMsg_TOSS_DICE {
  u8  player;
  struct Result {
    u8  value;
  };
  std::vector<Result> tosses;
};

struct CoreMsg_ROCK_PAPER_SCISSORS {
  u8  player;
};

struct CoreMsg_HAND_RES {
  u8  res;
};

struct CoreMsg_ANNOUNCE_RACE {
  u8  player;
  u8  count;
  u32 available;
};

struct CoreMsg_ANNOUNCE_ATTRIB {
  u8  player;
  u8  count;
  u32 available;
};

struct CoreMsg_ANNOUNCE_CARD {
  u8  player;
  u32 declarable_type;
};

struct CoreMsg_ANNOUNCE_NUMBER {
  u8  player;
  struct Announce {
    u32 value;
  };
  std::vector<Announce> numbers;
};

struct CoreMsg_ANNOUNCE_CARD_FILTER {
  u8  player;
  struct Filter {
    u32 opcode;
  };
  std::vector<Filter> filters;
};

struct CoreMsg_CARD_HINT {
  u8  controller;
  u8  location;
  u8  sequence;
  u8  ignore;
  u8  chtype;
  u32 value;
};

struct CoreMsg_PLAYER_HINT {
  u8  player;
  u8  chtype;
  u32 value;
};

struct CoreMsg_MATCH_KILL {
  u32 match_kill;
};

struct CoreMsg_RELOAD_FIELD {
  u8  duel_rule;
  struct PlayersField {
    u32 lp;
    struct MCard {
      struct MValue {
        u8  position;
        u8  xyz_count;
      };
      std::optional<MValue> value;
    };
    std::array<MCard, 7> mzone_cards;
    struct Card {
      struct Value {
        u8  position;
      };
      std::optional<Value> value;
    };
    std::array<Card, 8> cards;
    u8  deck_count;
    u8  hand_count;
    u8  grave_count;
    u8  banish_count;
    u8  extra_count;
    u8  extra_pendu_count;
    struct Chain {
      u32 code;
      u8  previous_controller;
      u8  previous_location;
      u8  previous_sequence;
      u8  previous_subsequence;
      u8  current_controller;
      u8  current_location;
      u8  current_sequence;
      u32 desc;
    };
    std::vector<Chain> chains;
  };
  std::array<PlayersField, 4> players;
};

