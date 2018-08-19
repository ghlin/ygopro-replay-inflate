/* !!! Generated code, DO NOT EDIT !!! */

CoreMsg_RETRY
unpack_CoreMsg_RETRY(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_RETRY out;
  return out;
}

CoreMsg_HINT
unpack_CoreMsg_HINT(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_HINT out;
  out.type = buffer_next<u8>(in, end, "(type / u8)", __LINE__, __func__);
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.data = buffer_next<u32>(in, end, "(data / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_WIN
unpack_CoreMsg_WIN(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_WIN out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.type = buffer_next<u8>(in, end, "(type / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_WAITING
unpack_CoreMsg_WAITING(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_WAITING out;
  return out;
}

CoreMsg_START
unpack_CoreMsg_START(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_START out;
  out.player_type = buffer_next<u8>(in, end, "(player_type / u8)", __LINE__, __func__);
  out.player0_lp = buffer_next<u32>(in, end, "(player0_lp / u32)", __LINE__, __func__);
  out.player1_lp = buffer_next<u32>(in, end, "(player1_lp / u32)", __LINE__, __func__);
  out.player0_deck_count = buffer_next<u16>(in, end, "(player0_deck_count / u16)", __LINE__, __func__);
  out.player0_extra_count = buffer_next<u16>(in, end, "(player0_extra_count / u16)", __LINE__, __func__);
  out.player1_deck_count = buffer_next<u16>(in, end, "(player1_deck_count / u16)", __LINE__, __func__);
  out.player1_extra_count = buffer_next<u16>(in, end, "(player1_extra_count / u16)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_BATTLECMD
unpack_CoreMsg_SELECT_BATTLECMD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_BATTLECMD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto candidates1 = buffer_next<u8>(in, end, "(candidates1 / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates1; ++i) {
    CoreMsg_SELECT_BATTLECMD::Candidate1 unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.description = buffer_next<u32>(in, end, "(description / u32)", __LINE__, __func__);
    out.candidates1.emplace_back(std::move(unpacking));
  }
  const auto candidates2 = buffer_next<u8>(in, end, "(candidates2 / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates2; ++i) {
    CoreMsg_SELECT_BATTLECMD::Candidate2 unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    out.candidates2.emplace_back(std::move(unpacking));
  }
  out.to_main2_phase = buffer_next<u8>(in, end, "(to_main2_phase / u8)", __LINE__, __func__);
  out.to_end_phase = buffer_next<u8>(in, end, "(to_end_phase / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_IDLECMD
unpack_CoreMsg_SELECT_IDLECMD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_IDLECMD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto summon_candidates = buffer_next<u8>(in, end, "(summon_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != summon_candidates; ++i) {
    CoreMsg_SELECT_IDLECMD::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.summon_candidates.emplace_back(std::move(unpacking));
  }
  const auto spsummon_candidates = buffer_next<u8>(in, end, "(spsummon_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != spsummon_candidates; ++i) {
    CoreMsg_SELECT_IDLECMD::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.spsummon_candidates.emplace_back(std::move(unpacking));
  }
  const auto reposition_candidates = buffer_next<u8>(in, end, "(reposition_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != reposition_candidates; ++i) {
    CoreMsg_SELECT_IDLECMD::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.reposition_candidates.emplace_back(std::move(unpacking));
  }
  const auto mset_candidates = buffer_next<u8>(in, end, "(mset_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != mset_candidates; ++i) {
    CoreMsg_SELECT_IDLECMD::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.mset_candidates.emplace_back(std::move(unpacking));
  }
  const auto sset_candidates = buffer_next<u8>(in, end, "(sset_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != sset_candidates; ++i) {
    CoreMsg_SELECT_IDLECMD::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.sset_candidates.emplace_back(std::move(unpacking));
  }
  const auto active_candidates = buffer_next<u8>(in, end, "(active_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != active_candidates; ++i) {
    CoreMsg_SELECT_IDLECMD::ActiveCandidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.desc = buffer_next<u32>(in, end, "(desc / u32)", __LINE__, __func__);
    out.active_candidates.emplace_back(std::move(unpacking));
  }
  out.to_battle_phase = buffer_next<u8>(in, end, "(to_battle_phase / u8)", __LINE__, __func__);
  out.to_end_phase = buffer_next<u8>(in, end, "(to_end_phase / u8)", __LINE__, __func__);
  out.can_shuffle = buffer_next<u8>(in, end, "(can_shuffle / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_EFFECTYN
unpack_CoreMsg_SELECT_EFFECTYN(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_EFFECTYN out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out._ignore_ = buffer_next<u8>(in, end, "(_ignore_ / u8)", __LINE__, __func__);
  out.desc = buffer_next<u32>(in, end, "(desc / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_YESNO
unpack_CoreMsg_SELECT_YESNO(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_YESNO out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.desc = buffer_next<u32>(in, end, "(desc / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_OPTION
unpack_CoreMsg_SELECT_OPTION(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_OPTION out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto candidates = buffer_next<u8>(in, end, "(candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates; ++i) {
    CoreMsg_SELECT_OPTION::Candidate unpacking;
    unpacking.option_id = buffer_next<u8>(in, end, "(option_id / u8)", __LINE__, __func__);
    out.candidates.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SELECT_CARD
unpack_CoreMsg_SELECT_CARD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_CARD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.cancelable = buffer_next<u8>(in, end, "(cancelable / u8)", __LINE__, __func__);
  out.select_min = buffer_next<u8>(in, end, "(select_min / u8)", __LINE__, __func__);
  out.select_max = buffer_next<u8>(in, end, "(select_max / u8)", __LINE__, __func__);
  const auto candidates = buffer_next<u8>(in, end, "(candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates; ++i) {
    CoreMsg_SELECT_CARD::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    out.candidates.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SELECT_UNSELECT_CARD
unpack_CoreMsg_SELECT_UNSELECT_CARD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_UNSELECT_CARD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.finishable = buffer_next<u8>(in, end, "(finishable / u8)", __LINE__, __func__);
  out.cancelable = buffer_next<u8>(in, end, "(cancelable / u8)", __LINE__, __func__);
  out.select_min = buffer_next<u8>(in, end, "(select_min / u8)", __LINE__, __func__);
  out.select_max = buffer_next<u8>(in, end, "(select_max / u8)", __LINE__, __func__);
  const auto candidates1 = buffer_next<u8>(in, end, "(candidates1 / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates1; ++i) {
    CoreMsg_SELECT_UNSELECT_CARD::Candidate1 unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    out.candidates1.emplace_back(std::move(unpacking));
  }
  const auto candidates2 = buffer_next<u8>(in, end, "(candidates2 / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates2; ++i) {
    CoreMsg_SELECT_UNSELECT_CARD::Candidate2 unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    out.candidates2.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SELECT_CHAIN
unpack_CoreMsg_SELECT_CHAIN(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_CHAIN out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto candidates = buffer_next<u8>(in, end, "(candidates / u8)", __LINE__, __func__);
  out.spe_count = buffer_next<u8>(in, end, "(spe_count / u8)", __LINE__, __func__);
  out.forced = buffer_next<u8>(in, end, "(forced / u8)", __LINE__, __func__);
  out.hint0 = buffer_next<u32>(in, end, "(hint0 / u32)", __LINE__, __func__);
  out.hint1 = buffer_next<u32>(in, end, "(hint1 / u32)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates; ++i) {
    CoreMsg_SELECT_CHAIN::Candidate unpacking;
    unpacking.flag = buffer_next<u8>(in, end, "(flag / u8)", __LINE__, __func__);
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    unpacking.desc = buffer_next<u32>(in, end, "(desc / u32)", __LINE__, __func__);
    out.candidates.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SELECT_PLACE
unpack_CoreMsg_SELECT_PLACE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_PLACE out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.select_min = buffer_next<u8>(in, end, "(select_min / u8)", __LINE__, __func__);
  out.selectable_field = buffer_next<u32>(in, end, "(selectable_field / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_DISFIELD
unpack_CoreMsg_SELECT_DISFIELD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_DISFIELD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.select_min = buffer_next<u8>(in, end, "(select_min / u8)", __LINE__, __func__);
  out.selectable_field = buffer_next<u32>(in, end, "(selectable_field / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_POSITION
unpack_CoreMsg_SELECT_POSITION(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_POSITION out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.positions = buffer_next<u8>(in, end, "(positions / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SELECT_TRIBUTE
unpack_CoreMsg_SELECT_TRIBUTE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_TRIBUTE out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.cancelable = buffer_next<u8>(in, end, "(cancelable / u8)", __LINE__, __func__);
  out.select_min = buffer_next<u8>(in, end, "(select_min / u8)", __LINE__, __func__);
  out.select_max = buffer_next<u8>(in, end, "(select_max / u8)", __LINE__, __func__);
  const auto candidates = buffer_next<u8>(in, end, "(candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates; ++i) {
    CoreMsg_SELECT_TRIBUTE::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.operation_param = buffer_next<u8>(in, end, "(operation_param / u8)", __LINE__, __func__);
    out.candidates.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SELECT_COUNTER
unpack_CoreMsg_SELECT_COUNTER(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_COUNTER out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.select_counter_type = buffer_next<u16>(in, end, "(select_counter_type / u16)", __LINE__, __func__);
  out.select_counter_count = buffer_next<u16>(in, end, "(select_counter_count / u16)", __LINE__, __func__);
  const auto candidates = buffer_next<u8>(in, end, "(candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates; ++i) {
    CoreMsg_SELECT_COUNTER::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.operation_param = buffer_next<u16>(in, end, "(operation_param / u16)", __LINE__, __func__);
    out.candidates.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SELECT_SUM
unpack_CoreMsg_SELECT_SUM(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SELECT_SUM out;
  out.select_mode = buffer_next<u8>(in, end, "(select_mode / u8)", __LINE__, __func__);
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.select_sumval = buffer_next<u32>(in, end, "(select_sumval / u32)", __LINE__, __func__);
  out.select_min = buffer_next<u8>(in, end, "(select_min / u8)", __LINE__, __func__);
  out.select_max = buffer_next<u8>(in, end, "(select_max / u8)", __LINE__, __func__);
  const auto must_select_candidates = buffer_next<u8>(in, end, "(must_select_candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != must_select_candidates; ++i) {
    CoreMsg_SELECT_SUM::MustSelect unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.operation_param = buffer_next<u32>(in, end, "(operation_param / u32)", __LINE__, __func__);
    out.must_select_candidates.emplace_back(std::move(unpacking));
  }
  const auto candidates = buffer_next<u8>(in, end, "(candidates / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != candidates; ++i) {
    CoreMsg_SELECT_SUM::Candidate unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.operation_param = buffer_next<u32>(in, end, "(operation_param / u32)", __LINE__, __func__);
    out.candidates.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SORT_CARD
unpack_CoreMsg_SORT_CARD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SORT_CARD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_SORT_CARD::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SORT_CHAIN
unpack_CoreMsg_SORT_CHAIN(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SORT_CHAIN out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_SORT_CHAIN::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_CONFIRM_DECKTOP
unpack_CoreMsg_CONFIRM_DECKTOP(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CONFIRM_DECKTOP out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_CONFIRM_DECKTOP::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_CONFIRM_EXTRATOP
unpack_CoreMsg_CONFIRM_EXTRATOP(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CONFIRM_EXTRATOP out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_CONFIRM_EXTRATOP::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_CONFIRM_CARDS
unpack_CoreMsg_CONFIRM_CARDS(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CONFIRM_CARDS out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_CONFIRM_CARDS::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SHUFFLE_DECK
unpack_CoreMsg_SHUFFLE_DECK(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SHUFFLE_DECK out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_REFRESH_DECK
unpack_CoreMsg_REFRESH_DECK(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_REFRESH_DECK out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SWAP_GRAVE_DECK
unpack_CoreMsg_SWAP_GRAVE_DECK(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SWAP_GRAVE_DECK out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SHUFFLE_SET_CARD
unpack_CoreMsg_SHUFFLE_SET_CARD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SHUFFLE_SET_CARD out;
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  const auto count = buffer_next<u8>(in, end, "(count / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != count; ++i) {
    CoreMsg_SHUFFLE_SET_CARD::Card unpacking;
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.ignore = buffer_next<u8>(in, end, "(ignore / u8)", __LINE__, __func__);
    out.cards1.emplace_back(std::move(unpacking));
  }
  for (unsigned i = 0; i != count; ++i) {
    CoreMsg_SHUFFLE_SET_CARD::Card unpacking;
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.ignore = buffer_next<u8>(in, end, "(ignore / u8)", __LINE__, __func__);
    out.cards2.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SHUFFLE_HAND
unpack_CoreMsg_SHUFFLE_HAND(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SHUFFLE_HAND out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_SHUFFLE_HAND::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_SHUFFLE_EXTRA
unpack_CoreMsg_SHUFFLE_EXTRA(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SHUFFLE_EXTRA out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_SHUFFLE_EXTRA::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_REVERSE_DECK
unpack_CoreMsg_REVERSE_DECK(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_REVERSE_DECK out;
  return out;
}

CoreMsg_DECK_TOP
unpack_CoreMsg_DECK_TOP(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_DECK_TOP out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_NEW_TURN
unpack_CoreMsg_NEW_TURN(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_NEW_TURN out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_NEW_PHASE
unpack_CoreMsg_NEW_PHASE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_NEW_PHASE out;
  out.phase = buffer_next<u16>(in, end, "(phase / u16)", __LINE__, __func__);
  return out;
}

CoreMsg_MOVE
unpack_CoreMsg_MOVE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_MOVE out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.previous_controller = buffer_next<u8>(in, end, "(previous_controller / u8)", __LINE__, __func__);
  out.previous_location = buffer_next<u8>(in, end, "(previous_location / u8)", __LINE__, __func__);
  out.previous_sequence = buffer_next<u8>(in, end, "(previous_sequence / u8)", __LINE__, __func__);
  out.previous_position = buffer_next<u8>(in, end, "(previous_position / u8)", __LINE__, __func__);
  out.current_controller = buffer_next<u8>(in, end, "(current_controller / u8)", __LINE__, __func__);
  out.current_location = buffer_next<u8>(in, end, "(current_location / u8)", __LINE__, __func__);
  out.current_sequence = buffer_next<u8>(in, end, "(current_sequence / u8)", __LINE__, __func__);
  out.current_position = buffer_next<u8>(in, end, "(current_position / u8)", __LINE__, __func__);
  out.reason = buffer_next<u32>(in, end, "(reason / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_POS_CHANGE
unpack_CoreMsg_POS_CHANGE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_POS_CHANGE out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.current_controller = buffer_next<u8>(in, end, "(current_controller / u8)", __LINE__, __func__);
  out.current_location = buffer_next<u8>(in, end, "(current_location / u8)", __LINE__, __func__);
  out.current_sequence = buffer_next<u8>(in, end, "(current_sequence / u8)", __LINE__, __func__);
  out.previous_position = buffer_next<u8>(in, end, "(previous_position / u8)", __LINE__, __func__);
  out.current_position = buffer_next<u8>(in, end, "(current_position / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SET
unpack_CoreMsg_SET(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SET out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.current_controller = buffer_next<u8>(in, end, "(current_controller / u8)", __LINE__, __func__);
  out.current_location = buffer_next<u8>(in, end, "(current_location / u8)", __LINE__, __func__);
  out.current_sequence = buffer_next<u8>(in, end, "(current_sequence / u8)", __LINE__, __func__);
  out.current_position = buffer_next<u8>(in, end, "(current_position / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SWAP
unpack_CoreMsg_SWAP(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SWAP out;
  out.code1 = buffer_next<u32>(in, end, "(code1 / u32)", __LINE__, __func__);
  out.controller1 = buffer_next<u8>(in, end, "(controller1 / u8)", __LINE__, __func__);
  out.location1 = buffer_next<u8>(in, end, "(location1 / u8)", __LINE__, __func__);
  out.sequence1 = buffer_next<u8>(in, end, "(sequence1 / u8)", __LINE__, __func__);
  out.position1 = buffer_next<u8>(in, end, "(position1 / u8)", __LINE__, __func__);
  out.code2 = buffer_next<u32>(in, end, "(code2 / u32)", __LINE__, __func__);
  out.controller2 = buffer_next<u8>(in, end, "(controller2 / u8)", __LINE__, __func__);
  out.location2 = buffer_next<u8>(in, end, "(location2 / u8)", __LINE__, __func__);
  out.sequence2 = buffer_next<u8>(in, end, "(sequence2 / u8)", __LINE__, __func__);
  out.position2 = buffer_next<u8>(in, end, "(position2 / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_FIELD_DISABLED
unpack_CoreMsg_FIELD_DISABLED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_FIELD_DISABLED out;
  out.disabled_fields = buffer_next<u32>(in, end, "(disabled_fields / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_SUMMONING
unpack_CoreMsg_SUMMONING(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SUMMONING out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.position = buffer_next<u8>(in, end, "(position / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SUMMONED
unpack_CoreMsg_SUMMONED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SUMMONED out;
  return out;
}

CoreMsg_SPSUMMONING
unpack_CoreMsg_SPSUMMONING(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SPSUMMONING out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.position = buffer_next<u8>(in, end, "(position / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_SPSUMMONED
unpack_CoreMsg_SPSUMMONED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_SPSUMMONED out;
  return out;
}

CoreMsg_FLIPSUMMONING
unpack_CoreMsg_FLIPSUMMONING(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_FLIPSUMMONING out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.position = buffer_next<u8>(in, end, "(position / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_FLIPSUMMONED
unpack_CoreMsg_FLIPSUMMONED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_FLIPSUMMONED out;
  return out;
}

CoreMsg_CHAINING
unpack_CoreMsg_CHAINING(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAINING out;
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  out.previous_chain_controller = buffer_next<u8>(in, end, "(previous_chain_controller / u8)", __LINE__, __func__);
  out.previous_chain_location = buffer_next<u8>(in, end, "(previous_chain_location / u8)", __LINE__, __func__);
  out.previous_chain_sequence = buffer_next<u8>(in, end, "(previous_chain_sequence / u8)", __LINE__, __func__);
  out.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
  out.chain_controller = buffer_next<u8>(in, end, "(chain_controller / u8)", __LINE__, __func__);
  out.chain_location = buffer_next<u8>(in, end, "(chain_location / u8)", __LINE__, __func__);
  out.chain_sequence = buffer_next<u8>(in, end, "(chain_sequence / u8)", __LINE__, __func__);
  out.desc = buffer_next<u32>(in, end, "(desc / u32)", __LINE__, __func__);
  out.chain_param = buffer_next<u8>(in, end, "(chain_param / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CHAINED
unpack_CoreMsg_CHAINED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAINED out;
  out.chain_param = buffer_next<u8>(in, end, "(chain_param / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CHAIN_SOLVING
unpack_CoreMsg_CHAIN_SOLVING(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAIN_SOLVING out;
  out.chain_param = buffer_next<u8>(in, end, "(chain_param / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CHAIN_SOLVED
unpack_CoreMsg_CHAIN_SOLVED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAIN_SOLVED out;
  out.chain_param = buffer_next<u8>(in, end, "(chain_param / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CHAIN_END
unpack_CoreMsg_CHAIN_END(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAIN_END out;
  return out;
}

CoreMsg_CHAIN_NEGATED
unpack_CoreMsg_CHAIN_NEGATED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAIN_NEGATED out;
  out.chain_param = buffer_next<u8>(in, end, "(chain_param / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CHAIN_DISABLED
unpack_CoreMsg_CHAIN_DISABLED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CHAIN_DISABLED out;
  out.chain_param = buffer_next<u8>(in, end, "(chain_param / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CARD_SELECTED
unpack_CoreMsg_CARD_SELECTED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CARD_SELECTED out;
  return out;
}

CoreMsg_RANDOM_SELECTED
unpack_CoreMsg_RANDOM_SELECTED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_RANDOM_SELECTED out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_RANDOM_SELECTED::Card unpacking;
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_BECOME_TARGET
unpack_CoreMsg_BECOME_TARGET(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_BECOME_TARGET out;
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_BECOME_TARGET::Card unpacking;
    unpacking.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
    unpacking.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
    unpacking.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
    unpacking.subsequence = buffer_next<u8>(in, end, "(subsequence / u8)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_DRAW
unpack_CoreMsg_DRAW(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_DRAW out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto cards = buffer_next<u8>(in, end, "(cards / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != cards; ++i) {
    CoreMsg_DRAW::Card unpacking;
    unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
    out.cards.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_DAMAGE
unpack_CoreMsg_DAMAGE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_DAMAGE out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_RECOVER
unpack_CoreMsg_RECOVER(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_RECOVER out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_LPUPDATE
unpack_CoreMsg_LPUPDATE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_LPUPDATE out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_PAY_LPCOST
unpack_CoreMsg_PAY_LPCOST(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_PAY_LPCOST out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_EQUIP
unpack_CoreMsg_EQUIP(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_EQUIP out;
  out.controller1 = buffer_next<u8>(in, end, "(controller1 / u8)", __LINE__, __func__);
  out.location1 = buffer_next<u8>(in, end, "(location1 / u8)", __LINE__, __func__);
  out.sequence1 = buffer_next<u8>(in, end, "(sequence1 / u8)", __LINE__, __func__);
  out.ignore1 = buffer_next<u8>(in, end, "(ignore1 / u8)", __LINE__, __func__);
  out.controller2 = buffer_next<u8>(in, end, "(controller2 / u8)", __LINE__, __func__);
  out.location2 = buffer_next<u8>(in, end, "(location2 / u8)", __LINE__, __func__);
  out.sequence2 = buffer_next<u8>(in, end, "(sequence2 / u8)", __LINE__, __func__);
  out.ignore2 = buffer_next<u8>(in, end, "(ignore2 / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_UNEQUIP
unpack_CoreMsg_UNEQUIP(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_UNEQUIP out;
  out.controller1 = buffer_next<u8>(in, end, "(controller1 / u8)", __LINE__, __func__);
  out.location1 = buffer_next<u8>(in, end, "(location1 / u8)", __LINE__, __func__);
  out.sequence1 = buffer_next<u8>(in, end, "(sequence1 / u8)", __LINE__, __func__);
  out.ignore1 = buffer_next<u8>(in, end, "(ignore1 / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CARD_TARGET
unpack_CoreMsg_CARD_TARGET(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CARD_TARGET out;
  out.controller1 = buffer_next<u8>(in, end, "(controller1 / u8)", __LINE__, __func__);
  out.location1 = buffer_next<u8>(in, end, "(location1 / u8)", __LINE__, __func__);
  out.sequence1 = buffer_next<u8>(in, end, "(sequence1 / u8)", __LINE__, __func__);
  out.ignore1 = buffer_next<u8>(in, end, "(ignore1 / u8)", __LINE__, __func__);
  out.controller2 = buffer_next<u8>(in, end, "(controller2 / u8)", __LINE__, __func__);
  out.location2 = buffer_next<u8>(in, end, "(location2 / u8)", __LINE__, __func__);
  out.sequence2 = buffer_next<u8>(in, end, "(sequence2 / u8)", __LINE__, __func__);
  out.ignore2 = buffer_next<u8>(in, end, "(ignore2 / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_CANCEL_TARGET
unpack_CoreMsg_CANCEL_TARGET(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CANCEL_TARGET out;
  out.controller1 = buffer_next<u8>(in, end, "(controller1 / u8)", __LINE__, __func__);
  out.location1 = buffer_next<u8>(in, end, "(location1 / u8)", __LINE__, __func__);
  out.sequence1 = buffer_next<u8>(in, end, "(sequence1 / u8)", __LINE__, __func__);
  out.ignore1 = buffer_next<u8>(in, end, "(ignore1 / u8)", __LINE__, __func__);
  out.controller2 = buffer_next<u8>(in, end, "(controller2 / u8)", __LINE__, __func__);
  out.location2 = buffer_next<u8>(in, end, "(location2 / u8)", __LINE__, __func__);
  out.sequence2 = buffer_next<u8>(in, end, "(sequence2 / u8)", __LINE__, __func__);
  out.ignore2 = buffer_next<u8>(in, end, "(ignore2 / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_ADD_COUNTER
unpack_CoreMsg_ADD_COUNTER(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ADD_COUNTER out;
  out.type = buffer_next<u16>(in, end, "(type / u16)", __LINE__, __func__);
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.count = buffer_next<u16>(in, end, "(count / u16)", __LINE__, __func__);
  return out;
}

CoreMsg_REMOVE_COUNTER
unpack_CoreMsg_REMOVE_COUNTER(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_REMOVE_COUNTER out;
  out.type = buffer_next<u16>(in, end, "(type / u16)", __LINE__, __func__);
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.count = buffer_next<u16>(in, end, "(count / u16)", __LINE__, __func__);
  return out;
}

CoreMsg_ATTACK
unpack_CoreMsg_ATTACK(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ATTACK out;
  out.atk_controller = buffer_next<u8>(in, end, "(atk_controller / u8)", __LINE__, __func__);
  out.atk_location = buffer_next<u8>(in, end, "(atk_location / u8)", __LINE__, __func__);
  out.atk_sequence = buffer_next<u8>(in, end, "(atk_sequence / u8)", __LINE__, __func__);
  out.atk_ignore = buffer_next<u8>(in, end, "(atk_ignore / u8)", __LINE__, __func__);
  out.def_controller = buffer_next<u8>(in, end, "(def_controller / u8)", __LINE__, __func__);
  out.def_location = buffer_next<u8>(in, end, "(def_location / u8)", __LINE__, __func__);
  out.def_sequence = buffer_next<u8>(in, end, "(def_sequence / u8)", __LINE__, __func__);
  out.def_ignore = buffer_next<u8>(in, end, "(def_ignore / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_BATTLE
unpack_CoreMsg_BATTLE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_BATTLE out;
  out.atk_controller = buffer_next<u8>(in, end, "(atk_controller / u8)", __LINE__, __func__);
  out.atk_location = buffer_next<u8>(in, end, "(atk_location / u8)", __LINE__, __func__);
  out.atk_sequence = buffer_next<u8>(in, end, "(atk_sequence / u8)", __LINE__, __func__);
  out.atk_subsequence = buffer_next<u8>(in, end, "(atk_subsequence / u8)", __LINE__, __func__);
  out.atk_atkvalue = buffer_next<u32>(in, end, "(atk_atkvalue / u32)", __LINE__, __func__);
  out.atk_defvalue = buffer_next<u32>(in, end, "(atk_defvalue / u32)", __LINE__, __func__);
  out.atk_ignore = buffer_next<u8>(in, end, "(atk_ignore / u8)", __LINE__, __func__);
  out.def_controller = buffer_next<u8>(in, end, "(def_controller / u8)", __LINE__, __func__);
  out.def_location = buffer_next<u8>(in, end, "(def_location / u8)", __LINE__, __func__);
  out.def_sequence = buffer_next<u8>(in, end, "(def_sequence / u8)", __LINE__, __func__);
  out.def_subsequence = buffer_next<u8>(in, end, "(def_subsequence / u8)", __LINE__, __func__);
  out.def_atkvalue = buffer_next<u32>(in, end, "(def_atkvalue / u32)", __LINE__, __func__);
  out.def_defvalue = buffer_next<u32>(in, end, "(def_defvalue / u32)", __LINE__, __func__);
  out.def_ignore = buffer_next<u8>(in, end, "(def_ignore / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_ATTACK_DISABLED
unpack_CoreMsg_ATTACK_DISABLED(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ATTACK_DISABLED out;
  return out;
}

CoreMsg_DAMAGE_STEP_START
unpack_CoreMsg_DAMAGE_STEP_START(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_DAMAGE_STEP_START out;
  return out;
}

CoreMsg_DAMAGE_STEP_END
unpack_CoreMsg_DAMAGE_STEP_END(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_DAMAGE_STEP_END out;
  return out;
}

CoreMsg_MISSED_EFFECT
unpack_CoreMsg_MISSED_EFFECT(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_MISSED_EFFECT out;
  out.ignore = buffer_next<u32>(in, end, "(ignore / u32)", __LINE__, __func__);
  out.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_TOSS_COIN
unpack_CoreMsg_TOSS_COIN(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_TOSS_COIN out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto tosses = buffer_next<u8>(in, end, "(tosses / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != tosses; ++i) {
    CoreMsg_TOSS_COIN::Result unpacking;
    unpacking.value = buffer_next<u8>(in, end, "(value / u8)", __LINE__, __func__);
    out.tosses.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_TOSS_DICE
unpack_CoreMsg_TOSS_DICE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_TOSS_DICE out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto tosses = buffer_next<u8>(in, end, "(tosses / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != tosses; ++i) {
    CoreMsg_TOSS_DICE::Result unpacking;
    unpacking.value = buffer_next<u8>(in, end, "(value / u8)", __LINE__, __func__);
    out.tosses.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_ROCK_PAPER_SCISSORS
unpack_CoreMsg_ROCK_PAPER_SCISSORS(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ROCK_PAPER_SCISSORS out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_HAND_RES
unpack_CoreMsg_HAND_RES(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_HAND_RES out;
  out.res = buffer_next<u8>(in, end, "(res / u8)", __LINE__, __func__);
  return out;
}

CoreMsg_ANNOUNCE_RACE
unpack_CoreMsg_ANNOUNCE_RACE(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ANNOUNCE_RACE out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.count = buffer_next<u8>(in, end, "(count / u8)", __LINE__, __func__);
  out.available = buffer_next<u32>(in, end, "(available / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_ANNOUNCE_ATTRIB
unpack_CoreMsg_ANNOUNCE_ATTRIB(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ANNOUNCE_ATTRIB out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.count = buffer_next<u8>(in, end, "(count / u8)", __LINE__, __func__);
  out.available = buffer_next<u32>(in, end, "(available / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_ANNOUNCE_CARD
unpack_CoreMsg_ANNOUNCE_CARD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ANNOUNCE_CARD out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.declarable_type = buffer_next<u32>(in, end, "(declarable_type / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_ANNOUNCE_NUMBER
unpack_CoreMsg_ANNOUNCE_NUMBER(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ANNOUNCE_NUMBER out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto numbers = buffer_next<u8>(in, end, "(numbers / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != numbers; ++i) {
    CoreMsg_ANNOUNCE_NUMBER::Announce unpacking;
    unpacking.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
    out.numbers.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_ANNOUNCE_CARD_FILTER
unpack_CoreMsg_ANNOUNCE_CARD_FILTER(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_ANNOUNCE_CARD_FILTER out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  const auto filters = buffer_next<u8>(in, end, "(filters / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != filters; ++i) {
    CoreMsg_ANNOUNCE_CARD_FILTER::Filter unpacking;
    unpacking.opcode = buffer_next<u32>(in, end, "(opcode / u32)", __LINE__, __func__);
    out.filters.emplace_back(std::move(unpacking));
  }
  return out;
}

CoreMsg_CARD_HINT
unpack_CoreMsg_CARD_HINT(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_CARD_HINT out;
  out.controller = buffer_next<u8>(in, end, "(controller / u8)", __LINE__, __func__);
  out.location = buffer_next<u8>(in, end, "(location / u8)", __LINE__, __func__);
  out.sequence = buffer_next<u8>(in, end, "(sequence / u8)", __LINE__, __func__);
  out.ignore = buffer_next<u8>(in, end, "(ignore / u8)", __LINE__, __func__);
  out.chtype = buffer_next<u8>(in, end, "(chtype / u8)", __LINE__, __func__);
  out.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_PLAYER_HINT
unpack_CoreMsg_PLAYER_HINT(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_PLAYER_HINT out;
  out.player = buffer_next<u8>(in, end, "(player / u8)", __LINE__, __func__);
  out.chtype = buffer_next<u8>(in, end, "(chtype / u8)", __LINE__, __func__);
  out.value = buffer_next<u32>(in, end, "(value / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_MATCH_KILL
unpack_CoreMsg_MATCH_KILL(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_MATCH_KILL out;
  out.match_kill = buffer_next<u32>(in, end, "(match_kill / u32)", __LINE__, __func__);
  return out;
}

CoreMsg_RELOAD_FIELD
unpack_CoreMsg_RELOAD_FIELD(buffer_ptr *in, buffer_ptr end)
{
  (void)in; (void)end;
  CoreMsg_RELOAD_FIELD out;
  out.duel_rule = buffer_next<u8>(in, end, "(duel_rule / u8)", __LINE__, __func__);
  for (unsigned i = 0; i != 4; ++i) {
    out.players[i].lp = buffer_next<u32>(in, end, "(lp / u32)", __LINE__, __func__);
    for (unsigned i = 0; i != 7; ++i) {
      const auto value = buffer_next<u8>(in, end, "(value / u8)", __LINE__, __func__);
      if (value) {
        std::optional<CoreMsg_RELOAD_FIELD::PlayersField::MCard::MValue> unpacking = CoreMsg_RELOAD_FIELD::PlayersField::MCard::MValue { };
        (*unpacking).position = buffer_next<u8>(in, end, "(position / u8)", __LINE__, __func__);
        (*unpacking).xyz_count = buffer_next<u8>(in, end, "(xyz_count / u8)", __LINE__, __func__);
        out.players[i].mzone_cards[i].value = std::move(unpacking);
      }
    }
    for (unsigned i = 0; i != 8; ++i) {
      const auto value = buffer_next<u8>(in, end, "(value / u8)", __LINE__, __func__);
      if (value) {
        std::optional<CoreMsg_RELOAD_FIELD::PlayersField::Card::Value> unpacking = CoreMsg_RELOAD_FIELD::PlayersField::Card::Value { };
        (*unpacking).position = buffer_next<u8>(in, end, "(position / u8)", __LINE__, __func__);
        out.players[i].cards[i].value = std::move(unpacking);
      }
    }
    out.players[i].deck_count = buffer_next<u8>(in, end, "(deck_count / u8)", __LINE__, __func__);
    out.players[i].hand_count = buffer_next<u8>(in, end, "(hand_count / u8)", __LINE__, __func__);
    out.players[i].grave_count = buffer_next<u8>(in, end, "(grave_count / u8)", __LINE__, __func__);
    out.players[i].banish_count = buffer_next<u8>(in, end, "(banish_count / u8)", __LINE__, __func__);
    out.players[i].extra_count = buffer_next<u8>(in, end, "(extra_count / u8)", __LINE__, __func__);
    out.players[i].extra_pendu_count = buffer_next<u8>(in, end, "(extra_pendu_count / u8)", __LINE__, __func__);
    const auto chains = buffer_next<u8>(in, end, "(chains / u8)", __LINE__, __func__);
    for (unsigned i = 0; i != chains; ++i) {
      CoreMsg_RELOAD_FIELD::PlayersField::Chain unpacking;
      unpacking.code = buffer_next<u32>(in, end, "(code / u32)", __LINE__, __func__);
      unpacking.previous_controller = buffer_next<u8>(in, end, "(previous_controller / u8)", __LINE__, __func__);
      unpacking.previous_location = buffer_next<u8>(in, end, "(previous_location / u8)", __LINE__, __func__);
      unpacking.previous_sequence = buffer_next<u8>(in, end, "(previous_sequence / u8)", __LINE__, __func__);
      unpacking.previous_subsequence = buffer_next<u8>(in, end, "(previous_subsequence / u8)", __LINE__, __func__);
      unpacking.current_controller = buffer_next<u8>(in, end, "(current_controller / u8)", __LINE__, __func__);
      unpacking.current_location = buffer_next<u8>(in, end, "(current_location / u8)", __LINE__, __func__);
      unpacking.current_sequence = buffer_next<u8>(in, end, "(current_sequence / u8)", __LINE__, __func__);
      unpacking.desc = buffer_next<u32>(in, end, "(desc / u32)", __LINE__, __func__);
      out.players[i].chains.emplace_back(std::move(unpacking));
    }
  }
  return out;
}

