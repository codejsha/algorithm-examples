#ifndef CPP_ALGORITHM_POWER_OPERATION_H
#define CPP_ALGORITHM_POWER_OPERATION_H

namespace PowerOperation
{
    /**
     * \brief Compute repeated squaring x^y.
     * \param x double x
     * \param y integer y
     * \return result
     */
    double Power(double x, int y);
}

// ----------------------------------------------------------------------------
inline double PowerOperation::Power(double x, const int y)
{
    double result = 1.0;
    long long power = y;

    if (y < 0)
    {
        power = -power;
        x = 1.0 / x;
    }

    while (power)
    {
        if (power & 1)
        {
            result *= x;
        }
        x *= x;
        power >>= 1;
    }
    return result;
}

#endif
