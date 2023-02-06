#ifndef CPP_ALGORITHM_COMPUTE_SQUARE_ROOT_H
#define CPP_ALGORITHM_COMPUTE_SQUARE_ROOT_H

namespace ComputeSquareRoot
{
    /// @brief Compute the integer square root of a number.
    /// @details When given a non-negative integer,
    /// return the largest integer whose square is less than or equal to the number.
    /// @param k non-negative integer
    /// @return largest integer whose square is less than or equal to the number
    auto ComputeIntegerSquareRoot(int k) -> int;
}

#endif
