#include "compute_square_root.h"

auto ComputeSquareRoot::ComputeIntegerSquareRoot(const int k) -> int
{
    int left = 0;
    int right = k;

    while (left <= right)
    {
        const int mid = left + (right - left) / 2;
        const int mid_squared = mid * mid;

        if (mid_squared <= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left - 1;
}
