#ifndef CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H
#define CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H

#include <vector>

namespace IntervalSubset
{
    /**
     * @brief Find the maximum sum of a contiguous subsequence in a given sequence.
     * @param seq integer sequence
     * @return maximum sum of subset
     */
    auto SubsetSum1(const std::vector<int>& seq) -> int;

    /**
     * @brief Find the maximum sum of a contiguous subsequence in a given sequence.
     * @param seq integer sequence
     * @return maximum sum of subset
     */
    auto SubsetSum2(const std::vector<int>& seq) -> int;

    /**
     * @brief Find the maximum sum of a contiguous subsequence in a given sequence.
     * This algorithm uses a divide-and-conquer approach.
     * @details This approach calculates left subset, right subset and cross subset.
     * @param seq integer sequence
     * @param low lower index
     * @param high higher index
     * @return maximum sum of subset
     */
    auto DivideAndConquerSubsetSum(const std::vector<int>& seq, int low, int high) -> int;

    /**
     * @brief Find the maximum sum of a contiguous subsequence in a given sequence.
     * This algorithm uses a dynamic programming approach.
     * @param seq integer sequence
     * @return maximum sum of subset
     */
    auto DynamicProgrammingSubsetSum(const std::vector<int>& seq) -> int;
}

#endif
