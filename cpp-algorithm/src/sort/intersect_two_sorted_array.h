#ifndef CPP_ALGORITHM_INTERSECT_TWO_SORTED_ARRAY_H
#define CPP_ALGORITHM_INTERSECT_TWO_SORTED_ARRAY_H

#include <algorithm>
#include <ranges>
#include <vector>

namespace IntersectTwoSortedArray
{
    /**
     * \brief Compute the intersection of two sorted arrays.
     * Given two sorted arrays, compute their intersection and return the result as a vector.
     * The input arrays may have duplicate entries, but the output should be free of duplicates.
     * \details This function is a brute force solution using two for loops.
     * \param arr1 first sorted number array
     * \param arr2 second sorted number array
     * \return number array of intersection
     */
    std::vector<int> IntersectTwoSortedArrayLoopJoin(
        const std::vector<int>& arr1,
        const std::vector<int>& arr2);

    /**
     * \brief Compute the intersection of two sorted arrays.
     * Given two sorted arrays, compute their intersection and return the result as a vector.
     * The input arrays may have duplicate entries, but the output should be free of duplicates.
     * \details This function uses two for loops, but the inner loop uses _binary search_.
     * \param arr1 first sorted number array
     * \param arr2 second sorted number array
     * \return number array of intersection
     */
    std::vector<int> IntersectTwoSortedArrayLoopJoin2(
        const std::vector<int>& arr1,
        const std::vector<int>& arr2);

    /**
     * \brief Compute the intersection of two sorted arrays.
     * Given two sorted arrays, compute their intersection and return the result as a vector.
     * The input arrays may have duplicate entries, but the output should be free of duplicates.
     * \details This function uses two pointers to iterate through the arrays.
     * \param arr1 first sorted number array
     * \param arr2 second sorted number array
     * \return number array of intersection
     */
    std::vector<int> IntersectTwoSortedArray(
        const std::vector<int>& arr1,
        const std::vector<int>& arr2);
}

// ----------------------------------------------------------------------------
inline std::vector<int> IntersectTwoSortedArray::IntersectTwoSortedArrayLoopJoin(
    const std::vector<int>& arr1,
    const std::vector<int>& arr2)
{
    std::vector<int> intersection;
    for (int i = 1; i < static_cast<int>(arr1.size()); ++i)
    {
        if (arr1[i] != arr1[i - 1] && std::ranges::find(arr2, arr1[i]) != arr2.end())
        {
            intersection.emplace_back(arr1[i]);
        }
    }
    return intersection;
}

// ----------------------------------------------------------------------------
inline std::vector<int> IntersectTwoSortedArray::IntersectTwoSortedArrayLoopJoin2(
    const std::vector<int>& arr1,
    const std::vector<int>& arr2)
{
    std::vector<int> intersection;
    for (int i = 1; i < static_cast<int>(arr1.size()); ++i)
    {
        if ((arr1[i] != arr1[i - 1]) && std::ranges::binary_search(arr2, arr1[i]))
        {
            intersection.emplace_back(arr1[i]);
        }
    }
    return intersection;
}

// ----------------------------------------------------------------------------
inline std::vector<int> IntersectTwoSortedArray::IntersectTwoSortedArray(
    const std::vector<int>& arr1,
    const std::vector<int>& arr2)
{
    std::vector<int> intersection;
    int i = 0;
    int j = 0;
    while (i < static_cast<int>(arr1.size()) && j < static_cast<int>(arr2.size()))
    {
        if (arr1[i] == arr2[j] && (i == 0 || arr1[i] != arr1[i - 1]))
        {
            intersection.emplace_back(arr1[i]);
            ++i;
            ++j;
        }
        else if (arr1[i] < arr2[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return intersection;
}

#endif
