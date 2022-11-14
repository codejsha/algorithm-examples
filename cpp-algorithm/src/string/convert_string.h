#ifndef CPP_ALGORITHM_CONVERT_STRING_H
#define CPP_ALGORITHM_CONVERT_STRING_H

#include <string>

namespace ConvertString
{
    /// @brief Convert integer to string.
    /// @param number input number
    /// @return number string
    std::string IntToString(int number);

    /// @brief Convert string to integer.
    /// @param str input string
    /// @return number
    int StringToInt(const std::string& str);

    // TODO
    std::string ConvertBase(const std::string& str, int b1, int b2);
}

#endif
