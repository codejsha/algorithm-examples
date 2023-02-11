#include "anonymous_letter.h"

#include <gtest/gtest.h>

GTEST_TEST(IsLetterConstructibleFromMagazine, BasicCase1)
{
    const auto letter = "hello";
    const auto magazine = "hello world";
    constexpr auto expected = true;
    const auto result = AnonymousLetter::IsLetterConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IsLetterConstructibleFromMagazine, BasicCase2)
{
    const auto letter = "hi";
    const auto magazine = "hi world";
    constexpr auto expected = true;
    const auto result = AnonymousLetter::IsLetterConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IsWordConstructibleFromMagazine, BasicCase1)
{
    const auto letter = "hello";
    const auto magazine = "hello world";
    constexpr auto expected = true;
    const auto result = AnonymousLetter::IsWordConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IsWordConstructibleFromMagazine, BasicCase2)
{
    const auto letter = "hi";
    const auto magazine = "hi world";
    constexpr auto expected = true;
    const auto result = AnonymousLetter::IsWordConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}
