#include <math/testing/tests.hpp>
#include <gtest/gtest.h>

TEST(TestsTest, OstreamTests) {
  math::testing::OstreamTests().test(5, "5");
}

TEST(TestsTest, ExplicitConversionTests) {
  math::testing::ExplicitConversionTests()
    .test(2, 2)
    .test(2.2, 2);
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
  auto tests = math::testing::BaseTests();
  auto ostream_tests = math::testing::OstreamTests();
  ostream_tests.test(tests.failed_message(), "failed on index 0");
  ostream_tests.test(tests.next<>().failed_message(), "failed on index 1");
  ostream_tests.test(tests.next<>().failed_message(), "failed on index 2");
}
