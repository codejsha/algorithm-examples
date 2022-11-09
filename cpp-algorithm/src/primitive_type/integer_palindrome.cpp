#include "integer_palindrome.h"

#include <cmath>

bool IntegerPalindrome::IsPalindromeNumber(int x)
{
    if (x <= 0)
    {
        return x == 0;
    }

    const int numDigits = static_cast<int>(std::floor(log10(x))) + 1;
    int msdMask = static_cast<int>(std::pow(10, numDigits - 1));

    for (int i = 0; i < (numDigits / 2); ++i)
    {
        if (x / msdMask != x % 10)
        {
            return false;
        }

        x %= msdMask;
        x /= 10;
        msdMask /= 100;
    }
    return true;
}
