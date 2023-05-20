#include "nearest_repeated_entry.h"

#include <gtest/gtest.h>

GTEST_TEST(FindNearestRepeatedEntry, EmptyArray)
{
    const std::vector<std::string> paragraph = {};
    constexpr auto expected = -1;
    const auto actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, SingleWord)
{
    const std::vector<std::string> paragraph = {"foo"};
    constexpr auto expected = -1;
    const auto actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, TwoWords)
{
    const std::vector<std::string> paragraph = {"foo", "bar"};
    constexpr auto expected = -1;
    const auto actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, TwoWordsRepeated)
{
    const std::vector<std::string> paragraph = {"foo", "bar", "foo"};
    constexpr auto expected = 2;
    const auto actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, SomeWordsRepeated)
{
    const std::vector<std::string> paragraph = {"All", "work", "and", "no", "play", "makes", "for",
                                                "no", "work", "no", "fun", "and", "no", "results"};
    constexpr auto expected = 2;
    const auto actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}
