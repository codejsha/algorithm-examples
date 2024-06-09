#include "collatz_conjecture.h"

#include <gtest/gtest.h>

TEST(CollatzConjecture, LowerThanTen)
{
    auto expected = std::vector<long>{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto result = CollatzConjecture::FindNumbersSatisfyingCollatzConjecture(10);

    ASSERT_EQ(expected.size(), result.size());
    for (auto i = 0; i < static_cast<long>(expected.size()); ++i)
    {
        ASSERT_EQ(expected[i], result[i]);
    }
}

TEST(CollatzConjecture, LowerThanTwenty)
{
    auto expected = std::vector<long>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    auto result = CollatzConjecture::FindNumbersSatisfyingCollatzConjecture(20);

    ASSERT_EQ(expected.size(), result.size());
    for (auto i = 0; i < static_cast<long>(expected.size()); ++i)
    {
        ASSERT_EQ(expected[i], result[i]);
    }
}
