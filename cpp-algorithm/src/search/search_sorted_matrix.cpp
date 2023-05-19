#include "search_sorted_matrix.h"

auto SearchSortedMatrix::SearchSortedMatrix(const std::vector<std::vector<int>>& matrix, const int key) -> bool
{
    auto row = 0;
    auto col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0)
    {
        if (matrix[row][col] == key)
        {
            return true;
        }
        if (matrix[row][col] > key)
        {
            --col;
        }
        // matrix[row][col] > key
        else
        {
            ++row;
        }
    }

    return false;
}
