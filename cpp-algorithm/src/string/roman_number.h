#ifndef CPP_ALGORITHM_ROMAN_NUMBER_H
#define CPP_ALGORITHM_ROMAN_NUMBER_H

#include <string>

namespace RomanNumber
{
    /// @brief Verify if a string is a valid roman number.
    /// @param str roman number string
    /// @return whether the string is a valid roman number
    bool VerifyRomanString(const std::string& str);
    
    /// @brief Convert a roman number to integer.
    /// @param str roman number string
    /// @return result number
    int RomanStringToInteger(const std::string& str);

    // TODO
    std::string IntegerToShortestRomanString(int number);
}

#endif
