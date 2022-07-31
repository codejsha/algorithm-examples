#ifndef CPP_ALGORITHM_SORT_H
#define CPP_ALGORITHM_SORT_H

#include <vector>

namespace sort
{
    std::vector<int> SelectionSort(std::vector<int>& seq);
    std::vector<int> InsertionSort(std::vector<int>& seq);
} // namespace sort

#endif
