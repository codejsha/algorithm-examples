#include "combination.h"

#include <gtest/gtest.h>

GTEST_TEST(GenerateCombination, ValidIntInput1)
{
    const auto seq = std::vector<int>{2, 4, 6, 8};
    constexpr auto k = 2;
    const auto expected = std::vector<std::vector<int>>{
        {2, 4},
        {2, 6},
        {2, 8},
        {4, 6},
        {4, 8},
        {6, 8}};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, ValidIntInput2)
{
    const auto seq = std::vector<int>{0, 1, 2, 3, 4, 5};
    constexpr auto k = 2;
    const auto expected = std::vector<std::vector<int>>{
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5},
        {1, 2},
        {1, 3},
        {1, 4},
        {1, 5},
        {2, 3},
        {2, 4},
        {2, 5},
        {3, 4},
        {3, 5},
        {4, 5}};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, ValidStringArrayInput1)
{
    const auto seq = std::vector<std::string>{"a", "b", "c"};
    constexpr auto k = 2;
    const auto expected = std::vector<std::vector<std::string>>{
        {"a", "b"},
        {"a", "c"},
        {"b", "c"}};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, ValidStringInput1)
{
    const auto seq = "abc";
    constexpr auto k = 2;
    const auto expected = std::vector<std::string>{
        "ab",
        "ac",
        "bc"};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, KGreaterThanStringLength)
{
    const auto seq = "abcd";
    constexpr auto k = 5;
    const auto expected = std::vector<std::string>{};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, EmptyString)
{
    const auto seq = "";
    constexpr auto k = 3;
    const auto expected = std::vector<std::string>{};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, KZero)
{
    const auto seq = "abc";
    constexpr auto k = 0;
    const auto expected = std::vector<std::string>{""};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(GenerateCombination, SingleCharacterString)
{
    const auto seq = "a";
    constexpr auto k = 1;
    const auto expected = std::vector<std::string>{"a"};
    const auto result = Combination::GenerateCombination(seq, k);
    EXPECT_EQ(expected, result);
}
