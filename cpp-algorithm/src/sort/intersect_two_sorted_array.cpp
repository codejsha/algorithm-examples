#include "intersect_two_sorted_array.h"

#include <algorithm>
#include <ranges>

std::vector<int> IntersectTwoSortedArray::IntersectTwoSortedArrayLoopJoin(const std::vector<int>& arr1,
                                                                          const std::vector<int>& arr2)
{
    std::vector<int> intersection;
    for (auto i = 1; i < static_cast<int>(arr1.size()); ++i)
    {
        if (arr1[i] != arr1[i - 1] && std::ranges::find(arr2, arr1[i]) != arr2.end())
        {
            intersection.emplace_back(arr1[i]);
        }
    }
    return intersection;
}

std::vector<int> IntersectTwoSortedArray::IntersectTwoSortedArrayLoopJoin2(const std::vector<int>& arr1,
                                                                           const std::vector<int>& arr2)
{
    std::vector<int> intersection;
    for (auto i = 1; i < static_cast<int>(arr1.size()); ++i)
    {
        if ((arr1[i] != arr1[i - 1]) && std::ranges::binary_search(arr2, arr1[i]))
        {
            intersection.emplace_back(arr1[i]);
        }
    }
    return intersection;
}

std::vector<int> IntersectTwoSortedArray::IntersectTwoSortedArray(const std::vector<int>& arr1,
                                                                  const std::vector<int>& arr2)
{
    std::vector<int> intersection;
    auto i = 0;
    auto j = 0;
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
