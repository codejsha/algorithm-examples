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
    std::vector<long long> GenerateCollatzSequence(
        long long number,
        std::unordered_map<long long, std::vector<long long>>& hash_table);

    /**
     * \brief Find the numbers satisfying the Collatz conjecture.
     * \param number a positive integer
     * \return a vector of numbers satisfying the Collatz conjecture
     */
    std::vector<long long> FindNumbersSatisfyingCollatzConjecture(
        long long number);
}

// ----------------------------------------------------------------------------
inline std::vector<long long> CollatzConjecture::GenerateCollatzSequence(
    const long long number,
    std::unordered_map<long long, std::vector<long long>>& hash_table)
{
    if (number <= 0)
    {
        return {};
    }
    if (number == 1)
    {
        return {1};
    }
    if (hash_table.contains(number))
    {
        return hash_table[number];
    }

    std::vector<long long> sequence = {number};
    // if number is even, then divide it by 2
    if (number % 2 == 0)
    {
        std::vector<long long> sub_sequence = GenerateCollatzSequence(number / 2, hash_table);
        sequence.insert(sequence.end(), sub_sequence.begin(), sub_sequence.end());
    }
    // if number is odd, then multiply it by 3 and add 1
    else
    {
        std::vector<long long> sub_sequence = GenerateCollatzSequence(number * 3 + 1, hash_table);
        sequence.insert(sequence.end(), sub_sequence.begin(), sub_sequence.end());
    }

    hash_table[number] = sequence;
    return sequence;
}

// ----------------------------------------------------------------------------
inline std::vector<long long> CollatzConjecture::FindNumbersSatisfyingCollatzConjecture(
    const long long number)
{
    std::vector<long long> satisfied_numbers;
    std::unordered_map<long long, std::vector<long long>> hash_table;
    for (long long i = 1LL; i < number; ++i)
    {
        // if the Collatz sequence ends with 1, then satisfies the Collatz conjecture
        if (std::vector<long long> sequence = GenerateCollatzSequence(i, hash_table); sequence.back() == 1)
        {
            satisfied_numbers.push_back(i);
        }
    }
    return satisfied_numbers;
}

#endif
