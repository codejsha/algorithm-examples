#include "advancing_through.h"

#include <gtest/gtest.h>

GTEST_TEST(AdvancingThrough, CanReachEnd_WhenReachable)
{
    // Test case: [3, 3, 1, 0, 2, 0, 1]
    // index: 0 -> 1 -> 4 -> 6 (reachable)
    EXPECT_TRUE(AdvancingThrough::CanReachEnd(std::vector<int>{3, 3, 1, 0, 2, 0, 1}));
}

GTEST_TEST(AdvancingThrough, CanReachEnd_WhenUnreachable)
{
    // Test case: [3, 2, 0, 0, 2, 0, 1]
    // (unreachable)
    EXPECT_FALSE(AdvancingThrough::CanReachEnd(std::vector<int>{3, 2, 0, 0, 2, 0, 1}));
}

