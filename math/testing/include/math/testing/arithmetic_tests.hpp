#pragma once

#include <gtest/gtest.h>

namespace math::testing {

enum class ArithmeticOperation { Addition, Subtraction, Multiplication, Division };

template<ArithmeticOperation OP>
class ArithmeticTests {
 private:
  int idx = 0;
 public:
  template<typename LT, typename RT, typename T>
  ArithmeticTests& test(LT lhs, const RT& rhs, const T& res) {
    EXPECT_EQ(operation(lhs, rhs), res) << "failed on index " << idx;
    EXPECT_EQ(assignment_operation(lhs, rhs), res) << "failed on index " << idx;
    EXPECT_EQ(lhs, res) << "failed on index " << idx;
    ++idx;
    return *this;
  }
  template<typename LT, typename RT, typename T>
  inline ArithmeticTests& test_with_swap(const LT& lhs, const RT& rhs, const T& res) {
    EXPECT_EQ(operation(rhs, lhs), res) << "failed on index " << idx;
    return test(lhs, rhs, res);
  }
 private:
  template<typename LT, typename RT>
  inline auto operation(const LT& lhs, const RT& rhs) const {
    if constexpr (OP == ArithmeticOperation::Addition) return lhs + rhs;
    else if constexpr (OP == ArithmeticOperation::Subtraction) return lhs - rhs;
    else if constexpr (OP == ArithmeticOperation::Multiplication) return lhs * rhs;
    else if constexpr (OP == ArithmeticOperation::Division) return lhs / rhs;
  }
  template<typename LT, typename RT>
  inline auto& assignment_operation(LT& lhs, const RT& rhs) const {
    if constexpr (OP == ArithmeticOperation::Addition) return lhs += rhs;
    else if constexpr (OP == ArithmeticOperation::Subtraction) return lhs -= rhs;
    else if constexpr (OP == ArithmeticOperation::Multiplication) return lhs *= rhs;
    else if constexpr (OP == ArithmeticOperation::Division) return lhs /= rhs;
  }
};

using AdditionTests = ArithmeticTests<ArithmeticOperation::Addition>;
using SubtractionTests = ArithmeticTests<ArithmeticOperation::Subtraction>;
using MultiplicationTests = ArithmeticTests<ArithmeticOperation::Multiplication>;
using DivisionTests = ArithmeticTests<ArithmeticOperation::Division>;
}
