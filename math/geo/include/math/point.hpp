#pragma once

#include <ostream>

namespace math {

template<typename T>
struct Point2 {
  using value_type = T;

  T x, y;
};

template<typename T>
math::Point2<T> make_point(const T& x, const T& y) {
  return {.x=x, .y=y};
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Point2<T>& point) {
  return out << "(" << point.x << ", " << point.y << ")";
}
}
