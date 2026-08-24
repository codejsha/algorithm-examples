#ifndef CPP_ALGORITHM_ROMAN_NUMBER_H
#define CPP_ALGORITHM_ROMAN_NUMBER_H

#include <string>
#include <unordered_map>

namespace RomanNumber
{
    /**
     * \brief Verify if a string is a valid roman number.
     * \param str roman number string
     * \return whether the string is a valid roman number
     */
    bool VerifyRomanString(const std::string& str);

    /**
     * \brief Convert a roman number to integer.
     * \param str roman number string
     * \return result number
     */
    int RomanStringToInteger(const std::string& str);

    // TODO: Implement IntegerToShortestRomanString
    std::string IntegerToShortestRomanString(int number);
}

// ----------------------------------------------------------------------------
inline auto roman_set =
    std::unordered_map<char, int>{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

// ----------------------------------------------------------------------------
inline bool RomanNumber::VerifyRomanString(const std::string& str)
{
    bool is_except = false;

    for (int i = 0; i < static_cast<int>(str.size() - 1); ++i)
    {
        if (roman_set[str[i]] < roman_set[str[i + 1]])
        {
            if (is_except)
            {
                return false;
            }
            is_except = true;
        }
    }

    return true;
}

// ----------------------------------------------------------------------------
inline int RomanNumber::RomanStringToInteger(const std::string& str)
{
    int sum = 0;
    for (int i = static_cast<int>(str.size() - 1); i >= 0; --i)
    {
        const int value = roman_set[str[i]];
        if (i > 0 && roman_set[str[i - 1]] < value)
        {
            sum += value - roman_set[str[i - 1]];
            --i;
        }
        else
        {
            sum += value;
        }
    }
    return sum;
}

#endif
