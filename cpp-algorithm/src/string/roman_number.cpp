#include "roman_number.h"

#include <unordered_map>

auto roman_set =
    std::unordered_map<char, int>{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

auto RomanNumber::VerifyRomanString(const std::string& str) -> bool
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

auto RomanNumber::RomanStringToInteger(const std::string& str) -> int
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
