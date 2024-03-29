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
    auto FibonacciDynamicTopDown(int number, std::vector<int>& memo) -> int;

    /**
     * \brief Calculate the Fibonacci number using a bottom-up approach.
     * Use memoization to cache the results.
     * \param number number to calculate
     * \return nth Fibonacci number
     */
    auto FibonacciDynamicBottomUp(int number) -> int;
}

#endif
