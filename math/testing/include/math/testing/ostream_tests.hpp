#pragma once

#include <gtest/gtest.h>
#include <sstream>

namespace math::testing {

class OstreamTests {
 private:
  std::stringstream ss;
  int idx = 0;
 public:
  template<typename T>
  OstreamTests& test(const T& val, const char* c_str) {
    ss.str(std::string());
    ss << val;
    EXPECT_STREQ(ss.str().c_str(), c_str) << "Failed on index " << idx;
    ++idx;
    return *this;
  }
};

inline OstreamTests ostream_tests() { return OstreamTests(); }
}
