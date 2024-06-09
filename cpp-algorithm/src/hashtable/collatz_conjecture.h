#ifndef CPP_ALGORITHM_COLLATZ_CONJECTURE_H
#define CPP_ALGORITHM_COLLATZ_CONJECTURE_H

#include <unordered_map>
#include <vector>

namespace CollatzConjecture
{
    /**
     * \brief Generate the Collatz sequence of a number.
     * \details The Collatz conjecture is defined as follows:
     * Take any natural number n. If n is even, divide it by 2 to get n / 2.
     * If n is odd, multiply it by 3 and add 1 to obtain 3n + 1.
     * \param number a positive integer
     * \param hash_table a hash table to store the Collatz sequence of a number
     * \return the Collatz sequence of a number
     */
    auto GenerateCollatzSequence(long long number, std::unordered_map<long long, std::vector<long long>>& hash_table)
        -> std::vector<long long>;

    /**
     * \brief Find the numbers satisfying the Collatz conjecture.
     * \param number a positive integer
     * \return a vector of numbers satisfying the Collatz conjecture
     */
    auto FindNumbersSatisfyingCollatzConjecture(long long number) -> std::vector<long long>;
}

#endif
