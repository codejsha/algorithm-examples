#ifndef CPP_ALGORITHM_FIBONACCI_NUMBER_H
#define CPP_ALGORITHM_FIBONACCI_NUMBER_H

#include <vector>

namespace Fibonacci
{
    /// @brief Calculate the Fibonacci number using a top-down approach.
    /// @param number number to calculate
    /// @param memo memoization of previously calculated numbers
    /// @return nth Fibonacci number
    int FibonacciDynamicTopDown(int number, std::vector<int>& memo);

    /// @brief Calculate the Fibonacci number using a bottom-up approach.
    /// Use memoization to cache the results.
    /// @param number number to calculate
    /// @return nth Fibonacci number
    int FibonacciDynamicBottomUp(int number);
}

#endif
