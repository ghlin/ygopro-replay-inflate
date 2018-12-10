SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(core)

INCLUDE_DIRECTORIES(../lua)

SET(CORE_SRC
  ../core/scriptlib.cpp
  ../core/libdebug.cpp
  ../core/operations.cpp
  ../core/libgroup.cpp
  ../core/libduel.cpp
  ../core/interpreter.cpp
  ../core/mem.cpp
  ../core/playerop.cpp
  ../core/group.cpp
  ../core/processor.cpp
  ../core/card.cpp
  ../core/effect.cpp
  ../core/libcard.cpp
  ../core/duel.cpp
  ../core/libeffect.cpp
  ../core/field.cpp
  ../core/ocgapi.cpp)

ADD_LIBRARY(core STATIC ${CORE_SRC})

