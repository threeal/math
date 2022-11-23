#include <math/point.hpp>
#include <math/testing/arithmetic_tests.hpp>
#include <math/testing/equality_tests.hpp>
#include <math/testing/ostream_tests.hpp>
#include <gtest/gtest.h>

#define P2(x, y) math::make_point(x, y)

TEST(PointTest, Negation) {
  const auto point = math::make_point(3, -4);
  ASSERT_EQ(-point, math::make_point(-3, 4));
}

TEST(PointTest, MakePoint) {
  const auto point = math::make_point(3, -4);
  EXPECT_EQ(point.x, 3);
  EXPECT_EQ(point.y, -4);
}

TEST(PointTest, Ostream) {
  math::testing::ostream_tests()
    .test(math::make_point(3, -4), "(3, -4)")
    .test(math::make_point(0.5, 0.0), "(0.5, 0)");
}

TEST(PointTest, Equality) {
  math::testing::EqualityTests()
    .test(P2(3, -4), P2(3, -4), true)
    .test(P2(1, -4), P2(3, -4), false)
    .test(P2(3, 0), P2(3, -4), false)
    .test(P2(1, 0), P2(3, -4), false);
}

TEST(PointTest, Addition) {
  math::testing::addition_tests()
    .test(P2(3, -4), P2(2, 3), P2(5, -1));
}

TEST(PointTest, Subtraction) {
  math::testing::subtraction_tests()
    .test(P2(3, -4), P2(2, 3), P2(1, -7));
}

TEST(PointTest, Multiplication) {
  math::testing::multiplication_tests()
    .test_with_swap(P2(3, -4), 3, P2(9, -12));
}

TEST(PointTest, Division) {
  math::testing::division_tests()
    .test(P2(6, -8), 2, P2(3, -4));
}
