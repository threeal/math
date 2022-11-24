#pragma once

#include "base_tests.hpp"
#include <gtest/gtest.h>
#include <sstream>

namespace math::testing {

class OstreamTests : public BaseTests{
 private:
  std::stringstream ss;
 public:
  template<typename T>
  OstreamTests& test(const T& val, const char* c_str) {
    ss.str(std::string());
    ss << val;
    EXPECT_STREQ(ss.str().c_str(), c_str) << failed_message();
    return next<OstreamTests>();
  }  // LCOV_EXCL_LINE
};
}
