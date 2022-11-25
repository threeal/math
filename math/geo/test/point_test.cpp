#include <math/point.hpp>
#include <math/testing/tests.hpp>
#include <gtest/gtest.h>

#define P(x, y) math::make_point(x, y)

using Flags = math::testing::ArithmeticTestsFlags;

TEST(PointTest, MakePoint) {
  const auto point = math::make_point(3, -4);
  EXPECT_EQ(point.x, 3);
  EXPECT_EQ(point.y, -4);
}

TEST(PointTest, Ostream) {
  math::testing::OstreamTests()
    .test(P(3, -4), "(3, -4)");
}

TEST(PointTest, ExplicitConversion) {
  math::testing::ExplicitConversionTests()
    .test(P(3, -4), P(3, -4))
    .test(P(3.1, -4.1), P(3, -4));
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
  math::testing::AdditionTests<>()
    .test(P(3, -4), P(2, 3), P(5, -1))
    .test(P(3, -4), P(0.5, 1.5), P(3.5, -2.5));
}

TEST(PointTest, Subtraction) {
  math::testing::SubtractionTests<>()
    .test(P(3, -4), P(2, 3), P(1, -7))
    .test(P(3, -4), P(0.5, 1.5), P(2.5, -5.5));;
}

TEST(PointTest, Multiplication) {
  math::testing::MultiplicationTests<Flags::NoAssignmentOperationSwap>()
    .test(P(3, -4), 3, P(9, -12))
    .test(P(3, -4), 0.5, P(1.5, -2.0))
    .test(P(0.5, 1.5), 3, P(1.5, 4.5));
}

TEST(PointTest, Division) {
  math::testing::DivisionTests<Flags::NoSwap>()
    .test(P(6, -8), 2, P(3, -4))
    .test(P(6, -8), 2.5, P(2.4, -3.2))
    .test(P(0.5, 1.5), 2, P(0.25, 0.75));
}
