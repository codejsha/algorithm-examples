#include <vector>

#ifndef CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H
#define CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H

namespace problem
{
    int SimpleSubsetSum(const std::vector<int>& seq);
    int SimpleSubsetSum2(const std::vector<int>& seq);
    int DivideAndConquerSubsetSum(const std::vector<int>& seq, int low, int high);
    int DynamicProgrammingSubsetSum(const std::vector<int>& seq);
}// namespace problem

#endif//CPP_ALGORITHM_INTERVAL_SUBSET_SUM_PROBLEM_H
