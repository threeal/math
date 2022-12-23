#pragma once

#include <catch2/catch_test_macros.hpp>

#include "base_tests.hpp"

namespace math::testing {

class ExplicitConversionTests : public BaseTests {
 public:
  template <typename LT, typename RT>
  ExplicitConversionTests& test(const LT& val, const RT& res) {
    INFO("Test number " << idx);
    CHECK(static_cast<RT>(val) == res);
    return next<ExplicitConversionTests>();
  }
};
}  // namespace math::testing
