#ifndef CPP_ALGORITHM_FIND_MIN_MAX_H
#define CPP_ALGORITHM_FIND_MIN_MAX_H

#include <vector>

namespace FindMinMax
{
    /**
     * \brief Find the minimum and maximum elements in an array.
     * \param array an array of integers
     * \return a pair of integers, the first element is the minimum and the second element is the maximum
     */
    auto FindMinMax(const std::vector<int>& array) -> std::pair<int, int>;
}

#endif
