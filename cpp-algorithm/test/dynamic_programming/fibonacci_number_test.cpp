#include "fibonacci_number.h"

#include <gtest/gtest.h>

TEST(FibonacciNumberTest, DynamicProgrammingTopDown)
{
    constexpr auto number = 8;
    constexpr auto expected = 21;
    auto memo = std::vector<int>(number + 1, -1);

    const auto result = Fibonacci::FibonacciDynamicTopDown(number, memo);
    ASSERT_EQ(expected, result);
}

TEST(FibonacciNumberTest, DynamicProgrammingBottomUp)
{
    constexpr auto number = 8;
    constexpr auto expected = 21;

    const auto result = Fibonacci::FibonacciDynamicBottomUp(number);
    ASSERT_EQ(expected, result);
}
