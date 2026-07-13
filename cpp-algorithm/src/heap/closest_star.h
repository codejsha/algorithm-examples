#ifndef CPP_ALGORITHM_CLOSEST_STAR_H
#define CPP_ALGORITHM_CLOSEST_STAR_H

#include <cmath>
#include <queue>
#include <vector>

namespace ClosestStar
{
    struct Star
    {
        double x;
        double y;
        double z;

        [[nodiscard]] double Distance() const { return std::sqrt((x * x) + (y * y) + (z * z)); }

        [[nodiscard]] bool operator<(const Star& other) const { return Distance() < other.Distance(); }
    };

    /**
     * \brief Find the closest star.
     * \details Given a list of stars and their coordinates in a 3D space, find the closest star.
     * \param stars a list of stars
     * \param k number of closest stars to find
     * \return the closest star
     */
    std::priority_queue<Star> FindClosestStar(
        std::vector<Star>& stars,
        int k);
}

// ----------------------------------------------------------------------------
inline std::priority_queue<ClosestStar::Star> ClosestStar::FindClosestStar(
    std::vector<Star>& stars,
    const int k)
{
    std::priority_queue<Star> max_heap;

    while (!stars.empty())
    {
        Star star = stars.back();
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

#endif
