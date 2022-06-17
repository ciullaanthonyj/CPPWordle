# CMakeList.txt : CMake project for CPPWordle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CPPWordle "CPPWordle.cc"  "Word.cc" "Game.cc" "Word.h" "Game.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPPWordle PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
