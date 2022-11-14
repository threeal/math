#include <math/point.hpp>
#include <gtest/gtest.h>
#include <sstream>

TEST(PointTest, MakePoint) {
  const auto point = math::make_point(3, -4);
  EXPECT_EQ(point.x, 3);
  EXPECT_EQ(point.y, -4);
}

TEST(PointTest, Ostream) {
  const auto ss = std::stringstream() << math::Point2<int>{3, -4};
  ASSERT_STREQ(ss.str().c_str(), "(3, -4)");
}

TEST(PointTest, Equality) {
  auto lhs = math::make_point(3, -4);
  auto rhs = lhs;
  ASSERT_TRUE(lhs == rhs);
  ASSERT_FALSE(lhs != rhs);
  rhs.x += 2;
  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);
}
