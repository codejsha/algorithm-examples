#ifndef CPP_ALGORITHM_ARITHMETIC_OPERATION_H
#define CPP_ALGORITHM_ARITHMETIC_OPERATION_H

namespace ArithmeticOperation
{
    /**
     * \brief Calculate the product of two numbers without using arithmetic operators.
     * \param x multiplier
     * \param y multiplicand
     * \return product result
     */
    unsigned long long Multiply(
        unsigned long long x,
        unsigned long long y);

    /**
     * \brief Calculate the fraction of two numbers without using arithmetic operators.
     * \param x dividend
     * \param y divisor
     * \return fraction result
     */
    int Divide(int x, int y);
}

// ----------------------------------------------------------------------------
inline unsigned long long Add(
    unsigned long long a,
    unsigned long long b)
{
    while (b)
    {
        const unsigned long long carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// ----------------------------------------------------------------------------
inline unsigned long long ArithmeticOperation::Multiply(
    unsigned long long x,
    unsigned long long y)
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

// ----------------------------------------------------------------------------
inline int ArithmeticOperation::Divide(int x, int y)
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

#endif
