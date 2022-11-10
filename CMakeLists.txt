cmake_minimum_required(VERSION 3.14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

project(math)

if(BUILD_TESTING)
  enable_testing()
  find_package(googletest REQUIRED)
  add_executable(math_test test/test.cpp)
  target_link_libraries(math_test PRIVATE gtest_main)
  gtest_discover_tests(math_test)
endif()
