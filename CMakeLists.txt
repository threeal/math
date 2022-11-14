cmake_minimum_required(VERSION 3.14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
set(CMAKE_CXX_STANDARD 14)

project(math)

if(BUILD_TESTING)
  enable_testing()
  find_package(googletest REQUIRED)
endif()

add_subdirectory(math/geo)
