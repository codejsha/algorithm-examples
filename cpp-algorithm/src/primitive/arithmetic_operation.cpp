#include "arithmetic_operation.h"

auto Add(unsigned long long a, unsigned long long b) -> unsigned long long
{
    while (b)
    {
        const unsigned long long carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

auto ArithmeticOperation::Multiply(unsigned long long x, unsigned long long y) -> unsigned long long
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

auto ArithmeticOperation::Divide(int x, int y) -> int
{
    int result = 0;
    int power = 32;
    unsigned long long y_power = static_cast<unsigned long long>(y) << power;

    while (x >= y)
    {
        while (y_power > x)
        {
            y_power >>= 1;
            --power;
        }
        result += 1 << power;
        x -= y_power;
    }
    return result;
}
