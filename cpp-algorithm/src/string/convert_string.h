#ifndef CPP_ALGORITHM_CONVERT_STRING_H
#define CPP_ALGORITHM_CONVERT_STRING_H

#include <string>

namespace ConvertString
{
    /**
     * \brief Convert integer to string.
     * \param number input number
     * \return number string
     */
    std::string IntToString(int number);

    /**
     * \brief Convert string to integer.
     * \param str input string
     * \return number
     */
    int StringToInt(const std::string& str);

    // TODO: Implement ConvertBase
    std::string ConvertBase(const std::string& str, int b1, int b2);
}

// ----------------------------------------------------------------------------
inline std::string ConvertString::IntToString(int number)
{
    std::string str;
    bool is_negative = false;
    if (number < 0)
    {
        is_negative = true;
        number = -number;
    }

    do
    {
        str.push_back('0' + number % 10);
        number /= 10;
    } while (number > 0);

    if (is_negative)
    {
        str.push_back('-');
    }

    std::reverse(str.begin(), str.end());
    return str;
}

// ----------------------------------------------------------------------------
inline int ConvertString::StringToInt(const std::string& str)
{
    int number = 0;
    for (char i : str)
    {
        number = (number * 10) + (i - '0');
    }
    return number;
}

#endif
