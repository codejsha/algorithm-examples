#include "online_data_median.h"

#include <gtest/gtest.h>

GTEST_TEST(OnlineDataMedian, FindMedian)
{
    auto stream = std::deque{1, 0, 3, 5, 2, 0, 1};
    const auto expected = std::vector<double>{1, 0.5, 1, 2, 2, 1.5, 1};
    const auto result = OnlineDataMedian::FindMedian(stream);
    EXPECT_EQ(expected, result);
}
