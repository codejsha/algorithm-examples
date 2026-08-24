#ifndef CPP_ALGORITHM_MERGE_INTERVAL_H
#define CPP_ALGORITHM_MERGE_INTERVAL_H

#include <algorithm>
#include <vector>

namespace MergeInterval
{
    /**
     * \brief Merge intervals if they overlap.
     * \details Given a collection of intervals, merge all overlapping intervals.
     * \param intervals intervals to be merged
     * \return merged intervals
     */
    std::vector<std::vector<int>> MergeIntervals(
        std::vector<std::vector<int>>& intervals);

    /**
     * \brief Merge intervals if they overlap.
     * \details Given a collection of intervals, merge all overlapping intervals.
     * \param intervals interval collection
     * \param new_interval new interval to be merged
     * \return merged intervals
     */
    std::vector<std::vector<int>> MergeIntervals(
        std::vector<std::vector<int>>& intervals,
        std::vector<int> new_interval);
}

// ----------------------------------------------------------------------------
inline std::vector<std::vector<int>> MergeInterval::MergeIntervals(
    std::vector<std::vector<int>>& intervals)
{
    // if array is empty
    if (intervals.empty())
    {
        return {};
    }

    // sort intervals by start time
    std::ranges::sort(intervals, [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> result;
    result.emplace_back(intervals[0]);
    intervals.erase(intervals.begin());

    for (const auto& interval : intervals)
    {
        // if current interval does not overlap with previous
        if (result.back()[1] < interval[0])
        {
            result.emplace_back(interval);
        }
        else
        {
            result.back()[1] = std::max(result.back()[1], interval[1]);
        }
    }

    return result;
}

// ----------------------------------------------------------------------------
inline std::vector<std::vector<int>> MergeInterval::MergeIntervals(
    std::vector<std::vector<int>>& intervals,
    std::vector<int> new_interval)
{
    std::vector<std::vector<int>> result;
    int idx = 0;

    // add all intervals starting before new_interval
    while (idx < static_cast<int>(intervals.size()) && intervals[idx][1] < new_interval[0])
    {
        result.emplace_back(intervals[idx]);
        ++idx;
    }

    // merge all overlapping intervals to one considering new_interval
    while (idx < static_cast<int>(intervals.size()) && intervals[idx][0] <= new_interval[1])
    {
        new_interval[0] = std::min(intervals[idx][0], new_interval[0]);
        new_interval[1] = std::max(intervals[idx][1], new_interval[1]);
        ++idx;
    }
    result.emplace_back(new_interval);

    // add all intervals starting after new_interval
    while (idx < static_cast<int>(intervals.size()))
    {
        result.emplace_back(intervals[idx]);
        ++idx;
    }

    return result;
}

#endif
