#ifndef CPP_ALGORITHM_INTEGER_PALINDROME_H
#define CPP_ALGORITHM_INTEGER_PALINDROME_H

#include <cmath>

namespace IntegerPalindrome
{
    /**
     * \brief Check if a number is a palindrome.
     * \param x input number
     * \return whether the number is a palindrome
     */
    bool IsPalindromeNumber(int x);
}

// ----------------------------------------------------------------------------
inline bool IntegerPalindrome::IsPalindromeNumber(int x)
{
    if (x <= 0)
    {
        return x == 0;
    }

    const int num_digits = static_cast<int>(std::floor(log10(x))) + 1;
    int msd_mask = static_cast<int>(std::pow(10, num_digits - 1));

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

#endif
