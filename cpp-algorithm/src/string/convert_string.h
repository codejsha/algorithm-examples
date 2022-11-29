#ifndef CPP_ALGORITHM_CONVERT_STRING_H
#define CPP_ALGORITHM_CONVERT_STRING_H

#include <string>

namespace ConvertString
{
    /// @brief Convert integer to string.
    /// @param number input number
    /// @return number string
    auto IntToString(int number) -> std::string;

    /// @brief Convert string to integer.
    /// @param str input string
    /// @return number
    auto StringToInt(const std::string& str) -> int;

    // TODO: ConvertBase
    auto ConvertBase(const std::string& str, int b1, int b2) -> std::string;
}

#endif
