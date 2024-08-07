#include "search_sorted_matrix.h"

#include <gtest/gtest.h>

TEST(SearchSortedMatrix, KeyExistsCase1)
{
    const auto matrix = std::vector<std::vector<int>>{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    constexpr int key = 5;
    constexpr bool expected = true;
    const bool result = SearchSortedMatrix::SearchSortedMatrix(matrix, key);
    EXPECT_EQ(expected, result);
}

TEST(SearchSortedMatrix, KeyExistsCase2)
{
    const auto matrix = std::vector<std::vector<int>>{
        {-1, 2, 4, 4, 6},
        {1, 5, 5, 9, 21},
        {3, 6, 6, 9, 22},
        {3, 6, 8, 10, 24},
        {6, 8, 9, 12, 25},
        {8, 10, 12, 13, 40}};
    constexpr int key = 8;
    constexpr bool expected = true;
    const bool result = SearchSortedMatrix::SearchSortedMatrix(matrix, key);
    EXPECT_EQ(expected, result);
}

TEST(SearchSortedMatrix, KeyNotExistsCase1)
{
    const auto matrix = std::vector<std::vector<int>>{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    constexpr int key = 10;
    constexpr bool expected = false;
    const bool result = SearchSortedMatrix::SearchSortedMatrix(matrix, key);
    EXPECT_EQ(expected, result);
}

TEST(SearchSortedMatrix, KeyNotExistsCase2)
{
    const auto matrix = std::vector<std::vector<int>>{
        {-1, 2, 4, 4, 6},
        {1, 5, 5, 9, 21},
        {3, 6, 6, 9, 22},
        {3, 6, 8, 10, 24},
        {6, 8, 9, 12, 25},
        {8, 10, 12, 13, 40}};
    constexpr int key = 7;
    constexpr bool expected = false;
    const bool result = SearchSortedMatrix::SearchSortedMatrix(matrix, key);
    EXPECT_EQ(expected, result);
}
