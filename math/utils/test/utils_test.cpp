#include <math/utils.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("test `math::mod`") {
  SECTION("normal case") {
    CHECK(math::mod(5, 2) == 1);
    CHECK(math::mod(4.75, 1.5) == 0.25);
  }
  SECTION("cross type case") {
    CHECK(math::mod(5, 1.5) == 0.5);
    CHECK(math::mod(4.75, 2) == 0.75);
  }
}
