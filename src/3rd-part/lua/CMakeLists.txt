PROJECT(lua)

SET(LUA_SRC
  ltm.c
  lbaselib.c
  lcode.c
  ldblib.c
  lzio.c
  lctype.c
  lvm.c
  lgc.c
  ldebug.c
  lmathlib.c
  ldo.c
  lstrlib.c
  luac.c
  llex.c
  lopcodes.c
  ltablib.c
  linit.c
  lua.c
  lcorolib.c
  lundump.c
  lparser.c
  ltable.c
  liolib.c
  lbitlib.c
  lfunc.c
  lmem.c
  ldump.c
  lauxlib.c
  lstring.c
  loadlib.c
  lapi.c
  loslib.c
  lutf8lib.c
  lstate.c
  lobject.c)

# Compile lua using C++ compiler
#
# see https://github.com/moecube/ygopro-core/commit/3c4fd547c47e0e2c73b0b7bcee0c9bd6210476b8#diff-519ef3cf5034fc82afc18516a6b856b1
SET_SOURCE_FILES_PROPERTIES(${LUA_SRC} PROPERTIES LANGUAGE CXX)

ADD_LIBRARY(lua STATIC ${LUA_SRC})
