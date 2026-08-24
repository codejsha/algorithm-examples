#ifndef CPP_ALGORITHM_DUTCH_NATIONAL_FLAG_H
#define CPP_ALGORITHM_DUTCH_NATIONAL_FLAG_H

#include <vector>

namespace DutchFlag
{
    /**
     * \brief Colors used in the Dutch national flag problem.
     * The array is partitioned around a pivot color so that all elements less than
     * the pivot appear first, then equals, and finally elements greater than the
     * pivot.
     */
    enum Color
    {
        Red,
        White,
        Blue
    };

    /**
     * \brief Naive partitioning approach.
     * Repeatedly scans the array to move smaller values left and larger values
     * right. This is conceptually simple but not optimal.
     * \param pivot_index Index of the pivot element.
     * \param arr Input array to be partitioned in-place.
     * \return The partitioned array.
     */
    std::vector<Color> DutchFlagPartition1(
        int pivot_index,
        std::vector<Color>& arr);

    /**
     * \brief Two-pass partitioning approach.
     * One pass moves values smaller than the pivot to the front, and another pass
     * moves values larger than the pivot to the end. This is better than the
     * naive version but still uses multiple scans.
     * \param pivot_index Index of the pivot element.
     * \param arr Input array to be partitioned in-place.
     * \return The partitioned array.
     */
    std::vector<Color> DutchFlagPartition2(
        int pivot_index,
        std::vector<Color>& arr);

    /**
     * \brief Three-way partitioning approach.
     * This is the canonical Dutch national flag solution. It keeps three regions:
     * [smaller than pivot], [equal to pivot], and [greater than pivot].
     * The algorithm runs in O(n) time and uses O(1) extra space.
     * \param pivot_index Index of the pivot element.
     * \param arr Input array to be partitioned in-place.
     * \return The partitioned array.
     */
    std::vector<Color> DutchFlagPartition3(
        int pivot_index,
        std::vector<Color>& arr);
}

// ----------------------------------------------------------------------------
inline std::vector<DutchFlag::Color> DutchFlag::DutchFlagPartition1(
    const int pivot_index,
    std::vector<Color>& arr)
{
    const Color pivot = arr[pivot_index];
    const int size = static_cast<Color>(arr.size());

    // Move elements smaller than the pivot to the left
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < pivot)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }

    // Move elements larger than the pivot to the right
    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > pivot)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }

    return arr;
}

// ----------------------------------------------------------------------------
inline std::vector<DutchFlag::Color> DutchFlag::DutchFlagPartition2(
    const int pivot_index,
    std::vector<Color>& arr)
{
    const Color pivot = arr[pivot_index];
    const int  size = static_cast<Color>(arr.size());

    // Collect elements smaller than the pivot to the front
    int smaller = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < pivot)
        {
            std::swap(arr[i], arr[smaller++]);
        }
    }

    // Collect elements larger than the pivot to the end
    int larger = size - 1;
    for (int i = size - 1; i >= 0; --i)
    {
        if (arr[i] > pivot)
        {
            std::swap(arr[i], arr[larger--]);
        }
    }

    return arr;
}

// ----------------------------------------------------------------------------
inline std::vector<DutchFlag::Color> DutchFlag::DutchFlagPartition3(
    const int pivot_index,
    std::vector<Color>& arr)
{
    const Color pivot = arr[pivot_index];
    const int size = static_cast<Color>(arr.size());

    // [0, smaller): elements less than pivot
    // [smaller, equal): elements equal to pivot
    // [equal, larger): unprocessed region
    // [larger, size): elements greater than pivot
    int smaller = 0;
    int equal = 0;
    int larger = size;

    while (equal < larger)
    {
        // If the current element is smaller than the pivot, swap it to the smaller region
        if (arr[equal] < pivot)
        {
            std::swap(arr[smaller++], arr[equal++]);
        }
        // If the current element is equal to the pivot, just move the equal pointer forward
        else if (arr[equal] == pivot)
        {
            ++equal;
        }
        // If the current element is larger than the pivot, swap it to the larger region
        else
        {
            std::swap(arr[equal], arr[--larger]);
        }
    }

    return arr;
}

#endif
