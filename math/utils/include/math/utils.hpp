#pragma once

#include <cmath>
#include <type_traits>

namespace math {

template<typename LT, typename RT>
inline auto mod(const LT& lhs, const RT& rhs) {
  // TODO: this implementation will force type to be LT if both LT and RT are floating point
  if constexpr (std::is_floating_point_v<LT>) {
    return std::fmod(lhs, static_cast<LT>(rhs));
  } else if constexpr (std::is_floating_point_v<RT>) {
    return std::fmod(static_cast<RT>(lhs), rhs);
  } else {
    return lhs % rhs;
  }
}
}
