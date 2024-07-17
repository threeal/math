add_library(math_utils INTERFACE)
target_include_directories(math_utils INTERFACE include)

if(MATH_ENABLE_TESTS)
  add_executable(math_utils_test test/utils_test.cpp)
  target_link_libraries(math_utils_test PRIVATE math_utils Catch2::Catch2WithMain)
  catch_discover_tests(math_utils_test)
endif()
