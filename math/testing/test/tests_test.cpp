#include <math/testing/arithmetic_tests.hpp>
#include <math/testing/equality_tests.hpp>
#include <math/testing/negation_tests.hpp>
#include <math/testing/ostream_tests.hpp>
#include <gtest/gtest.h>

TEST(TestsTest, OstreamTests) {
  math::testing::OstreamTests().test(5, "5");
}

TEST(TestsTest, EqualityTests) {
  math::testing::EqualityTests()
    .test(2, 2, true)
    .test(2, 3, false)
    .test(2, 2.0, true)
    .test(2, 2.5, false);
}

TEST(TestsTest, NegationTests) {
  math::testing::NegationTests().test(2, -2);
}

TEST(TestsTest, AdditionTests) {
  math::testing::AdditionTests<>()
    .test(2, 3, 5)
    .test(2, 0.5, 2.5);
}

TEST(TestsTest, SubtractionTests) {
  math::testing::SubtractionTests<>()
    .test(2, 3, -1)
    .test(2, 0.5, 1.5);
}

TEST(TestsTest, MultiplicationTests) {
  math::testing::MultiplicationTests<>()
    .test(2, 3, 6)
    .test(2, 0.25, 0.5);
}

TEST(TestsTest, DivisionTests) {
  math::testing::DivisionTests<>()
    .test(6, 3, 2)
    .test(7, 3, 2)
    .test(6, 2.5, 2.4);
}

TEST(TestsTest, FailedMessage) {
  auto tests = math::testing::OstreamTests();
  tests.test(tests.failed_message(), "failed on index 0");
  tests.test(tests.failed_message(), "failed on index 1");
  tests.test(tests.failed_message(), "failed on index 2");
}