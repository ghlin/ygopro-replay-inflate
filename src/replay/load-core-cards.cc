#include "load-core-cards.h"

#include <sqlite3.h>

namespace ri::replay {

Seq<card_data>
load_core_cards(const Str &ygopro_root_path)
{
  ::sqlite3      *db   = nullptr;
  ::sqlite3_stmt *stmt = nullptr;

  struct defer_helper {
    std::function<void (void)> rm;
    defer_helper(std::function<void (void)> &&rm): rm(std::move(rm)) { }
    ~defer_helper() { rm(); }
  };

  defer_helper defer([&db, &stmt]
                     {
                       if (stmt) ::sqlite3_finalize(stmt);
                       ::sqlite3_close(db);
                     });

  const auto cards_cdb_path = ygopro_root_path + "/cards.cdb";

  if (::sqlite3_open_v2(cards_cdb_path.c_str(), &db, SQLITE_OPEN_READONLY, 0) != SQLITE_OK) {
    std::fprintf( stderr
                , "[ERROR] failed to open %s as sqlite3 databse: %s\n"
                  "        is %s really your YGOPRO folder?\n"
                , cards_cdb_path.c_str()
                , ::sqlite3_errmsg(db)
                , ygopro_root_path.c_str());

    throw std::runtime_error("Cannot open cards.cdb as sqlite3 database");
  }

  // no need to load card text here
  const char *sql = R"(SELECT * FROM datas)";
  if (::sqlite3_prepare_v2(db, sql, -1, &stmt, 0) != SQLITE_OK) {
    std::fprintf( stderr
                , "[ERROR] failed to load card info (error execute sql `%s`): %s\n"
                , sql
                , ::sqlite3_errmsg(db));

    throw std::runtime_error("Cannot load card info");
  }

  Seq<card_data> records;

  for (int step = 0; (step = ::sqlite3_step(stmt)) != SQLITE_DONE; ) {
    if (step == SQLITE_BUSY || step == SQLITE_ERROR || step == SQLITE_MISUSE) {
      std::fprintf( stderr
                  , "[ERROR] failed to load card info (error step stmt): %s\n"
                  , ::sqlite3_errmsg(db));

      throw std::runtime_error("Cannot load card info");
    }

    if (step != SQLITE_ROW) continue; // don't care.

    card_data c;

    c.code      = ::sqlite3_column_int(stmt, 0);
    // OT:        ::sqlite3_column_int(stmt, 1);
    c.alias     = ::sqlite3_column_int(stmt, 2);
    c.setcode   = ::sqlite3_column_int64(stmt, 3);
    c.type      = ::sqlite3_column_int(stmt, 4);
    c.attack    = ::sqlite3_column_int(stmt, 5);
    c.defense   = ::sqlite3_column_int(stmt, 6);
    c.level     = ::sqlite3_column_int(stmt, 7);
    c.race      = ::sqlite3_column_int(stmt, 8);
    c.attribute = ::sqlite3_column_int(stmt, 9);
    // CATEGORY:  ::sqlite3_column_int(stmt, 10);

    // decompose some reused fileds.
    if (c.type & TYPE_LINK) {
      c.link_marker = c.defense;
      c.defense     = 0;
    } else {
      c.link_marker = 0;
    }

    c.lscale = (c.level >> 24) & 0xff;
    c.rscale = (c.level >> 16) & 0xff;
    c.level  = c.level         & 0xff;

    records.push_back(c);
  }

  return records;
}

CoreCardStorage
make_core_card_storage(const Seq<card_data> &cards)
{
  CoreCardStorage cc;
  for (const auto &c: cards) {
    cc.lookup[c.code] = c;
  }

  return cc;
}


} // namespace ri::replay
