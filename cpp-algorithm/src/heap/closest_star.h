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

        [[nodiscard]] auto Distance() const -> double { return std::sqrt((x * x) + (y * y) + (z * z)); }

        [[nodiscard]] auto operator<(const Star& other) const -> bool { return Distance() < other.Distance(); }
    };

    /// @brief Find the closest star.
    /// @details Given a list of stars and their coordinates in a 3D space, find the closest star.
    /// @param stars a list of stars
    /// @param k number of closest stars to find
    /// @return the closest star
    auto FindClosestStar(std::vector<Star>& stars, int k) -> std::priority_queue<Star>;

}
#endif
