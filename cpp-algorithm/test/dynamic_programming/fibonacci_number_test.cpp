#include "fibonacci_number.h"
#include <gtest/gtest.h>

TEST(FibonacciNumberTest, DynamicProgrammingTopDown)
{
    constexpr auto number = 8;
    constexpr auto expected_value = 21;
    std::vector<int> memo(number + 1, -1);

    const auto result = fibonacci::FibonacciDynamicTopDown(number, memo);
    ASSERT_EQ(result, expected_value);
}

TEST(FibonacciNumberTest, DynamicProgrammingBottomUp)
{
    constexpr auto number = 8;
    constexpr auto expected_value = 21;

    const auto result = fibonacci::FibonacciDynamicBottomUp(number);
    ASSERT_EQ(result, expected_value);
}
