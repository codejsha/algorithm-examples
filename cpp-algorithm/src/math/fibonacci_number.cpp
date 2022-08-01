#include "fibonacci_number.h"

int fibonacci::FibonacciDynamicTopDown(const int number, std::vector<int>& memoization)
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
        memoization[number] = FibonacciDynamicTopDown(number - 1, memoization)
                              + FibonacciDynamicTopDown(number - 2, memoization);
        return memoization[number];
    }
}

int fibonacci::FibonacciDynamicBottomUp(int number)
{
    if (number <= 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else
    {
        std::vector<int> memoization(number + 1, -1);
        memoization[0] = 0;
        memoization[1] = 1;

        for (auto i = 2; i < number; i++)
        {
            memoization[i] = memoization[i - 1] + memoization[i - 2];
        }

        return memoization[number - 1] + memoization[number - 2];
    }
}
