#pragma once

#include "base_tests.hpp"
#include <gtest/gtest.h>

namespace math::testing {

class EqualityTests : public BaseTests {
 public:
  template<typename LT, typename RT>
  EqualityTests& test(const LT& lhs, const RT& rhs, bool expect_equal) {
    EXPECT_EQ(lhs == rhs, expect_equal) << failed_message();
    EXPECT_EQ(lhs != rhs, !expect_equal) << failed_message();
    return next<EqualityTests>();
  }
};
}
