#ifndef CPP_ALGORITHM_FIBONACCI_NUMBER_H
#define CPP_ALGORITHM_FIBONACCI_NUMBER_H

#include <vector>

namespace fibonacci
{
    /// <summary>
    /// Calculates the nth Fibonacci number using memoization.
    /// </summary>
    /// <param name="number">number to calculate</param>
    /// <param name="memoization">memoization of previously calculated numbers</param>
    /// <returns>nth Fibonacci number</returns>
    int FibonacciMemoization(int number, std::vector<int>& memoization);
} // namespace fibonacci

#endif
