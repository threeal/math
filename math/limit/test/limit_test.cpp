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
