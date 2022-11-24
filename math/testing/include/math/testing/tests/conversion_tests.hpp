#pragma once

#include "base_tests.hpp"
#include <gtest/gtest.h>

namespace math::testing {

class ExplicitConversionTests : public BaseTests {
 public:
  template<typename LT, typename RT>
  ExplicitConversionTests& test(const LT& val, const RT& res) {
    EXPECT_EQ(static_cast<RT>(val), res) << failed_message();
    return next<ExplicitConversionTests>();
  }  // LCOV_EXCL_LINE
};
}
