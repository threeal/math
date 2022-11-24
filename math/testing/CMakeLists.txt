add_library(math_testing INTERFACE)
target_include_directories(math_testing INTERFACE include)
target_link_libraries(math_testing INTERFACE gtest)

if(BUILD_TESTING)
  add_executable(math_testing_test test/tests_test.cpp)
  target_link_libraries(math_testing_test PRIVATE math_testing gtest_main)
  gtest_discover_tests(math_testing_test)
endif()
