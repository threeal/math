add_library(math_limit INTERFACE)
target_include_directories(math_limit INTERFACE include)

if(BUILD_TESTING)
  add_executable(math_limit_test test/limit_test.cpp)
  target_link_libraries(
    math_limit_test PRIVATE
    math_limit
    math_testing
    gtest_main
  )
  gtest_discover_tests(math_limit_test)
endif()
