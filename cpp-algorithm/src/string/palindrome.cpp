#include "palindrome.h"

auto Palindrome::IsPalindromic1(const std::string& str) -> bool
{
    for (int i = 0; i < static_cast<int>(str.length()) / 2; ++i)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

auto Palindrome::IsPalindromic2(const std::string& str) -> bool
{
    for (int i = 0, j = static_cast<int>(str.length()) - 1; i < j; ++i, --j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}
