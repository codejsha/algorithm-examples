#include "sort_increasing_decreasing_array.h"

#include <algorithm>
#include <iterator>

auto IncreasingDecreasingArray::SortIncreasingDecreasingArray(const std::vector<int>& arr) -> std::vector<int>
{
    auto sorted_arr = std::vector<int>{};
    auto increasing = true;
    auto is_transition = false;
    auto begin = arr.begin();
    auto end = arr.begin();

    // if the array is empty
    if (arr.empty())
    {
        return sorted_arr;
    }

    // if the array has only one element
    if (arr.size() == 1)
    {
        sorted_arr.push_back(arr.front());
        return sorted_arr;
    }

    for (int i = 1; i < static_cast<int>(arr.size()); ++i)
    {
        if (arr[i - 1] < arr[i])
        {
            if (!increasing)
            {
                is_transition = true;
                end = arr.begin() + i - 1;
            }
            increasing = true;
        }
        else if (arr[i - 1] > arr[i])
        {
            if (increasing)
            {
                is_transition = true;
                end = arr.begin() + i - 1;
            }
            increasing = false;
        }

        // if we have a transition, insert the subarray into the sorted array and sort it
        if (is_transition)
        {
            if (increasing)
            {
                sorted_arr.insert(std::end(sorted_arr), begin, end + 1);
                std::ranges::sort(sorted_arr);
            }
            else
            {
                sorted_arr.insert(std::end(sorted_arr), begin, end + 1);
                std::ranges::sort(sorted_arr, std::less<int>{});
            }
            is_transition = false;
            begin = arr.begin() + i;
        }

        // if we are at the end of the array,
        // insert the subarray into the sorted array and sort it
        if (i == static_cast<int>(arr.size()) - 1)
        {
            if (increasing)
            {
                sorted_arr.insert(std::end(sorted_arr), begin, arr.end());
                std::ranges::sort(sorted_arr);
            }
            else
            {
                sorted_arr.insert(std::end(sorted_arr), begin, arr.end());
                std::ranges::sort(sorted_arr, std::less<int>{});
            }
        }
    }

    return sorted_arr;
}
