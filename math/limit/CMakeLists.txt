add_library(math_limit INTERFACE)
target_include_directories(math_limit INTERFACE include)
target_link_libraries(math_limit INTERFACE math_utils)

if(MATH_ENABLE_TESTS)
  add_executable(math_limit_test test/limit_test.cpp)
  target_link_libraries(math_limit_test PRIVATE math_limit math_testing Catch2::Catch2WithMain)
  catch_discover_tests(math_limit_test)
endif()
