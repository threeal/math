#pragma once

#include "base_tests.hpp"
#include <catch2/catch_test_macros.hpp>

namespace math::testing {

class EqualityTests : public BaseTests {
 public:
  template<typename LT, typename RT>
  EqualityTests& test(const LT& lhs, const RT& rhs, bool expect_equal) {
    INFO("Test number " << idx);
    CHECK((lhs == rhs) == expect_equal);
    CHECK((lhs != rhs) != expect_equal);
    CHECK((rhs == lhs) == expect_equal);
    CHECK((rhs != lhs) != expect_equal);
    return next<EqualityTests>();
  }  // LCOV_EXCL_LINE
};
}
