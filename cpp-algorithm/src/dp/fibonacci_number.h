#ifndef CPP_ALGORITHM_FIBONACCI_NUMBER_H
#define CPP_ALGORITHM_FIBONACCI_NUMBER_H

#include <vector>

namespace Fibonacci
{
    /**
     * \brief Calculate the Fibonacci number using a top-down approach.
     * \note This is a recursive approach.
     * \param number number to calculate
     * \param memo memoization of previously calculated numbers
     * \return nth Fibonacci number
     */
    int FibonacciDynamicTopDown(
        int number,
        std::vector<int>& memo);

    /**
     * \brief Calculate the Fibonacci number using a bottom-up approach.
     * Use memoization to cache the results.
     * \param number number to calculate
     * \return nth Fibonacci number
     */
    int FibonacciDynamicBottomUp(int number);
}

// ----------------------------------------------------------------------------
inline int Fibonacci::FibonacciDynamicTopDown(
    const int number,
    std::vector<int>& memo)
{
    if (number == 0)
    {
        return 0;
    }
    if (number == 1)
    {
        return 1;
    }
    if (memo[number] > 0)
    {
        return memo[number];
    }

    memo[number] = FibonacciDynamicTopDown(number - 1, memo) + FibonacciDynamicTopDown(number - 2, memo);

    return memo[number];
}

// ----------------------------------------------------------------------------
inline int Fibonacci::FibonacciDynamicBottomUp(const int number)
{
    if (number == 0)
    {
        return 0;
    }
    if (number == 1)
    {
        return 1;
    }

    std::vector<int> memo(number + 1, -1);
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i < number; ++i)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[number - 1] + memo[number - 2];
}

#endif
