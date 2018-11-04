# -std=c++17
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_SUBDIRECTORY(3rd-part/core.cmake)
ADD_SUBDIRECTORY(3rd-part/lua)
ADD_SUBDIRECTORY(3rd-part/lzma)

SET(APP_SRC
  app.cc
  options.cc
  replay/replay-machine.cc
  replay/parse-meta.cc
  replay/handle-message.cc
  replay/load-core-cards.cc
  support/file-io.cc
  core-msg/unpack.cc
  core-msg/dump.cc)

ADD_EXECUTABLE(app ${APP_SRC})

FIND_LIBRARY(sqlite3 REQUIRED)

TARGET_LINK_LIBRARIES(app core lua lzma sqlite3)

SET_TARGET_PROPERTIES(app PROPERTIES
  OUTPUT_NAME ${PROJECT_OUTPUT_NAME}
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

INSTALL(TARGETS app DESTINATION bin)
