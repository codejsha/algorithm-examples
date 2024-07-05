#include "arithmetic_operation.h"

#include <gtest/gtest.h>

GTEST_TEST(ArithmeticOperation, Multiply)
{
    constexpr unsigned long long expected = 0b1110101;
    const unsigned long long result = ArithmeticOperation::Multiply(0b1101, 0b1001);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ArithmeticOperation, Divide)
{
    constexpr int expected = 0b101;
    const int result = ArithmeticOperation::Divide(0b1011, 0b10);
    EXPECT_EQ(expected, result);
}
