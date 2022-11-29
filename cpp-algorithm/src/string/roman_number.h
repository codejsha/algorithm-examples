#ifndef CPP_ALGORITHM_ROMAN_NUMBER_H
#define CPP_ALGORITHM_ROMAN_NUMBER_H

#include <string>

namespace RomanNumber
{
    /// @brief Verify if a string is a valid roman number.
    /// @param str roman number string
    /// @return whether the string is a valid roman number
    auto VerifyRomanString(const std::string& str) -> bool;

    /// @brief Convert a roman number to integer.
    /// @param str roman number string
    /// @return result number
    auto RomanStringToInteger(const std::string& str) -> int;

    // TODO: IntegerToShortestRomanString
    auto IntegerToShortestRomanString(int number) -> std::string;
}

#endif
