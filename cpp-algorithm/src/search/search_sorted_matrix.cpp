#include "search_sorted_matrix.h"

bool IsNotOutOfRange(const int row, const int col, const int row_len, const int col_len)
{
    return row >= 0 && row < row_len && col >= 0 && col < col_len;
}

bool SearchSortedMatrix::SearchSortedMatrix(const std::vector<std::vector<int>>& matrix, const int key)
{
    // matrix is empty, return false
    if (matrix.empty() || matrix[0].empty())
    {
        return false; 
    }

    const auto row_size = static_cast<int>(matrix.size());
    const auto col_size = static_cast<int>(matrix[0].size());

    // start from top right corner
    auto row = 0;
    auto col = static_cast<int>(matrix[0].size() - 1);

    while (IsNotOutOfRange(row, col, row_size, col_size))
    {
        if (matrix[row][col] == key)
        {
            return true;
        }

        // remove column
        if (matrix[row][col] > key)
        {
            --col;
        }
        // remove row
        // matrix[row][col] < key
        else
        {
            ++row;
        }
    }

    return false;
}
