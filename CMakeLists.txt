cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)

project(math)

include(cmake/CPM.cmake)
cpmaddpackage("gh:TheLartians/Format.cmake@1.7.3")

if(BUILD_TESTING)
  enable_testing()

  cpmaddpackage("gh:catchorg/Catch2@3.5.3")
  include("${Catch2_SOURCE_DIR}/extras/Catch.cmake")

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage -g -O0")

  add_subdirectory(math/testing)
endif()

add_subdirectory(math/geo)
add_subdirectory(math/utils)

add_subdirectory(math/limit)
