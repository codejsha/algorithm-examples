#include "collatz_conjecture.h"

auto CollatzConjecture::GenerateCollatzSequence(const long long number,
                                                std::unordered_map<long long, std::vector<long long>>& hash_table)
    -> std::vector<long long>
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
        auto sub_sequence = GenerateCollatzSequence(number / 2, hash_table);
        sequence.insert(sequence.end(), sub_sequence.begin(), sub_sequence.end());
    }
    // if number is odd, then multiply it by 3 and add 1
    else
    {
        auto sub_sequence = GenerateCollatzSequence(number * 3 + 1, hash_table);
        sequence.insert(sequence.end(), sub_sequence.begin(), sub_sequence.end());
    }

    hash_table[number] = sequence;
    return sequence;
}

auto CollatzConjecture::FindNumbersSatisfyingCollatzConjecture(const long long number) -> std::vector<long long>
{
    std::vector<long long> satisfied_numbers;
    std::unordered_map<long long, std::vector<long long>> hash_table;
    for (auto i = 1LL; i < number; ++i)
    {
        // if the Collatz sequence ends with 1, then satisfies the Collatz conjecture
        if (auto sequence = GenerateCollatzSequence(i, hash_table); sequence.back() == 1)
        {
            satisfied_numbers.push_back(i);
        }
    }
    return satisfied_numbers;
}
