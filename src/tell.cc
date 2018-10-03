#include "tell.h"
#include "core-msg/interface.h"
#include "support/format.h"
#include "replay/replay-machine.h"
#include "core-card-data/default-storage.h"
#include "3rd-part/core/common.h"

namespace ri::story {

template <typename ...Args>
static inline
Seq<Str>
singleton(const Args &...args)
{
  return { format(args...) };
}

static inline
Str
name_from_code(u32 code)
{
  const auto &storage = *core_card_data::default_core_card_storage();

  const auto found = storage.lookup.find(code);
  if (found == storage.lookup.cend()) {
    return "<unknown>";
  } else {
    return found->second.name;
  }
}

template <typename T>
static inline
Str
join_card_names(const Seq<T> &cards)
{
  Str  names;
  bool sep = false;

  for (const auto &x: cards) {
    u32 code;

    if constexpr (std::is_integral_v<T>)
      code = x;
    else
      code = x.code;

    names += format("%s **%s** ", sep ? ", " : "", name_from_code(code));

    sep = true;
  }

  return names;
}

static inline
Str
format_location( u32 location
               , u32 sequence    = UINT32_MAX
               , u32 subsequence = UINT32_MAX)
{
  const char *location_labels[] = {
    "卡组", "手卡", "怪兽区域", "魔法&陷阱区域",
    "墓地", "除外区", "额外卡组区域", "XYZ素材区域"
  };
  const auto labels_n = sizeof location_labels / sizeof location_labels[0];

  const auto sequence_label
    = sequence == UINT32_MAX && subsequence == UINT32_MAX ? format("")
    : sequence    == UINT32_MAX ? format("(/%d)", subsequence)
    : subsequence == UINT32_MAX ? format("(%d)", sequence)
    : format("(%d/%d)", sequence, subsequence);

  // handle xyz-overlay
  if ((location & LOCATION_EXTRA) && (location && LOCATION_OVERLAY)) {
    return format("%s%s", "XYZ叠放区", sequence_label, location);
  }

  for (unsigned i = 0; i != labels_n; ++i) {
    if (location & (1u << i))
      return format("%s%s", location_labels[i], sequence_label, location);
  }

  return "<unknown>";
}

static inline
Str
format_position(u32 position)
{
  const char *position_labels[] = {
    "表侧攻击", "里侧攻击", "表侧守备", "里侧守备"
  };

  const auto labels_n = sizeof position_labels / sizeof position_labels[0];

  for (unsigned i = 0; i != labels_n; ++i) {
    if (position & (1u << i)) {
      return position_labels[i];
    }
  }

  return "<unknown>";
}

struct StoryTeller
{
  const StoryTellerConfig &cfg;
  core_msg::CoreMsg_HINT last_hint = { };

#define ON_MESSAGE(ty)                           \
  Seq<Str>                                       \
  operator ()(const attr_unused core_msg::ty &msg)

  ON_MESSAGE(CoreMsg_HINT) {
    last_hint = msg;
    return { };
  }

  ON_MESSAGE(CoreMsg_RETRY) {
    // not possible
    return { " *** RETRY" };
  }

  ON_MESSAGE(CoreMsg_WIN) {
    const auto player = msg.player;
    const auto reason = msg.type;

    return singleton("玩家 _%s_ 获胜", cfg.player_names[player]);
  }

  ON_MESSAGE(CoreMsg_DRAW) {
    const auto player = msg.player;

    return singleton( "玩家 _%s_ 抽了`%zu`张卡: %s"
                    , cfg.player_names[player]
                    , msg.cards.size()
                    , join_card_names(msg.cards));
  }

  ON_MESSAGE(CoreMsg_CONFIRM_DECKTOP) {
    Seq<Str> lines = { format( "确认玩家 _%s_ 的卡组顶`%zu`张卡: %s"
                              , cfg.player_names[msg.player]
                              , msg.cards.size()
                              , join_card_names(msg.cards)) };

    return lines;
  }

  ON_MESSAGE(CoreMsg_CONFIRM_EXTRATOP) {
    Seq<Str> lines = { format( "确认玩家 _%s_ 的额外卡组顶`%zu`张卡: %s"
                              , cfg.player_names[msg.player]
                              , msg.cards.size()
                              , join_card_names(msg.cards)) };

    return lines;
  }

  ON_MESSAGE(CoreMsg_CONFIRM_CARDS) {
    Seq<Str> lines = { format( "确认玩家 _%s_ `%zu`张卡: %s"
                              , cfg.player_names[msg.player]
                              , msg.cards.size()
                              , join_card_names(msg.cards)) };

    return lines;
  }

  ON_MESSAGE(CoreMsg_NEW_TURN) {
    const auto player = msg.player;
    return singleton("进入玩家 _%s_ 的回合", cfg.player_names[player]);
  }

  ON_MESSAGE(CoreMsg_NEW_PHASE) {
    const auto phase
      = msg.phase == PHASE_STANDBY      ? "准备阶段"
      : msg.phase == PHASE_BATTLE_STEP  ? "战斗步骤"
      : msg.phase == PHASE_DAMAGE_CAL   ? "伤害步骤"
      : msg.phase == PHASE_BATTLE       ? "战斗阶段"
      : msg.phase == PHASE_DRAW         ? "抽卡阶段"
      : msg.phase == PHASE_MAIN2        ? "主要阶段1"
      : msg.phase == PHASE_MAIN1        ? "主要阶段2"
      : msg.phase == PHASE_END          ? "结束阶段"
      : msg.phase == PHASE_BATTLE_START ? "战斗步骤开始"
      : "<unknown phase>";

    return singleton("进入 **%s** ", phase);
  }

  ON_MESSAGE(CoreMsg_SWAP) {
    const auto card1_name = name_from_code(msg.code1);
    const auto card2_name = name_from_code(msg.code2);
    return singleton("交换 **%s** 和 **%s** 的位置", card1_name, card2_name);
  }

  ON_MESSAGE(CoreMsg_POS_CHANGE) {
    const auto name = name_from_code(msg.code);
    const auto prev_position = format_position(msg.previous_position);
    const auto position = format_position(msg.current_position);
    const auto location = format_location(msg.current_location, msg.current_sequence);
    const auto player = cfg.player_names[msg.current_controller];

    return singleton( "玩家 _%s_ 位于 **%s** 的卡片 **%s** 表示形式由 **%s** 变更为 **%s** "
                    , player
                    , location
                    , name
                    , prev_position
                    , position);
  }

  ON_MESSAGE(CoreMsg_SUMMONING) {
    const auto player = msg.controller;
    const auto name = name_from_code(msg.code);
    const auto position = format_position(msg.position);
    const auto location = format_location(msg.location, msg.sequence);

    return singleton( "玩家 _%s_ 以 **%s** 表示召唤怪兽 **%s** 于 **%s** "
                    , cfg.player_names[player]
                    , position
                    , name
                    , location);
  }

  ON_MESSAGE(CoreMsg_SPSUMMONING) {
    const auto player = msg.controller;
    const auto name = name_from_code(msg.code);
    const auto position = format_position(msg.position);
    const auto location = format_location(msg.location, msg.sequence);

    return singleton( "玩家 _%s_ 以 **%s** 表示特殊召唤怪兽 **%s** 于 **%s** "
                    , cfg.player_names[player]
                    , position
                    , name
                    , location);
  }

  ON_MESSAGE(CoreMsg_FLIPSUMMONING) {
    const auto player = msg.controller;
    const auto name   = name_from_code(msg.code);

    return singleton("玩家 _%s_ 翻转召唤怪兽 **%s** ", cfg.player_names[player], name);
  }

  ON_MESSAGE(CoreMsg_BECOME_TARGET) {
    Str line;
    bool sep = false;
    for (const auto &c: msg.cards) {
      if (sep) line += ",";

      const auto player_name = cfg.player_names[c.controller];
      const auto location = format_location(c.location, c.sequence);

      line += format("玩家 _%s_ 在  **%s**  的卡片", player_name, location);

      sep = true;
    }

    line += "被选择为对象";

    return { line };
  }

  ON_MESSAGE(CoreMsg_DAMAGE) {
    const auto player_name = cfg.player_names[msg.player];
    const auto value = msg.value;

    return singleton("玩家 _%s_ 生命值下降`%d`", player_name, value);
  }

  ON_MESSAGE(CoreMsg_RECOVER) {
    const auto player_name = cfg.player_names[msg.player];
    const auto value = msg.value;

    return singleton("玩家 _%s_ 生命值回复`%d`", player_name, value);
  }

  ON_MESSAGE(CoreMsg_LPUPDATE) {
    const auto player_name = cfg.player_names[msg.player];
    const auto value = msg.value;

    return singleton("玩家 _%s_ 生命值变为`%d`", player_name, value);
  }

  ON_MESSAGE(CoreMsg_PAY_LPCOST) {
    const auto player_name = cfg.player_names[msg.player];
    const auto value = msg.value;

    return singleton("玩家 _%s_ 支付`%d`生命值", player_name, value);
  }

  ON_MESSAGE(CoreMsg_FIELD_DISABLED) {
    return singleton("   > 区域被禁用0x%08x", msg.disabled_fields);
  }

  ON_MESSAGE(CoreMsg_ATTACK) {
    const auto atk_player = cfg.player_names[msg.atk_controller];
    const auto def_player = cfg.player_names[msg.def_controller];
    const auto atk_location = format_location(msg.atk_location, msg.atk_sequence);
    const auto def_location = format_location(msg.def_location, msg.def_sequence);

    return singleton( "玩家 _%s_ 的 **%s** 攻击玩家 _%s_ 的 **%s** "
                    , atk_player
                    , atk_location
                    , def_player
                    , def_location);
  }

  ON_MESSAGE(CoreMsg_MOVE) {
    for (unsigned i : { 1, 4, 5 }) { // HAND/GRAVE/REMOVE(banish)
      const auto mask = 1u << i;
      if ((msg.previous_location & mask) && (msg.current_location & mask)) {
        return { };
      }
    }

    const auto player_name   = cfg.player_names[msg.current_controller];
    const auto card_name     = name_from_code(msg.code);
    const auto prev_location = format_location(msg.previous_location, msg.previous_sequence);
    const auto location      = format_location(msg.current_location, msg.current_sequence);

    const bool destory = !!(msg.reason & REASON_DESTROY);
    const bool to_hand = !!(msg.current_location & LOCATION_HAND);
    const bool horiz_move
      =  ((msg.current_location & LOCATION_MZONE) && (msg.previous_position & LOCATION_MZONE))
      || ((msg.current_location & LOCATION_SZONE) && (msg.previous_position & LOCATION_SZONE));

    const auto verb = to_hand ? "加入" : horiz_move ? "移动到" : "送往";

    return singleton( "   >  **%s** 处的卡片 **%s** 被%s%s _%s_ 的 **%s** "
                    , prev_location
                    , card_name
                    , destory ? "破坏并" : ""
                    , verb
                    , player_name
                    , location);
  }

  ON_MESSAGE(CoreMsg_SET) {
    const auto player_name = cfg.player_names[msg.current_controller];
    const auto card_name   = name_from_code(msg.code);
    const auto location    = format_location(msg.current_location, msg.current_sequence);

    return singleton( "玩家 _%s_ 盖放卡片 **%s** 于 **%s** "
                    , player_name
                    , card_name
                    , location);
  }

  ON_MESSAGE(CoreMsg_CHAINING) {
    const auto player_name = cfg.player_names[msg.chain_controller];
    const auto card_name   = name_from_code(msg.code);
    const auto location    = format_location(msg.chain_location, msg.chain_sequence);
    const auto c           = core_card_data::default_core_card_storage()
      ->lookup.find(msg.code)->second;

    const auto monster = !!(c.type & TYPE_MONSTER);

    const auto &desc = c.desc;
    auto lines = singleton( "玩家 _%s_ 发动 **%s** %s于 **%s** "
                          , player_name
                          , card_name
                          , monster ? "的效果" : ""
                          , location);
    Str::size_type f = 0, s = 0;
    const auto sep = "\r\n";
    while ((s = desc.find_first_not_of(sep, f)) != Str::npos) {
      f = desc.find_first_of(sep, s);
      lines.push_back("   > " + desc.substr(s, f - s));
    }

    return lines;
  }

  template <typename T>
  Seq<Str>
  operator ()(const T &) {
    return { };
  }
};

Seq<Str>
translate( const core_msg::CoreMsg &msg
         , const StoryTellerConfig &cfg)
{
  StoryTeller teller { cfg, core_msg::CoreMsg_HINT { } };
  return std::visit(teller, msg);
}

} // namespace ri::story

