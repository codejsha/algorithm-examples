#include "fibonacci_number.h"

#include <gtest/gtest.h>

GTEST_TEST(FibonacciNumber, FibonacciDynamicTopDown)
{
    constexpr int number = 8;
    constexpr int expected = 21;
    auto memo = std::vector<int>(number + 1, -1);

    const int result = Fibonacci::FibonacciDynamicTopDown(number, memo);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(FibonacciNumber, FibonacciDynamicBottomUp)
{
    constexpr int number = 8;
    constexpr int expected = 21;

    const int result = Fibonacci::FibonacciDynamicBottomUp(number);
    EXPECT_EQ(expected, result);
}
