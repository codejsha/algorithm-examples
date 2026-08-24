#ifndef CPP_ALGORITHM_ONLINE_DATA_MEDIAN_H
#define CPP_ALGORITHM_ONLINE_DATA_MEDIAN_H

#include <deque>
#include <queue>
#include <vector>

namespace OnlineDataMedian
{
    /**
     * \brief Find the median of a stream of numbers.
     * \details Given a stream of numbers, find the median of the stream.
     * \param stream a stream of numbers
     * \return the median of the stream
     */
    std::vector<double> FindMedian(std::deque<int>& stream);
}

// ----------------------------------------------------------------------------
inline std::vector<double> OnlineDataMedian::FindMedian(std::deque<int>& stream)
{
    // min heap to store the larger half elements
    auto min_heap = std::priority_queue<int, std::vector<int>, std::greater<>>{};
    // max heap to store the smaller half elements
    auto max_heap = std::priority_queue<int>{};
    std::vector<double> result;

    while (!stream.empty())
    {
        min_heap.emplace(stream.front());
        stream.pop_front();
        max_heap.emplace(min_heap.top());
        min_heap.pop();

        if (max_heap.size() > min_heap.size())
        {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }

        result.emplace_back(min_heap.size() == max_heap.size() ? (min_heap.top() + max_heap.top()) / 2.0
                                                               : min_heap.top());
    }

    return result;
}

#endif
