#include "anonymous_letter.h"

#include <gtest/gtest.h>

GTEST_TEST(IsLetterConstructibleFromMagazine, BasicCase1)
{
    const std::string letter = "hello";
    const std::string magazine = "hello world";
    constexpr bool expected = true;
    const bool result = AnonymousLetter::IsLetterConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IsLetterConstructibleFromMagazine, BasicCase2)
{
    const std::string letter = "hi";
    const std::string magazine = "hi world";
    constexpr bool expected = true;
    const bool result = AnonymousLetter::IsLetterConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IsWordConstructibleFromMagazine, BasicCase1)
{
    const std::string letter = "hello";
    const std::string magazine = "hello world";
    constexpr bool expected = true;
    const bool result = AnonymousLetter::IsWordConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(IsWordConstructibleFromMagazine, BasicCase2)
{
    const std::string letter = "hi";
    const std::string magazine = "hi world";
    constexpr bool expected = true;
    const bool result = AnonymousLetter::IsWordConstructibleFromMagazine(letter, magazine);
    EXPECT_EQ(expected, result);
}
