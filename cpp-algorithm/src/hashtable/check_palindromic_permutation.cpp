#include "check_palindromic_permutation.h"

#include <unordered_set>

auto CheckPalindromicPermutation::IsPalindromePermutation(const std::string& str) -> bool
{
    std::unordered_set<char> char_set;
    for (const char& ch : str)
    {
        if (char_set.contains(ch))
        {
            char_set.erase(ch);
        }
        else
        {
            char_set.insert(ch);
        }
    }

    return char_set.size() <= 1;
}
