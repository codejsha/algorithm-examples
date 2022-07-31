#ifndef CPP_ALGORITHM_UTIL_H
#define CPP_ALGORITHM_UTIL_H

#include <vector>

namespace util
{
    std::vector<int> GenerateSequence(int size, int min, int max);
    void PrintSequence(const std::vector<int>& seq);
} // namespace util

#endif
