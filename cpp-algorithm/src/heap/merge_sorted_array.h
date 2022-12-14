#ifndef CPP_ALGORITHM_MERGE_SORTED_ARRAY_H
#define CPP_ALGORITHM_MERGE_SORTED_ARRAY_H

#include <queue>
#include <vector>

namespace MergeSortedArray
{
    template <typename T, typename... U> auto MergeSortedArray(std::priority_queue<T>& queue, U... vectors)
        -> std::priority_queue<int, std::vector<int>, std::less<int>>
    {
        const auto length = static_cast<int>(sizeof...(vectors));
        auto vector_arr = std::vector<std::vector<T>>{vectors...};

        while (true)
        {
            for (auto i = 0; i < length; ++i)
            {
                if (!vector_arr[i].empty())
                {
                    queue.push(vector_arr[i].back());
                    vector_arr[i].pop_back();
                }
            }

            if (std::all_of(vector_arr.begin(), vector_arr.end(), [](const auto& v)
                    { return v.empty(); }))
            {
                break;
            }
        }
        return queue;
    }
}

#endif
