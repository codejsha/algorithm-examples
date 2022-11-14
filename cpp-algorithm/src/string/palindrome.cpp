#include "palindrome.h"

bool Palindrome::IsPalindromic1(const std::string& str)
{
    for (auto i = 0; i < static_cast<int>(str.length()) / 2; ++i)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool Palindrome::IsPalindromic2(const std::string& str)
{
    for (auto i = 0, j = static_cast<int>(str.length()) - 1; i < j; ++i, --j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}
