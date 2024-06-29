from functools import lru_cache
from typing import Dict
from typing import Generator


def fibonacci_recursive(n: int) -> int:
    """
    Calculate the Fibonacci number of the given number.
    :param n: input number
    :return: Fibonacci number
    """
    if n < 2:  # base case
        return n
    return fibonacci_recursive(n - 2) + fibonacci_recursive(n - 1)  # recursive case


def fibonacci_memoization(n: int) -> int:
    """
    Calculate the Fibonacci number of the given number using memoization.
    :param n: input number
    :return: Fibonacci number
    """
    memo: Dict[int, int] = {0: 0, 1: 1}  # our base cases

    def helper(m: int) -> int:
        if m not in memo:
            memo[m] = helper(m - 1) + helper(m - 2)  # memoization
        return memo[m]

    return helper(n)


@lru_cache(maxsize=None)
def fibonacci_automatic_memoization(n: int) -> int:
    """
    Calculate the Fibonacci number of the given number using automatic memoization.
    It uses the @lru_cache decorator to cache the results of the function.
    It has same definition as :func:`fibonacci_recursive`.
    :param n: input number
    :return: Fibonacci number
    """
    if n < 2:  # base case
        return n
    return fibonacci_recursive(n - 2) + fibonacci_recursive(n - 1)  # recursive case


def fibonacci_iterative(n: int) -> int:
    """
    Calculate the Fibonacci number of the given number using iterative approach.
    :param n: input number
    :return: Fibonacci number
    """
    if n == 0:
        return n  # special case
    _last: int = 0  # initially set to fib(0)
    _next: int = 1  # initially set to fib(1)
    for _ in range(1, n):
        _last, _next = _next, _last + _next
    return _next


def fibonacci_generator(n: int) -> Generator[int, None, None]:
    """
    Calculate the Fibonacci number of the given number using generator approach.
    :param n: input number
    :return: generator of Fibonacci numbers
    """
    yield 0  # special case
    if n > 0:
        yield 1  # special case
    _last: int = 0  # initially set to fibonacci(0)
    _next: int = 1  # initially set to fibonacci(1)
    for _ in range(1, n):
        _last, _next = _next, _last + _next
        yield _next  # main generation step
