#include <math/point.hpp>
#include <math/testing/arithmetic_tests.hpp>
#include <math/testing/equality_tests.hpp>
#include <math/testing/negation_tests.hpp>
#include <math/testing/ostream_tests.hpp>
#include <gtest/gtest.h>

#define P(x, y) math::make_point(x, y)

TEST(PointTest, MakePoint) {
  const auto point = math::make_point(3, -4);
  EXPECT_EQ(point.x, 3);
  EXPECT_EQ(point.y, -4);
}

TEST(PointTest, Ostream) {
  math::testing::OstreamTests()
    .test(P(3, -4), "(3, -4)")
    .test(P(0.5, 0.0), "(0.5, 0)");
}

TEST(PointTest, Equality) {
  math::testing::EqualityTests()
    .test(P(3, -4), P(3, -4), true)
    .test(P(1, -4), P(3, -4), false)
    .test(P(3, 0), P(3, -4), false)
    .test(P(1, 0), P(3, -4), false)
    .test(P(3, -4), P(3.0, -4.0), true)
    .test(P(1, -4), P(3.0, -4.0), false);
}

TEST(PointTest, Negation) {
  math::testing::NegationTests()
    .test(P(3, -4), P(-3, 4));
}

TEST(PointTest, Addition) {
  math::testing::AdditionTests()
    .test(P(3, -4), P(2, 3), P(5, -1))
    .test(P(3, -4), P(0.5, 1.5), P(3.5, -2.5))
    .test(P(0.25, 0.5), P(2, 3), P(2.25, 3.5));
}

TEST(PointTest, Subtraction) {
  math::testing::SubtractionTests()
    .test(P(3, -4), P(2, 3), P(1, -7))
    .test(P(3, -4), P(0.5, 1.5), P(2.5, -5.5))
    .test(P(0.25, 0.5), P(2, 3), P(-1.75, -2.5));
}

TEST(PointTest, Multiplication) {
  math::testing::MultiplicationTests()
    .test_with_swap(P(3, -4), 3, P(9, -12))
    .test_with_swap(P(3, -4), 0.5, P(1.5, -2.0))
    .test_with_swap(P(0.5, 1.5), 3, P(1.5, 4.5))
    .test_with_swap(P(0.5, 1.5), 0.5, P(0.25, 0.75));
}

TEST(PointTest, Division) {
  math::testing::DivisionTests()
    .test(P(6, -8), 2, P(3, -4))
    .test(P(6, -8), 2.5, P(2.4, -3.2))
    .test(P(0.5, 1.5), 2, P(0.25, 0.75))
    .test(P(0.5, 1.5), 2.5, P(0.2, 0.6));
}
