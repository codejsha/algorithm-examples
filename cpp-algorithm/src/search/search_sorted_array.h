#ifndef CPP_ALGORITHM_SEARCH_SORTED_ARRAY_H
#define CPP_ALGORITHM_SEARCH_SORTED_ARRAY_H

#include <vector>

namespace SearchSortedArray
{
    /**
     * \brief Search a sorted array for the first occurrence of a key.
     * \details Given a sorted array of integers, find the first occurrence of a key.
     * \param array a sorted array of integers
     * \param key the key to search for
     * \return the index of the first occurrence of the key
     */
    int SearchFirstOfKey(
        const std::vector<int>& array,
        int key);

    /**
     * \brief Search a sorted array for the first greater than a key.
     * \details Given a sorted array of integers, find the first element that is greater than the key.
     * \param array a sorted array of integers
     * \param key the key to search for
     * \return the index of the first greater than the key
     */
    int SearchFirstGreaterThanKey(
        const std::vector<int>& array,
        int key);

    /**
     * \brief Search a sorted array for entry equal to its index.
     * \details Given a sorted array of distinct integers, find an entry equal to its index.
     * \param array a sorted array of integers
     * \return the entry equal to its index
     */
    std::vector<int> SearchEntryEqualToItsIndex(
        const std::vector<int>& array);

    /**
     * \brief Search a cyclically sorted array for the smallest element.
     * \details Given a cyclically sorted array of unique integers, find the smallest element.
     * \param array a sorted array of integers
     * \return the index of the smallest element
     */
    int SearchSmallestElementInCyclicallySortedArray(
        const std::vector<int>& array);
}

// ----------------------------------------------------------------------------
inline int SearchSortedArray::SearchFirstOfKey(
    const std::vector<int>& array,
    const int key)
{
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;
    int result = -1;

    while (left <= right)
    {
        const int mid = left + ((right - left) / 2);
        if (array[mid] > key)
        {
            right = mid - 1;
        }
        else if (array[mid] == key)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

// ----------------------------------------------------------------------------
inline int SearchSortedArray::SearchFirstGreaterThanKey(
    const std::vector<int>& array,
    const int key)
{
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;
    int result = -1;

    while (left <= right)
    {
        const int mid = left + ((right - left) / 2);
        if (array[mid] > key)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return result;
}

// ----------------------------------------------------------------------------
inline std::vector<int> SearchSortedArray::SearchEntryEqualToItsIndex(
    const std::vector<int>& array)
{
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;
    std::vector<int> result;

    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (array[mid] > mid)
        {
            right = mid - 1;
        }
        else if (array[mid] == mid)
        {
            result.push_back(mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

// ----------------------------------------------------------------------------
inline int SearchSortedArray::SearchSmallestElementInCyclicallySortedArray(
    const std::vector<int>& array)
{
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;

    while (left < right)
    {
        const int mid = left + ((right - left) / 2);
        if (array[mid] > array[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

#endif
