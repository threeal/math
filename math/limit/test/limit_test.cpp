#include <math/limit.hpp>
#include <math/testing/tests.hpp>
#include <catch2/catch_test_macros.hpp>

#define L(MIN, MAX) math::make_limit(MIN, MAX)

TEST_CASE("test `math::make_limit`") {
  const auto limit = math::make_limit(-1, 1);
  CHECK(limit.min == -1);
  CHECK(limit.max == 1);
}

TEST_CASE("test `std::ostream` operation of `math::Limit`") {
  math::testing::OstreamTests()
    .test(L(-1, 1), "{min: -1, max: 1}");
}

TEST_CASE("test equality operation of `math::Limit`") {
  math::testing::EqualityTests()
    .test(L(-1, 1), L(-1, 1), true)
    .test(L(0, 1), L(-1, 1), false)
    .test(L(-1, 0), L(-1, -1), false)
    .test(L(0, 0), L(-1, 1), false)
    .test(L(-1, 1), L(-1.0, 1.0), true)
    .test(L(0, 1), L(-1.0, 1.0), false);
}

TEST_CASE("test `normalize` function of `math::Limit`") {
  CHECK(L(-1, 1).normalize() == L(-1, 1));
  CHECK(L(1, -1).normalize() == L(-1, 1));
}

TEST_CASE("test `center` function of `math::Limit`") {
  CHECK(L(-1, 1).center() == 0);
  CHECK(L(0, 5).center() == 2);
  CHECK(L(0.0, 5.0).center() == 2.5);
}

TEST_CASE("test `range` function of `math::Limit`") {
  CHECK(L(-1, 1).range() == 2);
}

namespace {

class InsideOutsideTests : public math::testing::BaseTests {
 public:
  template<typename LT, typename RT>
  InsideOutsideTests& test(const math::Limit<LT>& limit, const RT& val, bool is_inside) {
    INFO("Test number " << idx);
    CHECK(limit.is_inside(val) == is_inside);
    CHECK(limit.is_outside(val) != is_inside);
    return next<InsideOutsideTests>();
  }
};
}

TEST_CASE("test `is_inside` and `is_outside` functions of `math::Limit`") {
  SECTION("inside case") {
    InsideOutsideTests()
      .test(L(-1, 1), 0, true)
      .test(L(-1, 1), -1, true)
      .test(L(-1, 1), 1, true);
  }
  SECTION("outside case") {
    InsideOutsideTests()
      .test(L(-1, 1), -2, false)
      .test(L(-1, 1), 3, false);
  }
  SECTION("inverted min max case") {
    InsideOutsideTests()
      .test(L(1, -1), 0, true)
      .test(L(1, -1), -2, false)
      .test(L(1, -1), 3, false);
  }
  SECTION("cross type case") {
    InsideOutsideTests()
      .test(L(-1, 1), 0.5, true)
      .test(L(-1, 1), 2.5, false)
      .test(L(-0.5, 1.5), 0, true)
      .test(L(-0.5, 1.5), -1, false);
  }
}

TEST_CASE("test `clamp` function of `math::Limit`") {
  SECTION("normal case") {
    CHECK(L(-1, 1).clamp(0) == 0);
    CHECK(L(-1, 1).clamp(-2) == -1);
    CHECK(L(-1, 1).clamp(3) == 1);
  }
  SECTION("inverted min max case") {
    CHECK(L(1, -1).clamp(0) == 0);
    CHECK(L(1, -1).clamp(-2) == -1);
    CHECK(L(1, -1).clamp(3) == 1);
  }
  SECTION("cross type case") {
    CHECK(L(-1, 1).clamp(0.2) == 0);
    CHECK(L(-1, 1).clamp(-2.2) == -1);
    CHECK(L(-0.5, 1.5).clamp(1) == 1.0);
    CHECK(L(-0.5, 1.5).clamp(2) == 1.5);
  }
}

TEST_CASE("test `fold` function of `math::Limit`") {
  SECTION("normal case") {
    CHECK(L(-2, 2).fold(0) == 0);
    CHECK(L(-2, 2).fold(5) == 1);
    CHECK(L(-2, 2).fold(-5) == -1);
  }
  SECTION("floating point case") {
    CHECK(L(-1.5, 2.75).fold(0.5) == 0.5);
    CHECK(L(-1.5, 2.75).fold(5.75) == 1.5);
    CHECK(L(-1.5, 2.75).fold(-9.25) == -0.75);
  }
  SECTION("inverted min max case") {
    CHECK(L(2, -2).fold(0) == 0);
    CHECK(L(2, -2).fold(5) == 1);
    CHECK(L(2, -2).fold(-5) == -1);
  }
  SECTION("cross type case") {
    CHECK(L(-2, 2).fold(0.2) == 0);
    CHECK(L(-2, 2).fold(5.2) == 1);
    CHECK(L(-1.5, 2.75).fold(0) == 0);
    CHECK(L(-1.5, 2.75).fold(-9) == -0.5);
  }
}
