#include <math/point.hpp>
#include <gtest/gtest.h>
#include <sstream>

TEST(PointTest, Ostream) {
  const auto ss = std::stringstream() << math::Point2<int>{3, -4};
  ASSERT_STREQ(ss.str().c_str(), "(3, -4)");
}
