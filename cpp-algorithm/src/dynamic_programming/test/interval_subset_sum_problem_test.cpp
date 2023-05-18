#include "interval_subset_sum_problem.h"

#include <gtest/gtest.h>

GTEST_TEST(IntervalSubset, Simple1)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::SimpleSubsetSum1(seq);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, Simple2)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::SimpleSubsetSum2(seq);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, DivideAndConquer)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::DivideAndConquerSubsetSum(seq, 0, static_cast<int>(seq.size() - 1));
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, DynamicProgramming)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr auto expected = 8;

    const auto result = IntervalSubset::DynamicProgrammingSubsetSum(seq);
    EXPECT_EQ(expected, result);
}