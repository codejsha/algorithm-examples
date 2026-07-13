#ifndef CPP_ALGORITHM_UNION_INTERVAL_H
#define CPP_ALGORITHM_UNION_INTERVAL_H

#include <algorithm>
#include <vector>

namespace UnionInterval
{
    /**
     * \brief Union of intervals
     * \details Given a set of intervals, find the union of all intervals.
     * \param intervals start and end pairs of intervals
     * \return union of intervals
     */
    std::vector<std::pair<int, int>> UnionOfIntervals(
        std::vector<std::pair<int, int>>& intervals);
}

// ----------------------------------------------------------------------------
inline std::vector<std::pair<int, int>> UnionInterval::UnionOfIntervals(
    std::vector<std::pair<int, int>>& intervals)

{
    // if array is empty
    if (intervals.empty())
    {
        return {};
    }

    // sort intervals by start time
    std::ranges::sort(intervals, [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    });

    std::vector<std::pair<int, int>> result;
    result.push_back(intervals[0]);

    for (const auto& interval : intervals)
    {
        // if current interval overlaps with the previous
        if (interval.first <= result.back().second)
        {
            result.back().second = std::max(result.back().second, interval.second);
        }
        else
        {
            result.push_back(interval);
        }
    }

    return result;
}

#endif
