#include "arithmetic_operation.h"

#include <gtest/gtest.h>

GTEST_TEST(ArithmeticOperation, Multiply)
{
    constexpr auto expected = 0b1110101;
    const auto result = ArithmeticOperation::Multiply(0b1101, 0b1001);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ArithmeticOperation, Divide)
{
    constexpr auto expected = 0b101;
    const auto result = ArithmeticOperation::Divide(0b1011, 0b10);
    EXPECT_EQ(expected, result);
}
