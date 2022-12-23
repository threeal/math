#include <catch2/catch_test_macros.hpp>
#include <math/point.hpp>
#include <math/testing/tests.hpp>

#define P(x, y) math::make_point(x, y)

using Flags = math::testing::ArithmeticTestsFlags;

TEST_CASE("test `math::make_point`") {
  const auto point = math::make_point(3, -4);
  CHECK(point.x == 3);
  CHECK(point.y == -4);
}

TEST_CASE("test `std::ostream` operation of `math::Point2`") {
  math::testing::OstreamTests().test(P(3, -4), "(3, -4)");
}

TEST_CASE("test explicit conversion operation of `math::Point2`") {
  math::testing::ExplicitConversionTests()  //
      .test(P(3, -4), P(3, -4))
      .test(P(3.1, -4.1), P(3, -4));
}

TEST_CASE("test equality operation of `math::Point2`") {
  math::testing::EqualityTests()
      .test(P(3, -4), P(3, -4), true)
      .test(P(1, -4), P(3, -4), false)
      .test(P(3, 0), P(3, -4), false)
      .test(P(1, 0), P(3, -4), false)
      .test(P(3, -4), P(3.0, -4.0), true)
      .test(P(1, -4), P(3.0, -4.0), false);
}

TEST_CASE("test negation operation of `math::Point2`") {
  math::testing::NegationTests().test(P(3, -4), P(-3, 4));  //
}

TEST_CASE("test addition operation of `math::Point2`") {
  math::testing::AdditionTests<>()  //
      .test(P(3, -4), P(2, 3), P(5, -1))
      .test(P(3, -4), P(0.5, 1.5), P(3.5, -2.5));
}

TEST_CASE("test subtraction operation of `math::Point2`") {
  math::testing::SubtractionTests<>()  //
      .test(P(3, -4), P(2, 3), P(1, -7))
      .test(P(3, -4), P(0.5, 1.5), P(2.5, -5.5));
}

TEST_CASE("test multiplication operation of `math::Point2`") {
  math::testing::MultiplicationTests<Flags::NoAssignmentOperationSwap>()
      .test(P(3, -4), 3, P(9, -12))
      .test(P(3, -4), 0.5, P(1.5, -2.0))
      .test(P(0.5, 1.5), 3, P(1.5, 4.5));
}

TEST_CASE("test division operation of `math::Point2`") {
  math::testing::DivisionTests<Flags::NoSwap>()
      .test(P(6, -8), 2, P(3, -4))
      .test(P(6, -8), 2.5, P(2.4, -3.2))
      .test(P(0.5, 1.5), 2, P(0.25, 0.75));
}
