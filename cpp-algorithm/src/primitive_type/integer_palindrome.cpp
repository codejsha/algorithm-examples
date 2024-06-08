#include "integer_palindrome.h"

#include <cmath>

auto IntegerPalindrome::IsPalindromeNumber(int x) -> bool
{
    if (x <= 0)
    {
        return x == 0;
    }

    const auto num_digits = static_cast<int>(std::floor(log10(x))) + 1;
    auto msd_mask = static_cast<int>(std::pow(10, num_digits - 1));

    for (int i = 0; i < (num_digits / 2); ++i)
    {
        if (x / msd_mask != x % 10)
        {
            return false;
        }

        x %= msd_mask;
        x /= 10;
        msd_mask /= 100;
    }
    return true;
}
