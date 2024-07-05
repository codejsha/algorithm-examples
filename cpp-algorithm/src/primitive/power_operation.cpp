#include "power_operation.h"

auto PowerOperation::Power(double x, const int y) -> double
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
