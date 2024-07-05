#include "h_index.h"

#include <gtest/gtest.h>

GTEST_TEST(HIndex1, Successful)
{
    auto citations = std::vector<int>{1, 4, 1, 4, 2, 1, 3, 5, 6};
    constexpr int expected = 4;
    EXPECT_EQ(expected, HIndex::HIndex1(citations));
}

GTEST_TEST(HIndex2, Successful)
{
    auto citations = std::vector<int>{1, 4, 1, 4, 2, 1, 3, 5, 6};
    constexpr int expected = 4;
    EXPECT_EQ(expected, HIndex::HIndex2(citations));
}
