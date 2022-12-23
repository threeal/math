#include <catch2/catch_test_macros.hpp>
#include <math/testing/tests.hpp>

TEST_CASE("test `math::testing::OstreamTests`") {
  math::testing::OstreamTests().test(5, "5");  //
}

TEST_CASE("test `math::testing::ExplicitConversionTests`") {
  math::testing::ExplicitConversionTests()  //
      .test(2, 2)
      .test(2.2, 2);
}

TEST_CASE("test `math::testing::EqualityTests`") {
  math::testing::EqualityTests()  //
      .test(2, 2, true)
      .test(2, 3, false)
      .test(2, 2.0, true)
      .test(2, 2.5, false);
}

TEST_CASE("test `math::testing::NegationTests`") {
  math::testing::NegationTests().test(2, -2);  //
}

TEST_CASE("test `math::testing::AdditionTests`") {
  math::testing::AdditionTests<>()  //
      .test(2, 3, 5)
      .test(2, 0.5, 2.5);
}

TEST_CASE("test `math::testing::SubtractionTests`") {
  math::testing::SubtractionTests<>()  //
      .test(2, 3, -1)
      .test(2, 0.5, 1.5);
}

TEST_CASE("test `math::testing::MultiplicationTests`") {
  math::testing::MultiplicationTests<>()  //
      .test(2, 3, 6)
      .test(2, 0.25, 0.5);
}

TEST_CASE("test `math::testing::DivisionTests`") {
  math::testing::DivisionTests<>()  //
      .test(6, 3, 2)
      .test(7, 3, 2)
      .test(6, 2.5, 2.4);
}
