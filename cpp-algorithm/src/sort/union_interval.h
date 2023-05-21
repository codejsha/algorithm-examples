#ifndef CPP_ALGORITHM_UNION_INTERVAL_H
#define CPP_ALGORITHM_UNION_INTERVAL_H

#include <vector>

namespace UnionInterval
{
    /**
     * \brief Union of intervals
     * \details Given a set of intervals, find the union of all intervals.
     * \param intervals start and end pairs of intervals
     * \return union of intervals
     */
    auto UnionOfIntervals(std::vector<std::pair<int, int>>& intervals)
        -> std::vector<std::pair<int, int>>;
}

#endif
