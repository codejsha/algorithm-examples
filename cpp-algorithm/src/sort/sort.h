#ifndef CPP_ALGORITHM_SORT_H
#define CPP_ALGORITHM_SORT_H

#include <vector>

namespace Sort
{
    /// @brief Selection sort algorithm.
    /// @param seq sequence of elements
    /// @return sorted sequence
    std::vector<int> SelectionSort(std::vector<int>& seq);

    /// @brief Insertion sort algorithm.
    /// @param seq sequence of elements
    /// @return sorted sequence
    std::vector<int> InsertionSort(std::vector<int>& seq);
}

#endif
