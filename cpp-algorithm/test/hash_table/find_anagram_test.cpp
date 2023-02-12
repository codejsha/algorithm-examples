#include "find_anagram.h"

#include <gtest/gtest.h>

GTEST_TEST(FindAnagramMappings, BasicCase1)
{
    const std::vector<std::string> dictionary = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis", "money"};
    const std::vector<std::vector<std::string>> expected_anagram_mappings = {{"debitcard", "badcredit"}, {"elvis", "lives", "levis"}, {"silent", "listen"}};
    const auto actual_anagram_mappings = FindAnagram::FindAnagramMappings(dictionary);
    EXPECT_EQ(expected_anagram_mappings, actual_anagram_mappings);
}
