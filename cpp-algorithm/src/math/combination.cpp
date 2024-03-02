#include "combination.h"

void GenerateCombinationHelper(const std::vector<int>& seq, const int k, std::vector<std::vector<int>>& result, std::vector<int>& current, const int start)
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

auto Combination::GenerateCombination(const std::vector<int>& seq, const int k) -> std::vector<std::vector<int>>
{
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    GenerateCombinationHelper(seq, k, result, combination, 0);
    return result;
}

void GenerateCombinationHelper(const std::vector<std::string>& seq, const int k, std::vector<std::vector<std::string>>& result, std::vector<std::string>& current, const int start)
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

auto Combination::GenerateCombination(const std::vector<std::string>& seq, const int k) -> std::vector<std::vector<std::string>>
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> combination;
    GenerateCombinationHelper(seq, k, result, combination, 0);
    return result;
}

void GenerateCombinationHelper(const std::string& str, const int k, std::vector<std::string>& result, const std::string& current, const int start)
{
    if (k == 0)
    {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= static_cast<int>(str.length()) - k; ++i)
    {
        auto new_current = current + str[i];
        GenerateCombinationHelper(str, k - 1, result, new_current, i + 1);
    }
}

auto Combination::GenerateCombination(const std::string& str, const int k) -> std::vector<std::string>
{
    std::vector<std::string> result;
    const std::string combination;
    GenerateCombinationHelper(str, k, result, combination, 0);
    return result;
}
