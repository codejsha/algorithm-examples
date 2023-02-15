#ifndef CPP_ALGORITHM_SMALLEST_SUBARRAY_H
#define CPP_ALGORITHM_SMALLEST_SUBARRAY_H

#include <string>
#include <unordered_set>
#include <vector>

namespace SmallestSubarray
{
    /// @brief Find the smallest subarray that covers all the elements in a set.
    /// @param paragraph an array
    /// @param keywords a set
    /// @return a tuple of the start and end indices of the smallest subarray
    auto FindSmallestSubarrayCoveringSet(
        const std::vector<std::string>& paragraph,
        const std::unordered_set<std::string>& keywords)
        -> std::tuple<int, int>;
}

#endif
