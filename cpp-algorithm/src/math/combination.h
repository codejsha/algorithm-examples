#ifndef CPP_ALGORITHM_COMBINATION_H
#define CPP_ALGORITHM_COMBINATION_H

#include <string>
#include <vector>

namespace Combination
{
    /**
     * \brief Generate all possible combinations of integer elements in a sequence.
     * \param seq sequence of integer elements
     * \param k size of the subset
     * \return combinations of integer elements
     */
    std::vector<std::vector<int>> GenerateCombination(
        const std::vector<int>& seq,
        int k);

    /**
     * \brief Generate all possible combinations of string elements in a sequence.
     * \param seq sequence of string elements
     * \param k size of the subset
     * \return combinations of string elements
     */
    std::vector<std::vector<std::string>> GenerateCombination(
        const std::vector<std::string>& seq,
        int k);

    /**
     * \brief Generate all possible combinations of chars in a string.
     * \param str given string
     * \param k size of the subset
     * \return combinations of chars in a string
     */
    std::vector<std::string> GenerateCombination(
        const std::string& str,
        int k);
}

// ----------------------------------------------------------------------------
inline void GenerateCombinationHelper(
    const std::vector<int>& seq,
    const int k, std::vector<std::vector<int>>& result,
    std::vector<int>& current,
    const int start)
{
    if (static_cast<int>(current.size()) == k)
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i < static_cast<int>(seq.size()); ++i)
    {
        current.push_back(seq[i]);
        GenerateCombinationHelper(seq, k, result, current, i + 1);
        current.pop_back();
    }
}

// ----------------------------------------------------------------------------
inline std::vector<std::vector<int>> Combination::GenerateCombination(
    const std::vector<int>& seq,
    const int k)
{
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    GenerateCombinationHelper(seq, k, result, combination, 0);
    return result;
}

// ----------------------------------------------------------------------------
inline void GenerateCombinationHelper(
    const std::vector<std::string>& seq,
    const int k,
    std::vector<std::vector<std::string>>& result,
    std::vector<std::string>& current,
    const int start)
{
    if (static_cast<int>(current.size()) == k)
    {
        result.push_back(current);
        return;
    }
    for (int i = start; i < static_cast<int>(seq.size()); ++i)
    {
        current.push_back(seq[i]);
        GenerateCombinationHelper(seq, k, result, current, i + 1);
        current.pop_back();
    }
}

// ----------------------------------------------------------------------------
inline std::vector<std::vector<std::string>> Combination::GenerateCombination(
    const std::vector<std::string>& seq,
    const int k)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> combination;
    GenerateCombinationHelper(seq, k, result, combination, 0);
    return result;
}

// ----------------------------------------------------------------------------
inline void GenerateCombinationHelper(
    const std::string& str,
    const int k, std::vector<std::string>& result,
    const std::string& current,
    const int start)
{
    if (k == 0)
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= static_cast<int>(str.length()) - k; ++i)
    {
        std::string new_current = current + str[i];
        GenerateCombinationHelper(str, k - 1, result, new_current, i + 1);
    }
}

// ----------------------------------------------------------------------------
inline std::vector<std::string> Combination::GenerateCombination(
    const std::string& str,
    const int k)
{
    std::vector<std::string> result;
    const std::string combination;
    GenerateCombinationHelper(str, k, result, combination, 0);
    return result;
}

#endif
