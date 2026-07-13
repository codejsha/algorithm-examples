#ifndef CPP_ALGORITHM_CHECK_PALINDROMIC_PERMUTATION_H
#define CPP_ALGORITHM_CHECK_PALINDROMIC_PERMUTATION_H

#include <string>
#include <unordered_set>

namespace CheckPalindromicPermutation
{
    /**
     * \brief Check if a string is a permutation of a palindrome.
     * \details A permutation of a palindrome is a rearrangement of its letters that results in a palindrome.
     * After processing the string, the character set should have at most one character.
     * This is because a palindrome can have at most one character that appears an odd number of times.
     * And all other characters must appear an even number of times.
     * \param str a string
     * \return true if the string is a permutation of a palindrome, false otherwise
     */
    bool IsPalindromePermutation(const std::string& str);
}

// ----------------------------------------------------------------------------
inline bool CheckPalindromicPermutation::IsPalindromePermutation(const std::string& str)
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

#endif
