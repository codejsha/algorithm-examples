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
    int FindKthSmallestElement(
        std::vector<int>& array,
        int k);

    /**
     * \brief Find the k-th smallest element in an array.
     * \param array an array of integers
     * \param k the k-th smallest
     * \return the k-th smallest element
     */
    int FindKthLargestElement(
        std::vector<int>& array,
        int k);

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
    int QuickSelectAlgorithm(
        std::vector<int>& array,
        int left,
        int right,
        int k);
}

// ----------------------------------------------------------------------------
/**
 * \brief Partition the array around the pivot element.
 * \details To find the k-th smallest (or largest) element, partition the array into two sub lists.
 * Elements less than or equal to the pivot are on one side, and elements greater than the pivot are on the other side.
 * \param array the array to partition
 * \param left the left index of the array
 * \param right the right index of the array
 * \return the index of the pivot element
 * \note
 * Comparison Explanation:
 * - Finding k-th smallest element: This comparison is used to find the k-th smallest element:
 *     \code if (arr[j] <= pivot) \endcode
 * - Finding k-th largest element: This comparison is used to find the k-th largest element:
 *     \code if (arr[j] >= pivot) \endcode
 */
inline int Partition(
    std::vector<int>& array,
    const int left,
    const int right)
{
    const int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; ++j)
    {
        if (array[j] <= pivot)
        {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[right]);
    return i + 1;
}

// ----------------------------------------------------------------------------
inline int QuickSelect::QuickSelectAlgorithm(
    std::vector<int>& array,
    const int left,
    const int right,
    const int k)
{
    if (left == right)
    {
        return array[left];
    }

    const int pivot_index = Partition(array, left, right);
    if (k == pivot_index)
    {
        return array[pivot_index];
    }
    if (k < pivot_index)
    {
        return QuickSelectAlgorithm(array, left, pivot_index - 1, k);
    }
    return QuickSelectAlgorithm(array, pivot_index + 1, right, k);
}

// ----------------------------------------------------------------------------
inline int QuickSelect::FindKthSmallestElement(
    std::vector<int>& array,
    const int k)
{
    constexpr int left = 0;
    const int right = static_cast<int>(array.size()) - 1;
    return QuickSelectAlgorithm(array, left, right, k - 1);
}

// ----------------------------------------------------------------------------
inline int QuickSelect::FindKthLargestElement(
    std::vector<int>& array,
    int k)
{
    constexpr int left = 0;
    const int right = static_cast<int>(array.size()) - 1;
    k = static_cast<int>(array.size()) - k;
    return QuickSelectAlgorithm(array, left, right, k);
}

#endif
