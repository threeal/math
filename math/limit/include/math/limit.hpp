#pragma once

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
}
