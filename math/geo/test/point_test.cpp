#include <math/point.hpp>
#include <gtest/gtest.h>
#include <sstream>

TEST(PointTest, Negation) {
  const auto point = math::make_point(3, -4);
  ASSERT_EQ(-point, math::make_point(-3, 4));
}

TEST(PointTest, AssignmentAddition) {
  auto point = math::make_point(3, -4);
  ASSERT_EQ(point += math::make_point(2, 3), math::make_point(5, -1));
  ASSERT_EQ(point, math::make_point(5, -1));
}

TEST(PointTest, AssignmentSubstraction) {
  auto point = math::make_point(3, -4);
  ASSERT_EQ(point -= math::make_point(2, 3), math::make_point(1, -7));
  ASSERT_EQ(point, math::make_point(1, -7));
}

TEST(PointTest, AssignmentMultiplication) {
  auto point = math::make_point(3, -4);
  ASSERT_EQ(point *= 3, math::make_point(9, -12));
  ASSERT_EQ(point, math::make_point(9, -12));
}

TEST(PointTest, AssignmentDivision) {
  auto point = math::make_point(6, -8);
  ASSERT_EQ(point /= 2, math::make_point(3, -4));
  ASSERT_EQ(point, math::make_point(3, -4));
}

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
  const auto lhs = math::make_point(3, -4);
  auto rhs = lhs;
  ASSERT_TRUE(lhs == rhs);
  ASSERT_FALSE(lhs != rhs);
  rhs.x += 2;
  EXPECT_FALSE(lhs == rhs);
  EXPECT_TRUE(lhs != rhs);
}

TEST(PointTest, Addition) {
  const auto point = math::make_point(3, -4);
  ASSERT_EQ(point + math::make_point(2, 3), math::make_point(5, -1));
}

TEST(PointTest, Substraction) {
  const auto point = math::make_point(3, -4);
  ASSERT_EQ(point - math::make_point(2, 3), math::make_point(1, -7));
}

TEST(PointTest, Multiplication) {
  const auto point = math::make_point(3, -4);
  ASSERT_EQ(point * 3, math::make_point(9, -12));
  ASSERT_EQ(-2 * point, math::make_point(-6, 8));
}

TEST(PointTest, Division) {
  const auto point = math::make_point(6, -8);
  ASSERT_EQ(point / 2, math::make_point(3, -4));
}
