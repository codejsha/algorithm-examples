#include "fibonacci_number.h"

#include <gtest/gtest.h>

GTEST_TEST(FibonacciNumberTest, FibonacciDynamicTopDown)
{
    constexpr auto number = 8;
    constexpr auto expected = 21;
    auto memo = std::vector<int>(number + 1, -1);

    const auto result = Fibonacci::FibonacciDynamicTopDown(number, memo);
    ASSERT_EQ(expected, result);
}

GTEST_TEST(FibonacciNumberTest, FibonacciDynamicBottomUp)
{
    constexpr auto number = 8;
    constexpr auto expected = 21;

    const auto result = Fibonacci::FibonacciDynamicBottomUp(number);
    ASSERT_EQ(expected, result);
}
