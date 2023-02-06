#include "search_sorted_array.h"

auto SearchSortedArray::SearchFirstOfKey(const std::vector<int>& array, const int key) -> int
{
    auto left = 0;
    auto right = array.size() - 1;
    auto result = -1;

    while (left <= right)
    {
        auto mid = left + ((right - left) / 2);
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
    auto left = 0;
    auto right = array.size() - 1;
    auto result = -1;

    while (left <= right)
    {
        auto mid = left + ((right - left) / 2);
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
    auto left = 0;
    auto right = array.size() - 1;
    auto result = std::vector<int>{};

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
    auto left = 0;
    auto right = array.size() - 1;

    while (left < right)
    {
        auto mid = left + ((right - left) / 2);
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
