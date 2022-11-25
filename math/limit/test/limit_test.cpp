#include <math/limit.hpp>
#include <math/testing/tests.hpp>
#include <gtest/gtest.h>

#define L(MIN, MAX) math::make_limit(MIN, MAX)

TEST(LimitTest, MakeLimit) {
  const auto limit = math::make_limit(-1, 1);
  EXPECT_EQ(limit.min, -1);
  EXPECT_EQ(limit.max, 1);
}

TEST(LimitTest, Ostream) {
  math::testing::OstreamTests()
    .test(L(-1, 1), "{min: -1, max: 1}");
}

TEST(LimitTest, Equality) {
  math::testing::EqualityTests()
    .test(L(-1, 1), L(-1, 1), true)
    .test(L(0, 1), L(-1, 1), false)
    .test(L(-1, 0), L(-1, -1), false)
    .test(L(0, 0), L(-1, 1), false)
    .test(L(-1, 1), L(-1.0, 1.0), true)
    .test(L(0, 1), L(-1.0, 1.0), false);
}

TEST(LimitTest, Center) {
  EXPECT_EQ(L(-1, 1).center(), 0);
  EXPECT_EQ(L(0, 5).center(), 2);
  EXPECT_EQ(L(0.0, 5.0).center(), 2.5);
}

TEST(LimitTest, Range) {
  EXPECT_EQ(L(-1, 1).range(), 2);
}

namespace {

class InsideOutsideTests : public math::testing::BaseTests {
 public:
  template<typename LT, typename RT>
  InsideOutsideTests& test(const math::Limit<LT>& limit, const RT& val, bool is_inside) {
    EXPECT_EQ(limit.is_inside(val), is_inside) << failed_message();
    EXPECT_EQ(limit.is_outside(val), !is_inside) << failed_message();
    return next<InsideOutsideTests>();
  }  // LCOV_EXCL_LINE
};
}

TEST(LimitTest, InsideOutside) {
  InsideOutsideTests()
    // test inside
    .test(L(-1, 1), 0, true)
    .test(L(-1, 1), -1, true)
    .test(L(-1, 1), 1, true)
    // test outside
    .test(L(-1, 1), -2, false)
    .test(L(-1, 1), 3, false)
    // test inverted min max
    .test(L(1, -1), 0, true)
    .test(L(1, -1), -2, false)
    .test(L(1, -1), 3, false)
    // test cross type
    .test(L(-1, 1), 0.5, true)
    .test(L(-1, 1), 2.5, false)
    .test(L(-0.5, 1.5), 0, true)
    .test(L(-0.5, 1.5), -1, false);
}
