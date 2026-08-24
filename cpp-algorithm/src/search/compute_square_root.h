#ifndef CPP_ALGORITHM_COMPUTE_SQUARE_ROOT_H
#define CPP_ALGORITHM_COMPUTE_SQUARE_ROOT_H

namespace ComputeSquareRoot
{
    /**
     * \brief Compute the integer square root of a number.
     * \details When given a non-negative integer,
     * return the largest integer whose square is less than or equal to the number.
     * \param k non-negative integer
     * \return largest integer whose square is less than or equal to the number
     */
    int ComputeIntegerSquareRoot(int k);
}

// ----------------------------------------------------------------------------
inline int ComputeSquareRoot::ComputeIntegerSquareRoot(const int k)
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

#endif
