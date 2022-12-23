#pragma once

#include <catch2/catch_test_macros.hpp>

#include "base_tests.hpp"

namespace math::testing {

class NegationTests : public BaseTests {
 public:
  template <typename LT, typename RT>
  NegationTests& test(const LT& val, const RT& res) {
    INFO("Test number " << idx);
    CHECK(-val == res);
    CHECK(-(-val) == val);
    return next<NegationTests>();
  }
};
}  // namespace math::testing
