#ifndef CPP_ALGORITHM_COLLATZ_CONJECTURE_H
#define CPP_ALGORITHM_COLLATZ_CONJECTURE_H

#include <unordered_map>
#include <vector>

namespace CollatzConjecture
{
    /// @brief Generate the Collatz sequence of a number.
    /// @param number a positive integer
    /// @param hash_table a hash table to store the Collatz sequence of a number
    /// @return the Collatz sequence of a number
    auto GenerateCollatzSequence(long long number, std::unordered_map<long long, std::vector<long long>>& hash_table) -> std::vector<long long>;

    /// @brief Find the numbers satisfying the Collatz conjecture.
    /// @param number a positive integer
    /// @return a vector of numbers satisfying the Collatz conjecture
    auto FindNumbersSatisfyingCollatzConjecture(long long number) -> std::vector<long long>;
}

#endif
