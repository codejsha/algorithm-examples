#include "closest_star.h"

#include <queue>

auto ClosestStar::FindClosestStar(std::vector<Star>& stars, const int k) -> std::priority_queue<Star>
{
    std::priority_queue<Star> max_heap;

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
