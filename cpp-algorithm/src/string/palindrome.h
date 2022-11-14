#ifndef CPP_ALGORITHM_PALINDROME_H
#define CPP_ALGORITHM_PALINDROME_H

#include <string>

namespace Palindrome
{
    /// @brief Check if a string is palindromic.
    /// Use one pointer to iterate half of the string.
    /// @param str input string
    /// @return true if the string is palindromic, false otherwise
    bool IsPalindromic1(const std::string& str);

    /// @brief Check if a string is palindromic.
    /// Use two pointers to iterate the string. One pointer starts from the beginning, the other starts from the end.
    /// @param str input string
    /// @return true if the string is palindromic, false otherwise
    bool IsPalindromic2(const std::string& str);
}

#endif
