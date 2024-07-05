#include "interval_subset_sum_problem.h"

#include <gtest/gtest.h>

GTEST_TEST(IntervalSubset, SubsetSum1)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr int expected = 8;

    const int result = IntervalSubset::SubsetSum1(seq);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, SubsetSum2)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr int expected = 8;

    const int result = IntervalSubset::SubsetSum2(seq);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, DivideAndConquer)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr int expected = 8;
    constexpr int low = 0;
    const int high = static_cast<int>(seq.size() - 1);

    const int result = IntervalSubset::DivideAndConquerSubsetSum(seq, low, high);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IntervalSubset, DynamicProgramming)
{
    const auto seq = std::vector<int>{3, -1, 2, -1, 5};
    constexpr int expected = 8;

    const int result = IntervalSubset::DynamicProgrammingSubsetSum(seq);
    EXPECT_EQ(expected, result);
}
