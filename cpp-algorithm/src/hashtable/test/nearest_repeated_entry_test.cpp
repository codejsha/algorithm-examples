#include "nearest_repeated_entry.h"

#include <gtest/gtest.h>

GTEST_TEST(FindNearestRepeatedEntry, EmptyArray)
{
    const std::vector<std::string> paragraph = {};
    constexpr int expected = -1;
    const int actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, SingleWord)
{
    const std::vector<std::string> paragraph = {"foo"};
    constexpr int expected = -1;
    const int actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, TwoWords)
{
    const std::vector<std::string> paragraph = {"foo", "bar"};
    constexpr int expected = -1;
    const int actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, TwoWordsRepeated)
{
    const std::vector<std::string> paragraph = {"foo", "bar", "foo"};
    constexpr int expected = 2;
    const int actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}

GTEST_TEST(FindNearestRepeatedEntry, SomeWordsRepeated)
{
    const std::vector<std::string> paragraph = {"All", "work", "and", "no", "play", "makes", "for",
                                                "no", "work", "no", "fun", "and", "no", "results"};
    constexpr int expected = 2;
    const int actual = NearestRepeatedEntry::FindNearestRepeatedEntry(paragraph);
    EXPECT_EQ(expected, actual);
}
