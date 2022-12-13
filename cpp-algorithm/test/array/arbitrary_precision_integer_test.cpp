#include "arbitrary_precision_integer.h"

#include <algorithm>
#include <gtest/gtest.h>
#include <ranges>

GTEST_TEST(ArbitraryPrecision, PlusOne)
{
    const auto number = std::vector<int>{1, 2, 9};
    const auto expected = std::vector<int>{1, 3, 0};
    const auto result = ArbitraryPrecision::PlusOne(number);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ArbitraryPrecision, StringAddition)
{
    const auto number1 = std::string{"101"};
    const auto number2 = std::string{"101"};
    const auto expected = std::vector<int>{1, 0, 1, 0};
    auto result = ArbitraryPrecision::StringAddition(number1, number2);
    std::ranges::reverse(result.begin(), result.end());
    EXPECT_EQ(expected, result);
}

GTEST_TEST(ArbitraryPrecision, Multiply)
{
    auto number1 = std::vector<int>{1, 9, 3, 7, 0, 7, 7, 2, 1};
    auto number2 = std::vector<int>{-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
    const auto expected = std::vector<int>{-1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7};
    const auto result = ArbitraryPrecision::Multiply(number1, number2);
    EXPECT_EQ(expected, result);
}
