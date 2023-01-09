#ifndef CPP_ALGORITHM_ONLINE_DATA_MEDIAN_H
#define CPP_ALGORITHM_ONLINE_DATA_MEDIAN_H

#include <deque>
#include <vector>

namespace OnlineDataMedian
{
    /// @brief Find the median of a stream of numbers.
    /// @details Given a stream of numbers, find the median of the stream.
    /// @param stream a stream of numbers
    /// @return the median of the stream
    auto FindMedian(std::deque<int>& stream) -> std::vector<double>;
}

#endif
