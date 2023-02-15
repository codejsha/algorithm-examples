#include "smallest_subarray.h"

#include <gtest/gtest.h>

GTEST_TEST(FindSmallestSubarrayCoveringSet, NoMatch)
{
    const std::vector<std::string> paragraph{"a", "b", "c"};
    const std::unordered_set<std::string> keywords{"d", "e", "f"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSet(paragraph, keywords);
    EXPECT_EQ(-1, std::get<0>(result));
    EXPECT_EQ(-1, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarrayCoveringSet, SingleMatch)
{
    const std::vector<std::string> paragraph{"a", "b", "c"};
    const std::unordered_set<std::string> keywords{"b"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSet(paragraph, keywords);
    EXPECT_EQ(1, std::get<0>(result));
    EXPECT_EQ(1, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarrayCoveringSet, MultipleMatches)
{
    const std::vector<std::string> paragraph{"a", "b", "c", "a", "b", "c", "a", "b", "c"};
    const std::unordered_set<std::string> keywords{"a", "b", "c"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSet(paragraph, keywords);
    EXPECT_EQ(0, std::get<0>(result));
    EXPECT_EQ(2, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarrayCoveringSet, MultipleMatches2)
{
    const std::vector<std::string> paragraph{"apple", "banana", "apple", "apple", "dog", "cat", "apple", "dog", "banana", "apple", "cat", "dog"};
    const std::unordered_set<std::string> keywords{"banana", "cat"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSet(paragraph, keywords);
    EXPECT_EQ(8, std::get<0>(result));
    EXPECT_EQ(10, std::get<1>(result));
}
