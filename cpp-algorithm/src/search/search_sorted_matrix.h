#ifndef CPP_ALGORITHM_SEARCH_SORTED_MATRIX_H
#define CPP_ALGORITHM_SEARCH_SORTED_MATRIX_H
#include <vector>

namespace SearchSortedMatrix
{
    /**
     * \brief Search a key in a sorted 2D array.
     * \details The 2D array is sorted in ascending order from left to right and top to bottom.
     * \param matrix sorted 2D array
     * \param key the key to search for
     * \return true if the key is found, false otherwise
     */
    bool SearchSortedMatrix(
        const std::vector<std::vector<int>>& matrix,
        int key);
}

// ----------------------------------------------------------------------------
inline bool IsNotOutOfRange(
    const int row,
    const int col,
    const int row_len,
    const int col_len)
{
    return row >= 0 && row < row_len && col >= 0 && col < col_len;
}

// ----------------------------------------------------------------------------
inline bool SearchSortedMatrix::SearchSortedMatrix(
    const std::vector<std::vector<int>>& matrix,
    const int key)
{
    // matrix is empty, return false
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }

    const int row_size = static_cast<int>(matrix.size());
    const int col_size = static_cast<int>(matrix[0].size());

    // start from top right corner
    int row = 0;
    int col = static_cast<int>(matrix[0].size() - 1);

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

#endif
