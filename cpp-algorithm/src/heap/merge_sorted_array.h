#ifndef CPP_ALGORITHM_MERGE_SORTED_ARRAY_H
#define CPP_ALGORITHM_MERGE_SORTED_ARRAY_H

#include <queue>
#include <vector>

namespace MergeSortedArray
{
    /**
     * \brief Merge sorted arrays into a single sorted array.
     * \details Given k sorted integer arrays, merge them into a single sorted array.
     * The arrays are sorted in ascending order.
     * \tparam T parameter pack of sorted arrays
     * \param vectors k sorted integer arrays
     * \return a single sorted array
     */
    template <typename... T>
    auto MergeSortedArray(T... vectors) -> std::priority_queue<int, std::vector<int>, std::less<int>>
    {
        auto queue = std::priority_queue<int>{};
        const auto length = static_cast<int>(sizeof...(vectors));
        auto vector_arr = std::vector<std::vector<int>>{vectors...};

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

            // check if all vectors are empty
            if (std::all_of(vector_arr.begin(), vector_arr.end(), [](const auto& v) { return v.empty(); }))
            {
                break;
            }
        }
        return queue;
    }
}

#endif
