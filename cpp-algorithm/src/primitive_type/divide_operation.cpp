#include "divide_operation.h"

int DivideOperation::Divide(int x, int y)
{
    int result = 0;
    int power = 32;
    unsigned long long yPower = static_cast<unsigned long long>(y) << power;

    while (x >= y)
    {
        while (yPower > x)
        {
            yPower >>= 1;
            --power;
        }
        result += 1 << power;
        x -= yPower;
    }
    return result;
}
