#ifndef CPP_ALGORITHM_SORT_H
#define CPP_ALGORITHM_SORT_H

#include <vector>

namespace Sort
{
    /// <summary>
    /// Selection sort algorithm.
    /// </summary>
    /// <param name="seq">sequence of elements</param>
    /// <returns>sorted sequence</returns>
    std::vector<int> SelectionSort(std::vector<int>& seq);

    /// <summary>
    /// Insertion sort algorithm.
    /// </summary>
    /// <param name="seq">sequence of elements</param>
    /// <returns>sorted sequence</returns>
    std::vector<int> InsertionSort(std::vector<int>& seq);
}

#endif
