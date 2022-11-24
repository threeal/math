#pragma once

#include <gtest/gtest.h>

namespace math::testing {

class EqualityTests {
 private:
  int idx = 0;
 public:
  template<typename LT, typename RT>
  EqualityTests& test(const LT& lhs, const RT& rhs, bool expect_equal) {
    EXPECT_EQ(lhs == rhs, expect_equal) << "failed on index " << idx;
    EXPECT_EQ(lhs != rhs, !expect_equal) << "failed on index " << idx;
    ++idx;
    return *this;
  }
};
}
