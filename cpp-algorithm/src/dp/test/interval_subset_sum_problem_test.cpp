#include "interval_subset_sum_problem.h"

#include <gtest/gtest.h>

GTEST_TEST(IntervalSubset, SubsetSum1)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::SubsetSum1(seq);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, SubsetSum2)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::SubsetSum2(seq);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, DivideAndConquer)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;
    constexpr auto low = 0;
    const auto high = static_cast<int>(seq.size() - 1);

    const auto result = IntervalSubset::DivideAndConquerSubsetSum(seq, low, high);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, DynamicProgramming)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::DynamicProgrammingSubsetSum(seq);
    EXPECT_EQ(expected, result);
}
