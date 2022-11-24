#pragma once

#include <ostream>
#include <type_traits>

namespace math {

template<typename T>
struct Point2 {
  using value_type = T;

  T x, y;

  template<typename OT>
  explicit operator Point2<OT>() {
    if constexpr (std::is_same_v<T,OT>) return *this;
    else return {.x=static_cast<OT>(x), .y=static_cast<OT>(y)};
  }

  Point2<T> operator-() const {
    return {.x = -x, .y = -y};
  }

  template<typename OT>
  auto& operator+=(const Point2<OT>& other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  template<typename OT>
  auto& operator-=(const Point2<OT>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  template<typename OT>
  auto& operator*=(const OT& other) {
    x *= other;
    y *= other;
    return *this;
  }

  template<typename OT>
  auto& operator/=(const OT& other) {
    x /= other;
    y /= other;
    return *this;
  }
};

template<typename T>
inline math::Point2<T> make_point(const T& x, const T& y) {
  return {.x=x, .y=y};
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Point2<T>& point) {
  return out << "(" << point.x << ", " << point.y << ")";
}

template<typename LT, typename RT>
bool operator==(const Point2<LT>& lhs, const Point2<RT>& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

template<typename LT, typename RT>
bool operator!=(const Point2<LT>& lhs, const Point2<RT>& rhs) {
  return lhs.x != rhs.x || lhs.y != rhs.y;
}

template<typename LT, typename RT>
auto operator+(const Point2<LT>& lhs, const Point2<RT>& rhs) {
  return math::make_point(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<typename LT, typename RT>
auto operator-(const Point2<LT>& lhs, const Point2<RT>& rhs) {
  return math::make_point(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<typename LT, typename RT>
auto operator*(const Point2<LT>& lhs, const RT& rhs) {
  return math::make_point(lhs.x * rhs, lhs.y * rhs);
}

template<typename LT, typename RT>
auto operator*(const LT& lhs, const Point2<RT>& rhs) {
  return math::make_point(lhs * rhs.x, lhs * rhs.y);
}

template<typename LT, typename RT>
auto operator/(const Point2<LT>& lhs, const RT& rhs) {
  return math::make_point(lhs.x / rhs, lhs.y / rhs);
}
}
