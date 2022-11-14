#include "advancing_through.h"

#include <gtest/gtest.h>

GTEST_TEST(AdvancingThroughTest, CanReachEnd)
{
    EXPECT_TRUE(AdvancingThrough::CanReachEnd(std::vector<int>{3, 3, 1, 0, 2, 0, 1}));

    EXPECT_FALSE(AdvancingThrough::CanReachEnd(std::vector<int>{3, 2, 0, 0, 2, 0, 1}));
}
