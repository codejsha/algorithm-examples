#include "closest_star.h"

#include <queue>

auto ClosestStar::FindClosestStar(std::vector<Star>& stars, const int k) -> std::priority_queue<Star>
{
    auto max_heap = std::priority_queue<Star>{};

    while (!stars.empty())
    {
        auto star = stars.back();
        stars.pop_back();

        if (static_cast<int>(max_heap.size()) < k)
        {
            max_heap.push(star);
        }
        else
        {
            if (star.Distance() < max_heap.top().Distance())
            {
                max_heap.pop();
                max_heap.push(star);
            }
        }
    }

    return max_heap;
}
