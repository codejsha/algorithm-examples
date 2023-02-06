#ifndef CPP_ALGORITHM_SEARCH_SORTED_ARRAY_H
#define CPP_ALGORITHM_SEARCH_SORTED_ARRAY_H

#include <vector>

namespace SearchSortedArray
{
    /// @brief Search a sorted array for the first occurrence of a key.
    /// @details Given a sorted array of integers, find the first occurrence of a key.
    /// @param array a sorted array of integers
    /// @param key the key to search for
    /// @return the index of the first occurrence of the key
    auto SearchFirstOfKey(const std::vector<int>& array, int key) -> int;

    /// @brief Search a sorted array for the first greater than a key.
    /// @details Given a sorted array of integers, find the first element that is greater than the key.
    /// @param array a sorted array of integers
    /// @param key the key to search for
    /// @return the index of the first greater than the key
    auto SearchFirstGreaterThanKey(const std::vector<int>& array, int key) -> int;

    /// @brief Search a sorted array for entry equal to its index.
    /// @details Given a sorted array of distinct integers, find an entry equal to its index.
    /// @param array array a sorted array of integers
    /// @return the entry equal to its index
    auto SearchEntryEqualToItsIndex(const std::vector<int>& array) -> std ::vector<int>;

    /// @brief Search a cyclically sorted array for the smallest element.
    /// @details Given a cyclically sorted array of unique integers, find the smallest element.
    /// @param array a sorted array of integers
    /// @return the index of the smallest element
    auto SearchSmallestElementInCyclicallySortedArray(const std::vector<int>& array) -> int;
}

#endif
