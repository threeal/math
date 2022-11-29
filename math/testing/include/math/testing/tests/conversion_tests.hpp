#pragma once

#include "base_tests.hpp"
#include <catch2/catch_test_macros.hpp>

namespace math::testing {

class ExplicitConversionTests : public BaseTests {
 public:
  template<typename LT, typename RT>
  ExplicitConversionTests& test(const LT& val, const RT& res) {
    INFO("Test number " << idx);
    CHECK(static_cast<RT>(val) == res);
    return next<ExplicitConversionTests>();
  }  // LCOV_EXCL_LINE
};
}
