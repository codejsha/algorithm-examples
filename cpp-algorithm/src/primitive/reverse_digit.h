#ifndef CPP_ALGORITHM_REVERSE_DIGIT_H
#define CPP_ALGORITHM_REVERSE_DIGIT_H

namespace ReverseDigit
{
    /**
     * \brief Reverse the digits of a given integer.
     * if the input is x = 123, the output should be 321.
     * \param x input number
     * \return result number
     */
    long long Reverse(int x);
}

// ----------------------------------------------------------------------------
inline long long ReverseDigit::Reverse(int x)
{
    long long result = 0;
    while (x)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

#endif
