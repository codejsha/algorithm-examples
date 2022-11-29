#include "reverse_digit.h"

auto ReverseDigit::Reverse(int x) -> long long
{
    long long result = 0;
    while (x)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}
