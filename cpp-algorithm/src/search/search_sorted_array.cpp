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
