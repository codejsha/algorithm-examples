#include "fibonacci_number.h"

auto Fibonacci::FibonacciDynamicTopDown(const int number, std::vector<int>& memo) -> int
{
    if (number <= 0) { return 0; }
    if (number == 1) { return 1; }
    if (memo[number] > 0) { return memo[number]; }

    memo[number] = FibonacciDynamicTopDown(number - 1, memo) + FibonacciDynamicTopDown(number - 2, memo);
    
    return memo[number];
}

auto Fibonacci::FibonacciDynamicBottomUp(const int number) -> int
{
    if (number <= 0) { return 0; }
    if (number == 1) { return 1; }

    std::vector<int> memo(number + 1, -1);
    memo[0] = 0;
    memo[1] = 1;

    for (auto i = 2; i < number; ++i)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[number - 1] + memo[number - 2];
}
