#ifndef CPP_ALGORITHM_INTERSECT_TWO_SORTED_ARRAY_H
#define CPP_ALGORITHM_INTERSECT_TWO_SORTED_ARRAY_H

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
    auto IntersectTwoSortedArrayLoopJoin(const std::vector<int>& arr1, const std::vector<int>& arr2)
        -> std::vector<int>;

    /**
     * \brief Compute the intersection of two sorted arrays.
     * Given two sorted arrays, compute their intersection and return the result as a vector.
     * The input arrays may have duplicate entries, but the output should be free of duplicates.
     * \details This function uses two for loops, but the inner loop uses _binary search_.
     * \param arr1 first sorted number array
     * \param arr2 second sorted number array
     * \return number array of intersection
     */
    auto IntersectTwoSortedArrayLoopJoin2(const std::vector<int>& arr1, const std::vector<int>& arr2)
        -> std::vector<int>;

    /**
     * \brief Compute the intersection of two sorted arrays.
     * Given two sorted arrays, compute their intersection and return the result as a vector.
     * The input arrays may have duplicate entries, but the output should be free of duplicates.
     * \details This function uses two pointers to iterate through the arrays.
     * \param arr1 first sorted number array
     * \param arr2 second sorted number array
     * \return number array of intersection
     */
    auto IntersectTwoSortedArray(const std::vector<int>& arr1, const std::vector<int>& arr2) -> std::vector<int>;
}

#endif
