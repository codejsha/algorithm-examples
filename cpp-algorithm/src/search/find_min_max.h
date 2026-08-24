#ifndef CPP_ALGORITHM_FIND_MIN_MAX_H
#define CPP_ALGORITHM_FIND_MIN_MAX_H

#include <algorithm>
#include <vector>

namespace FindMinMax
{
    /**
     * \brief Find the minimum and maximum elements in an array.
     * \param array an array of integers
     * \return a pair of integers, the first element is the minimum and the second element is the maximum
     */
    std::pair<int, int> FindMinMax(
        const std::vector<int>& array);
}

// ----------------------------------------------------------------------------
inline std::pair<int, int> FindMinMax::FindMinMax(
    const std::vector<int>& array)
{
    int global_min;
    int global_max;
    std::tie(global_min, global_max) = std::minmax(array[0], array[1]);

    // compare 2 elements at a time
    for (int i = 2; i < static_cast<int>(array.size()); i += 2)
    {
        // compare two adjacent elements
        const auto& [local_min, local_max] = std::minmax(array[i], array[i + 1]);
        // compare local min/max with global min/max
        global_min = std::min(global_min, local_min);
        global_max = std::max(global_max, local_max);
    }

    // if there are odd number of elements in the array,
    // compare the last element with the existing global min/max
    if (array.size() % 2 == 1)
    {
        global_min = std::min(global_min, array.back());
        global_max = std::max(global_max, array.back());
    }

    return {global_min, global_max};
}

#endif
