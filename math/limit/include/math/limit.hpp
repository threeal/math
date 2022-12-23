#pragma once

#include <math/utils.hpp>
#include <ostream>

namespace math {

template <typename T>
struct Limit {
  using value_type = T;

  T min, max;

  Limit<T> normalize() const {
    if (min <= max) return *this;
    return {.min = max, .max = min};
  }

  auto center() const { return (min + max) / 2; }
  auto range() const { return max - min; }

  template <typename OT>
  bool is_inside(const OT& other) const {
    if (min > max) return normalize().is_inside(other);
    return other >= min && other <= max;
  }

  template <typename OT>
  bool is_outside(const OT& other) const {
    if (min > max) return normalize().is_outside(other);
    return other < min || other > max;
  }

  template <typename OT>
  T clamp(const OT& other) const {
    if (min > max) return normalize().clamp(other);
    if (other < min) return min;
    if (other > max) return max;
    return other;
  }

  template <typename OT>
  T fold(const OT& other) const {
    if (min > max) return normalize().fold(other);
    const auto range = this->range();
    return min + math::mod(range + math::mod(other - min, range), range);
  }
};

template <typename T>
inline math::Limit<T> make_limit(const T& min, const T& max) {
  return {.min = min, .max = max};
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Limit<T>& limit) {
  return out << "{min: " << limit.min << ", max: " << limit.max << "}";
}

template <typename LT, typename RT>
bool operator==(const Limit<LT>& lhs, const Limit<RT>& rhs) {
  return lhs.min == rhs.min && lhs.max == rhs.max;
}

template <typename LT, typename RT>
bool operator!=(const Limit<LT>& lhs, const Limit<RT>& rhs) {
  return lhs.min != rhs.min || lhs.max != rhs.max;
}
}  // namespace math
