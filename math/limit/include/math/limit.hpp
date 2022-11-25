#pragma once

#include <ostream>

namespace math {

template<typename T>
struct Limit {
  using value_type = T;

  T min, max;
};

template<typename T>
inline math::Limit<T> make_limit(const T& min, const T& max) {
  return {.min=min, .max=max};
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Limit<T>& limit) {
  return out << "{min: " << limit.min << ", max: " << limit.max << "}";
}

template<typename LT, typename RT>
bool operator==(const Limit<LT>& lhs, const Limit<RT>& rhs) {
  return lhs.min == rhs.min && lhs.max == rhs.max;
}

template<typename LT, typename RT>
bool operator!=(const Limit<LT>& lhs, const Limit<RT>& rhs) {
  return lhs.min != rhs.min || lhs.max != rhs.max;
}
}
