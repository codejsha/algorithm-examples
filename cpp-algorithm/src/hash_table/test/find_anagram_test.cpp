#include "find_anagram.h"

#include <algorithm>
#include <gtest/gtest.h>

GTEST_TEST(FindAnagramMappings, BasicCase1)
{
    const std::vector<std::string> dictionary = {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom", "listen", "levis", "money"};
    const std::vector<std::vector<std::string>> expected_anagram_mappings = {{"debitcard", "badcredit"}, {"elvis", "lives", "levis"}, {"silent", "listen"}};
    const auto actual_anagram_mappings = FindAnagram::FindAnagramMappings(dictionary);
    EXPECT_TRUE(std::ranges::is_permutation(actual_anagram_mappings, expected_anagram_mappings));
}
