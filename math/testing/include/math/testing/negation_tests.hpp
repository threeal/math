#pragma once

#include <gtest/gtest.h>

namespace math::testing {

class NegationTests {
 private:
  int idx = 0;
 public:
  template<typename LT, typename RT>
  NegationTests& test(const LT& val, const RT& res) {
    EXPECT_EQ(-val, res) << "failed on index " << idx;
    ++idx;
    return *this;
  }
};
}
