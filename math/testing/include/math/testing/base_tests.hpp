#pragma once

#include <ostream>

namespace math::testing {

class BaseTests {
 private:
  int idx;
 public:
  struct FailedMessage { int idx; };
  FailedMessage failed_message() const { return {.idx=idx}; }
  template<typename T>
  T& next() {
    ++idx;
    return static_cast<T&>(*this);
  }
};

std::ostream& operator<<(std::ostream& out, const BaseTests::FailedMessage& msg) {
  return out << "failed on index " << msg.idx;
}
}
