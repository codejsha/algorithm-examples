#ifndef CPP_ALGORITHM_SORT_H
#define CPP_ALGORITHM_SORT_H

#include <vector>

namespace Sort
{
    /**
     * \brief Selection sort algorithm.
     * \param seq sequence of elements
     * \return sorted sequence
     */
    auto SelectionSort(std::vector<int>& seq) -> std::vector<int>;

    /**
     * \brief Insertion sort algorithm.
     * \param seq sequence of elements
     * \return sorted sequence
     */
    auto InsertionSort(std::vector<int>& seq) -> std::vector<int>;
}

#endif
