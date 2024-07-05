#include "search_sorted_array.h"

auto SearchSortedArray::SearchFirstOfKey(const std::vector<int>& array, const int key) -> int
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

auto SearchSortedArray::SearchFirstGreaterThanKey(const std::vector<int>& array, const int key) -> int
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

auto SearchSortedArray::SearchEntryEqualToItsIndex(const std::vector<int>& array) -> std::vector<int>
{
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;
    std::vector<int> result;

    while (left <= right)
    {
        auto mid = left + ((right - left) / 2);
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

auto SearchSortedArray::SearchSmallestElementInCyclicallySortedArray(const std::vector<int>& array) -> int
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
