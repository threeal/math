#pragma once

#include "base_tests.hpp"
#include <gtest/gtest.h>

namespace math::testing {

class NegationTests : public BaseTests {
 public:
  template<typename LT, typename RT>
  NegationTests& test(const LT& val, const RT& res) {
    EXPECT_EQ(-val, res) << failed_message();
    EXPECT_EQ(-(-val), val) << failed_message();
    return next<NegationTests>();
  }
};
}
