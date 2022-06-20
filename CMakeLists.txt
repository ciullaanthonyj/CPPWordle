# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)


project ("CPPWordle")


add_executable (CPPWordle "src/CPPWordle.cpp" "src/Game.hpp" "src/Game.cpp" "src/Output.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPPWordle PROPERTY CXX_STANDARD 20)
endif()
