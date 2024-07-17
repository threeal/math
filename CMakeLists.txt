cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(math)

option(MATH_ENABLE_TESTS "Enable test targets.")

include(cmake/CPM.cmake)
cpmaddpackage(
  GITHUB_REPOSITORY TheLartians/Format.cmake
  VERSION 1.7.3
  OPTIONS "FORMAT_SKIP_CMAKE ON"
)

if(MATH_ENABLE_TESTS)
  enable_testing()

  cpmaddpackage(gh:catchorg/Catch2@3.6.0)
  include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage -g -O0")

  add_subdirectory(math/testing)
endif()

add_subdirectory(math/geo)
add_subdirectory(math/utils)

add_subdirectory(math/limit)
