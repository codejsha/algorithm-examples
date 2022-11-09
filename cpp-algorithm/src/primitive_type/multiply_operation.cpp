#include "multiply_operation.h"

unsigned long long Add(unsigned long long a, unsigned long long b)
{
    while (b)
    {
        const unsigned long long carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

unsigned long long MultiplyOperation::Multiply(unsigned long long x, unsigned long long y)
{
    unsigned long long sum = 0;
    while (x)
    {
        if (x & 1)
        {
            sum = Add(sum, y);
        }
        x >>= 1;
        y <<= 1;
    }
    return sum;
}
