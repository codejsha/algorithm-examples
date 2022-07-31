#include "fibonacci_number.h"
#include <gtest/gtest.h>

TEST(FibonacciNumberTest, Memoization)
{
    constexpr auto number = 8;
    constexpr auto expected_value = 21;
    std::vector<int> memoization(number + 1, -1);

    const auto result = fibonacci::FibonacciMemoization(number, memoization);
    ASSERT_EQ(result, expected_value);
}
