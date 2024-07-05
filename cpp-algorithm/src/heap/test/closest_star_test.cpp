#include "closest_star.h"

#include <gtest/gtest.h>

GTEST_TEST(ClosestStar, FindClosestStar)
{
    std::vector<ClosestStar::Star> stars;
    stars.push_back({1, 2, 3});
    stars.push_back({4, 5, 6});
    stars.push_back({7, 8, 9});
    stars.push_back({10, 11, 12});
    stars.push_back({13, 14, 15});
    stars.push_back({16, 17, 18});
    stars.push_back({19, 20, 21});
    ASSERT_EQ(7, static_cast<int>(stars.size()));
    ASSERT_EQ(3, ClosestStar::FindClosestStar(stars, 3).size());
}
