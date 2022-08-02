#include "rod_cutting_problem.h"
#include <gtest/gtest.h>

TEST(RodCuttingTest, Simple)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expected_result = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 10}, {5, 13}, {6, 17}, {7, 18}, {8, 22}, {9, 25}, {10, 30}};

    const auto result1 = rodcutting::CutRod(price, 1);
    const auto result2 = rodcutting::CutRod(price, 2);
    const auto result3 = rodcutting::CutRod(price, 3);
    const auto result4 = rodcutting::CutRod(price, 4);
    const auto result5 = rodcutting::CutRod(price, 5);
    const auto result6 = rodcutting::CutRod(price, 6);
    const auto result7 = rodcutting::CutRod(price, 7);
    const auto result8 = rodcutting::CutRod(price, 8);
    const auto result9 = rodcutting::CutRod(price, 9);
    const auto result10 = rodcutting::CutRod(price, 10);

    ASSERT_EQ(result1, expected_result.at(1));
    ASSERT_EQ(result2, expected_result.at(2));
    ASSERT_EQ(result3, expected_result.at(3));
    ASSERT_EQ(result4, expected_result.at(4));
    ASSERT_EQ(result5, expected_result.at(5));
    ASSERT_EQ(result6, expected_result.at(6));
    ASSERT_EQ(result7, expected_result.at(7));
    ASSERT_EQ(result8, expected_result.at(8));
    ASSERT_EQ(result9, expected_result.at(9));
    ASSERT_EQ(result10, expected_result.at(10));
}

TEST(RodCuttingTest, DynamicProgrammingTopDown)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expected_result = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 10}, {5, 13}, {6, 17}, {7, 18}, {8, 22}, {9, 25}, {10, 30}};

    const auto result1 = rodcutting::MemoizedCutRod(price, 1);
    const auto result2 = rodcutting::MemoizedCutRod(price, 2);
    const auto result3 = rodcutting::MemoizedCutRod(price, 3);
    const auto result4 = rodcutting::MemoizedCutRod(price, 4);
    const auto result5 = rodcutting::MemoizedCutRod(price, 5);
    const auto result6 = rodcutting::MemoizedCutRod(price, 6);
    const auto result7 = rodcutting::MemoizedCutRod(price, 7);
    const auto result8 = rodcutting::MemoizedCutRod(price, 8);
    const auto result9 = rodcutting::MemoizedCutRod(price, 9);
    const auto result10 = rodcutting::MemoizedCutRod(price, 10);

    ASSERT_EQ(result1, expected_result.at(1));
    ASSERT_EQ(result2, expected_result.at(2));
    ASSERT_EQ(result3, expected_result.at(3));
    ASSERT_EQ(result4, expected_result.at(4));
    ASSERT_EQ(result5, expected_result.at(5));
    ASSERT_EQ(result6, expected_result.at(6));
    ASSERT_EQ(result7, expected_result.at(7));
    ASSERT_EQ(result8, expected_result.at(8));
    ASSERT_EQ(result9, expected_result.at(9));
    ASSERT_EQ(result10, expected_result.at(10));
}

TEST(RodCuttingTest, DynamicProgrammingBottomUp)
{
    const auto price = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 9}, {5, 10}, {6, 17}, {7, 17}, {8, 20}, {9, 24}, {10, 30}};
    const auto expected_result = std::map<int, int>{
        {1, 1}, {2, 5}, {3, 8}, {4, 10}, {5, 13}, {6, 17}, {7, 18}, {8, 22}, {9, 25}, {10, 30}};

    const auto result1 = rodcutting::BottomUpCutRod(price, 1);
    const auto result2 = rodcutting::BottomUpCutRod(price, 2);
    const auto result3 = rodcutting::BottomUpCutRod(price, 3);
    const auto result4 = rodcutting::BottomUpCutRod(price, 4);
    const auto result5 = rodcutting::BottomUpCutRod(price, 5);
    const auto result6 = rodcutting::BottomUpCutRod(price, 6);
    const auto result7 = rodcutting::BottomUpCutRod(price, 7);
    const auto result8 = rodcutting::BottomUpCutRod(price, 8);
    const auto result9 = rodcutting::BottomUpCutRod(price, 9);
    const auto result10 = rodcutting::BottomUpCutRod(price, 10);

    ASSERT_EQ(result1, expected_result.at(1));
    ASSERT_EQ(result2, expected_result.at(2));
    ASSERT_EQ(result3, expected_result.at(3));
    ASSERT_EQ(result4, expected_result.at(4));
    ASSERT_EQ(result5, expected_result.at(5));
    ASSERT_EQ(result6, expected_result.at(6));
    ASSERT_EQ(result7, expected_result.at(7));
    ASSERT_EQ(result8, expected_result.at(8));
    ASSERT_EQ(result9, expected_result.at(9));
    ASSERT_EQ(result10, expected_result.at(10));
}
