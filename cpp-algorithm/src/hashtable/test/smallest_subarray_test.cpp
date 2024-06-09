#include "smallest_subarray.h"

#include <gtest/gtest.h>

GTEST_TEST(FindSmallestSubarrayCoveringSet, NoMatch)
{
    const std::vector<std::string> paragraph{"a", "b", "c"};
    const std::vector<std::string> keywords{"d", "e", "f"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSubset(paragraph, keywords);
    EXPECT_EQ(-1, std::get<0>(result));
    EXPECT_EQ(-1, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarrayCoveringSet, SingleMatch)
{
    const std::vector<std::string> paragraph{"a", "b", "c"};
    const std::vector<std::string> keywords{"b"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSubset(paragraph, keywords);
    EXPECT_EQ(1, std::get<0>(result));
    EXPECT_EQ(1, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarrayCoveringSet, MultipleMatches)
{
    const std::vector<std::string> paragraph{"apple", "banana", "apple", "apple", "dog", "cat",
                                             "apple", "dog", "banana", "apple", "cat", "dog"};
    const std::vector<std::string> keywords{"banana", "cat"};
    const auto result = SmallestSubarray::FindSmallestSubarrayCoveringSubset(paragraph, keywords);
    EXPECT_EQ(8, std::get<0>(result));
    EXPECT_EQ(10, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarraySequentiallyCoveringSubset, NoMatch)
{
    const std::vector<std::string> paragraph{"a", "b", "c"};
    const std::vector<std::string> keywords{"d", "e", "f"};
    const auto result = SmallestSubarray::FindSmallestSubarraySequentiallyCoveringSubset(paragraph, keywords);
    EXPECT_EQ(-1, std::get<0>(result));
    EXPECT_EQ(-1, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarraySequentiallyCoveringSubset, SingleMatch)
{
    const std::vector<std::string> paragraph{"a", "b", "c"};
    const std::vector<std::string> keywords{"b"};
    const auto result = SmallestSubarray::FindSmallestSubarraySequentiallyCoveringSubset(paragraph, keywords);
    EXPECT_EQ(1, std::get<0>(result));
    EXPECT_EQ(1, std::get<1>(result));
}

GTEST_TEST(FindSmallestSubarraySequentiallyCoveringSubset, MultipleMatches)
{
    const std::vector<std::string> paragraph{"apple", "banana", "apple", "apple", "dog", "cat",
                                             "apple", "dog", "banana", "apple", "cat", "dog"};
    const std::vector<std::string> keywords{"banana", "cat"};
    const auto result = SmallestSubarray::FindSmallestSubarraySequentiallyCoveringSubset(paragraph, keywords);
    EXPECT_EQ(8, std::get<0>(result));
    EXPECT_EQ(10, std::get<1>(result));
}
