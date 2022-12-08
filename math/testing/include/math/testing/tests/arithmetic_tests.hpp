#pragma once

#include "base_tests.hpp"
#include <catch2/catch_test_macros.hpp>

namespace math::testing {

enum class ArithmeticOperation { Addition, Subtraction, Multiplication, Division };

enum ArithmeticTestsFlags : int {
  NoOperation = 1,
  NoAssignmentOperation = 2,
  NoOperationSwap = 4,
  NoAssignmentOperationSwap = 8,
  NoSwap = 12
};

template<ArithmeticOperation OP, int OPT=0>
class ArithmeticTests : public BaseTests {
 public:
  template<typename LT, typename RT, typename T>
  ArithmeticTests& test(LT lhs, const RT& rhs, const T& res) {
    INFO("Test number " << idx);
    if constexpr ((OPT & ArithmeticTestsFlags::NoOperation) == 0) {
      CHECK(operation(lhs, rhs) == res);
      if constexpr ((OPT & ArithmeticTestsFlags::NoOperationSwap) == 0)
        CHECK(operation(rhs, lhs) == inverse(res));
    }
    if constexpr ((OPT & ArithmeticTestsFlags::NoAssignmentOperation) == 0) {
      test_assignment(lhs, rhs, static_cast<LT>(res));
      if constexpr ((OPT & ArithmeticTestsFlags::NoAssignmentOperationSwap) == 0)
        test_assignment(rhs, lhs, static_cast<RT>(inverse(res)));
    }
    return next<ArithmeticTests>();
  }
 private:
  template<typename LT, typename RT, typename T>
  void test_assignment(LT lhs, const RT& rhs, const T& res) {
    CHECK(assignment_operation(lhs, rhs) == res);
    CHECK(lhs == res);
  }
  template<typename T>
  inline auto inverse(const T& val) const {
    if constexpr (OP == ArithmeticOperation::Subtraction) return -val;
    else if constexpr (OP == ArithmeticOperation::Division) return 1 / val;
    else return val;
  }
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

template<int OPT=0> using AdditionTests = ArithmeticTests<ArithmeticOperation::Addition, OPT>;
template<int OPT=0> using SubtractionTests = ArithmeticTests<ArithmeticOperation::Subtraction, OPT>;
template<int OPT=0> using MultiplicationTests = ArithmeticTests<ArithmeticOperation::Multiplication, OPT>;
template<int OPT=0> using DivisionTests = ArithmeticTests<ArithmeticOperation::Division, OPT>;
}
