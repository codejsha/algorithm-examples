#ifndef CPP_ALGORITHM_SEARCH_SORTED_MATRIX_H
#define CPP_ALGORITHM_SEARCH_SORTED_MATRIX_H
#include <vector>

namespace SearchSortedMatrix
{
    /// @brief Search in a 2D sorted array.
    /// @param matrix sorted 2D array
    /// @param key the key to search for 
    /// @return true if the key is found, false otherwise
    auto SearchSortedMatrix(const std::vector<std::vector<int>>& matrix, int key) -> bool;
}

#endif
