#include "h_index.h"

#include <gtest/gtest.h>

GTEST_TEST(HIndex, Successful1)
{
    auto citations = std::vector<int>{1, 4, 1, 4, 2, 1, 3, 5, 6};
    auto expected = 4;
    EXPECT_EQ(expected, HIndex::HIndex(citations));
}
