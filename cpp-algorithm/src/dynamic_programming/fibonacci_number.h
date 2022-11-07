#ifndef CPP_ALGORITHM_FIBONACCI_NUMBER_H
#define CPP_ALGORITHM_FIBONACCI_NUMBER_H

#include <vector>

namespace Fibonacci
{
    /// <summary>
    /// Calculate the Fibonacci number using a top-down approach.
    /// Use memoization to cache the results.
    /// </summary>
    /// <param name="number">number to calculate</param>
    /// <param name="memo">memoization of previously calculated numbers</param>
    /// <returns>nth Fibonacci number</returns>
    int FibonacciDynamicTopDown(int number, std::vector<int>& memo);

    /// <summary>
    /// Calculate the Fibonacci number using a bottom-up approach.
    /// Use memoization to cache the results.
    /// </summary>
    /// <param name="number">number to calculate</param>
    /// <returns>nth Fibonacci number</returns>
    int FibonacciDynamicBottomUp(int number);
}

#endif
