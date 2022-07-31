#include "fibonacci_number.h"

int fibonacci::FibonacciMemoization(const int number, std::vector<int>& memoization)
{
    if (number <= 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else if (memoization[number] > 0)
    {
        return memoization[number];
    }
    else
    {
        memoization[number] = FibonacciMemoization(number - 1, memoization) + FibonacciMemoization(number - 2, memoization);
        return memoization[number];
    }
}
