#pragma once

#include "base_tests.hpp"
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <cstring>

namespace math::testing {

class OstreamTests : public BaseTests{
 private:
  std::stringstream ss;
 public:
  template<typename T>
  OstreamTests& test(const T& val, const char* c_str) {
    INFO("Test number " << idx);
    ss.str(std::string());
    ss << val;
    CHECK(std::strcmp(ss.str().c_str(), c_str) == 0);
    return next<OstreamTests>();
  }
};
}
