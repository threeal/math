#include <math/utils.hpp>
#include <gtest/gtest.h>

TEST(UtilsTest, Mod) {
  EXPECT_EQ(math::mod(5, 2), 1);
  EXPECT_EQ(math::mod(4.75, 1.5), 0.25);
  // test cross type
  EXPECT_EQ(math::mod(5, 1.5), 0.5);
  EXPECT_EQ(math::mod(4.75, 2), 0.75);
}
