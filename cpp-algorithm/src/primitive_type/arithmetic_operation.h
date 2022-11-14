#ifndef CPP_ALGORITHM_ARITHMETIC_OPERATION_H
#define CPP_ALGORITHM_ARITHMETIC_OPERATION_H

namespace ArithmeticOperation
{
    /// @brief Calculate the product of two numbers without using arithmetic operators.
    /// @param x multiplier
    /// @param y multiplicand
    /// @return product result
    unsigned long long Multiply(unsigned long long x, unsigned long long y);

    /// @brief Calculate the fraction of two numbers without using arithmetic operators.
    /// @param x dividend
    /// @param y divisor
    /// @return fraction result
    int Divide(int x, int y);
}

#endif
