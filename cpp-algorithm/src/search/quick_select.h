#ifndef CPP_ALGORITHM_QUICK_SELECT_H
#define CPP_ALGORITHM_QUICK_SELECT_H

#include <vector>

namespace QuickSelect
{
    /**
     * \brief Find the k-th smallest element in an array.
     * \param array an array of integers
     * \param k the k-th smallest
     * \return the k-th smallest element
     */
    auto FindKthSmallestElement(std::vector<int>& array, int k) -> int;

    /**
     * \brief Find the k-th smallest element in an array.
     * \param array an array of integers
     * \param k the k-th smallest
     * \return the k-th smallest element
     */
    auto FindKthLargestElement(std::vector<int>& array, int k) -> int;

    /**
     * \brief QuickSelect is an algorithm used to select the k-th smallest (or largest) element in an unordered list of
     * elements.
     * \details It is a variation of QuickSort algorithm and works by partitioning the list into two sub lists around a
     * pivot element, with elements less than or equal to the pivot on one side and elements greater than the pivot on
     * the other.
     * \param array the array to search
     * \param left the left index of the array
     * \param right the right index of the array
     * \param k the index of the k-th element
     * \return the k-th element in the array
     */
    auto QuickSelectAlgorithm(std::vector<int>& array, int left, int right, int k) -> int;
}

#endif
