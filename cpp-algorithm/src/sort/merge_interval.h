#ifndef CPP_ALGORITHM_MERGE_INTERVAL_H
#define CPP_ALGORITHM_MERGE_INTERVAL_H

#include <vector>

namespace MergeInterval
{
    /**
     * \brief Merge intervals if they overlap.
     * \details Given a collection of intervals, merge all overlapping intervals.
     * \param intervals intervals to be merged
     * \return merged intervals
     */
    auto MergeIntervals(std::vector<std::vector<int>>& intervals)
        -> std::vector<std::vector<int>>;

    /**
     * \brief Merge intervals if they overlap.
     * \details Given a collection of intervals, merge all overlapping intervals.
     * \param intervals interval collection
     * \param new_interval new interval to be merged
     * \return merged intervals
     */
    auto MergeIntervals(std::vector<std::vector<int>>& intervals, std::vector<int> new_interval)
        -> std::vector<std::vector<int>>;
}
#endif
