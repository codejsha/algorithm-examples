#include "online_data_median.h"

#include <queue>

auto OnlineDataMedian::FindMedian(std::deque<int>& stream) -> std::vector<double>
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
