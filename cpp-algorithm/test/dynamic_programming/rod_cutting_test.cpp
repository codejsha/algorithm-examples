#include "rod_cutting.h"

#include <gtest/gtest.h>

TEST(RodCuttingTest, Simple)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expectedResult = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 10}, {5, 13}, {6, 17}, {7, 18}, {8, 22}, {9, 25}, {10, 30}};

    const auto result1 = RodCutting::CutRod(price, 1);
    const auto result2 = RodCutting::CutRod(price, 2);
    const auto result3 = RodCutting::CutRod(price, 3);
    const auto result4 = RodCutting::CutRod(price, 4);
    const auto result5 = RodCutting::CutRod(price, 5);
    const auto result6 = RodCutting::CutRod(price, 6);
    const auto result7 = RodCutting::CutRod(price, 7);
    const auto result8 = RodCutting::CutRod(price, 8);
    const auto result9 = RodCutting::CutRod(price, 9);
    const auto result10 = RodCutting::CutRod(price, 10);

    ASSERT_EQ(result1, expectedResult.at(1));
    ASSERT_EQ(result2, expectedResult.at(2));
    ASSERT_EQ(result3, expectedResult.at(3));
    ASSERT_EQ(result4, expectedResult.at(4));
    ASSERT_EQ(result5, expectedResult.at(5));
    ASSERT_EQ(result6, expectedResult.at(6));
    ASSERT_EQ(result7, expectedResult.at(7));
    ASSERT_EQ(result8, expectedResult.at(8));
    ASSERT_EQ(result9, expectedResult.at(9));
    ASSERT_EQ(result10, expectedResult.at(10));
}

TEST(RodCuttingTest, DynamicProgrammingTopDown)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expectedResult = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 10}, {5, 13}, {6, 17}, {7, 18}, {8, 22}, {9, 25}, {10, 30}};

    const auto result1 = RodCutting::MemoizedCutRod(price, 1);
    const auto result2 = RodCutting::MemoizedCutRod(price, 2);
    const auto result3 = RodCutting::MemoizedCutRod(price, 3);
    const auto result4 = RodCutting::MemoizedCutRod(price, 4);
    const auto result5 = RodCutting::MemoizedCutRod(price, 5);
    const auto result6 = RodCutting::MemoizedCutRod(price, 6);
    const auto result7 = RodCutting::MemoizedCutRod(price, 7);
    const auto result8 = RodCutting::MemoizedCutRod(price, 8);
    const auto result9 = RodCutting::MemoizedCutRod(price, 9);
    const auto result10 = RodCutting::MemoizedCutRod(price, 10);

    ASSERT_EQ(result1, expectedResult.at(1));
    ASSERT_EQ(result2, expectedResult.at(2));
    ASSERT_EQ(result3, expectedResult.at(3));
    ASSERT_EQ(result4, expectedResult.at(4));
    ASSERT_EQ(result5, expectedResult.at(5));
    ASSERT_EQ(result6, expectedResult.at(6));
    ASSERT_EQ(result7, expectedResult.at(7));
    ASSERT_EQ(result8, expectedResult.at(8));
    ASSERT_EQ(result9, expectedResult.at(9));
    ASSERT_EQ(result10, expectedResult.at(10));
}

TEST(RodCuttingTest, DynamicProgrammingBottomUp)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expectedResult = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 10}, {5, 13}, {6, 17}, {7, 18}, {8, 22}, {9, 25}, {10, 30}};

    const auto result1 = RodCutting::BottomUpCutRod(price, 1);
    const auto result2 = RodCutting::BottomUpCutRod(price, 2);
    const auto result3 = RodCutting::BottomUpCutRod(price, 3);
    const auto result4 = RodCutting::BottomUpCutRod(price, 4);
    const auto result5 = RodCutting::BottomUpCutRod(price, 5);
    const auto result6 = RodCutting::BottomUpCutRod(price, 6);
    const auto result7 = RodCutting::BottomUpCutRod(price, 7);
    const auto result8 = RodCutting::BottomUpCutRod(price, 8);
    const auto result9 = RodCutting::BottomUpCutRod(price, 9);
    const auto result10 = RodCutting::BottomUpCutRod(price, 10);

    ASSERT_EQ(result1, expectedResult.at(1));
    ASSERT_EQ(result2, expectedResult.at(2));
    ASSERT_EQ(result3, expectedResult.at(3));
    ASSERT_EQ(result4, expectedResult.at(4));
    ASSERT_EQ(result5, expectedResult.at(5));
    ASSERT_EQ(result6, expectedResult.at(6));
    ASSERT_EQ(result7, expectedResult.at(7));
    ASSERT_EQ(result8, expectedResult.at(8));
    ASSERT_EQ(result9, expectedResult.at(9));
    ASSERT_EQ(result10, expectedResult.at(10));
}

TEST(RodCuttingTest, DynamicProgrammingExtendedBottomUp)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expectedResult = std::map<int, std::tuple<int, int>>{
        {1, {1, 1}}, {2, {5, 2}}, {3, {8, 3}}, {4, {10, 2}}, {5, {13, 2}},
        {6, {17, 6}}, {7, {18, 1}}, {8, {22, 2}}, {9, {25, 3}}, {10, {30, 10}}};

    const auto result1 = RodCutting::ExtendedBottomUpCutRod(price, 1);
    const auto result2 = RodCutting::ExtendedBottomUpCutRod(price, 2);
    const auto result3 = RodCutting::ExtendedBottomUpCutRod(price, 3);
    const auto result4 = RodCutting::ExtendedBottomUpCutRod(price, 4);
    const auto result5 = RodCutting::ExtendedBottomUpCutRod(price, 5);
    const auto result6 = RodCutting::ExtendedBottomUpCutRod(price, 6);
    const auto result7 = RodCutting::ExtendedBottomUpCutRod(price, 7);
    const auto result8 = RodCutting::ExtendedBottomUpCutRod(price, 8);
    const auto result9 = RodCutting::ExtendedBottomUpCutRod(price, 9);
    const auto result10 = RodCutting::ExtendedBottomUpCutRod(price, 10);

    ASSERT_EQ(result1, expectedResult.at(1));
    ASSERT_EQ(result2, expectedResult.at(2));
    ASSERT_EQ(result3, expectedResult.at(3));
    ASSERT_EQ(result4, expectedResult.at(4));
    ASSERT_EQ(result5, expectedResult.at(5));
    ASSERT_EQ(result6, expectedResult.at(6));
    ASSERT_EQ(result7, expectedResult.at(7));
    ASSERT_EQ(result8, expectedResult.at(8));
    ASSERT_EQ(result9, expectedResult.at(9));
    ASSERT_EQ(result10, expectedResult.at(10));
}
