add_library(math_geo INTERFACE)
target_include_directories(math_geo INTERFACE include)

if(BUILD_TESTING)
  add_executable(math_geo_test test/point_test.cpp)
  target_link_libraries(math_geo_test PRIVATE math_geo math_testing Catch2::Catch2WithMain)
  catch_discover_tests(math_geo_test)
endif()
