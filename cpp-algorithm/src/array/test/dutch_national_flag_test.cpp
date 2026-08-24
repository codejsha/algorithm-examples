#include "dutch_national_flag.h"

#include <gtest/gtest.h>

GTEST_TEST(DutchFlag, Partition1)
{
    const auto input = std::vector<DutchFlag::Color>{
        DutchFlag::Blue,
        DutchFlag::Red,
        DutchFlag::White,
        DutchFlag::Blue,
        DutchFlag::Red,
        DutchFlag::White};
    const auto expected = std::vector<DutchFlag::Color>{
        DutchFlag::Red,
        DutchFlag::Red,
        DutchFlag::White,
        DutchFlag::White,
        DutchFlag::Blue,
        DutchFlag::Blue};

    auto arr = input;
    const auto result = DutchFlag::DutchFlagPartition1(2, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(DutchFlag, Partition2)
{
    const auto input = std::vector<DutchFlag::Color>{
        DutchFlag::Blue,
        DutchFlag::Red,
        DutchFlag::White,
        DutchFlag::Blue,
        DutchFlag::Red,
        DutchFlag::White};
    const auto expected = std::vector<DutchFlag::Color>{
        DutchFlag::Red,
        DutchFlag::Red,
        DutchFlag::White,
        DutchFlag::White,
        DutchFlag::Blue,
        DutchFlag::Blue};

    auto arr = input;
    const auto result = DutchFlag::DutchFlagPartition2(2, arr);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(DutchFlag, Partition3)
{
    const auto input = std::vector<DutchFlag::Color>{
        DutchFlag::Blue,
        DutchFlag::Red,
        DutchFlag::White,
        DutchFlag::Blue,
        DutchFlag::Red,
        DutchFlag::White};
    const auto expected = std::vector<DutchFlag::Color>{
        DutchFlag::Red,
        DutchFlag::Red,
        DutchFlag::White,
        DutchFlag::White,
        DutchFlag::Blue,
        DutchFlag::Blue};

    auto arr = input;
    const auto result = DutchFlag::DutchFlagPartition3(2, arr);
    EXPECT_EQ(expected, result);
}
