#ifndef CPP_ALGORITHM_ARITHMETIC_OPERATION_H
#define CPP_ALGORITHM_ARITHMETIC_OPERATION_H

namespace ArithmeticOperation
{
    /// @brief Calculate the product of two numbers without using arithmetic operators.
    /// @param x multiplier
    /// @param y multiplicand
    /// @return product result
    auto Multiply(unsigned long long x, unsigned long long y) -> unsigned long long;

    /// @brief Calculate the fraction of two numbers without using arithmetic operators.
    /// @param x dividend
    /// @param y divisor
    /// @return fraction result
    auto Divide(int x, int y) -> int;
}

#endif
