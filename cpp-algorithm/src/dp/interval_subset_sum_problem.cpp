#include "interval_subset_sum_problem.h"

#include <cmath>

auto IntervalSubset::SubsetSum1(const std::vector<int>& seq) -> int
{
    const int size = static_cast<int>(seq.size());
    int max = std::numeric_limits<int>::min();

    for (int prev = 0; prev < size; ++prev)
    {
        for (int next = prev; next < size; ++next)
        {
            int sum = 0;

            // sum of subset [prev, next]
            for (int loop_index = prev; loop_index <= next; ++loop_index)
            {
                sum += seq[loop_index];
            }

            max = std::max(max, sum);
        }
    }

    return max;
}

auto IntervalSubset::SubsetSum2(const std::vector<int>& seq) -> int
{
    const int size = static_cast<int>(seq.size());
    int max = std::numeric_limits<int>::min();

    for (int prev = 0; prev < size; ++prev)
    {
        int sum = 0;
        for (int next = prev; next < size; ++next)
        {
            sum += seq[next];
            max = std::max(max, sum);
        }
    }

    return max;
}

auto IntervalSubset::DivideAndConquerSubsetSum(const std::vector<int>& seq, const int low, const int high) -> int
{
    if (low == high)
    {
        return seq[low];
    }

    // left subset and right subset
    const int mid = static_cast<int>(std::floor((low + high) / 2));
    const int left_max = DivideAndConquerSubsetSum(seq, low, mid);
    const int right_max = DivideAndConquerSubsetSum(seq, mid + 1, high);

    // cross subset
    // based on mid, find max of left subset and right subset
    int left_cross_max = 0;
    int right_cross_max = 0;
    int left_sum = 0;
    int right_sum = 0;
    for (int index = mid; index >= low; --index)
    {
        left_sum += seq[index];
        left_cross_max = std::max(left_cross_max, left_sum);
    }
    for (int index = mid + 1; index <= high; ++index)
    {
        right_sum += seq[index];
        right_cross_max = std::max(right_cross_max, right_sum);
    }

    // return max of left subset, right subset, and cross subset
    return std::max(std::max(left_max, right_max), left_cross_max + right_cross_max);
}

auto IntervalSubset::DynamicProgrammingSubsetSum(const std::vector<int>& seq) -> int
{
    const int size = static_cast<int>(seq.size());
    int max = std::numeric_limits<int>::min();
    int sum = 0;

    for (int index = 0; index < size; ++index)
    {
        sum = std::max(sum + seq[index], seq[index]);
        max = std::max(max, sum);
    }

    return max;
}
