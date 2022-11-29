#ifndef CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H
#define CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H

#include <vector>

namespace IntervalSubset
{
    auto SimpleSubsetSum(const std::vector<int>& seq) -> int;
    auto SimpleSubsetSum2(const std::vector<int>& seq) -> int;
    auto DivideAndConquerSubsetSum(const std::vector<int>& seq, int low, int high) -> int;
    auto DynamicProgrammingSubsetSum(const std::vector<int>& seq) -> int;
}

#endif
