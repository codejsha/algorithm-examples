#include "reverse_digit.h"

long long ReverseDigit::Reverse(int x)
{
    long long result = 0;
    while (x)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}
