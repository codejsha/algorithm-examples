#include "compute_square_root.h"

auto ComputeSquareRoot::ComputeIntegerSquareRoot(const int k) -> int
{
    auto left = 0;
    auto right = k;

    while (left <= right)
    {
        auto mid = left + (right - left) / 2;
        auto mid_squared = mid * mid;

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
