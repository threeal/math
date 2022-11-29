#pragma once

#include <ostream>

namespace math::testing {

class BaseTests {
 public:
  int idx;
  template<typename T=BaseTests>
  T& next() {
    ++idx;
    return static_cast<T&>(*this);
  }
};
}
