from collections import deque

import pytest

import algorithm.dp.fibonacci as fibonacci


@pytest.mark.benchmark(group='fibonacci_recursive')
@pytest.mark.parametrize(
    argnames='input_number, expected',
    argvalues=[
        (5, 5),
        (20, 6765),
        (30, 832_040)
    ],
    ids=['case1', 'case2', 'case3'])
def test_fibonacci_recursive(benchmark, input_number, expected):
    result = benchmark(fibonacci.fibonacci_recursive, input_number)
    assert expected == result


@pytest.mark.benchmark(group='fibonacci_memoization')
@pytest.mark.parametrize(
    argnames='input_number, expected',
    argvalues=[
        (5, 5),
        (20, 6765),
        (30, 832_040)
    ],
    ids=['case1', 'case2', 'case3'])
def test_fibonacci_memoization(benchmark, input_number, expected):
    result = benchmark(fibonacci.fibonacci_memoization, input_number)
    assert expected == result


@pytest.mark.benchmark(group='fibonacci_automatic_memoization')
@pytest.mark.parametrize(
    argnames='input_number, expected',
    argvalues=[
        (5, 5),
        (20, 6765),
        (30, 832_040)
    ],
    ids=['case1', 'case2', 'case3'])
def test_fibonacci_automatic_memoization(benchmark, input_number, expected):
    result = benchmark(fibonacci.fibonacci_automatic_memoization, input_number)
    assert expected == result


@pytest.mark.benchmark(group='fibonacci_iterative')
@pytest.mark.parametrize(
    argnames='input_number, expected',
    argvalues=[
        (5, 5),
        (20, 6765),
        (30, 832_040)
    ],
    ids=['case1', 'case2', 'case3'])
def test_fibonacci_iterative(benchmark, input_number, expected):
    result = benchmark(fibonacci.fibonacci_iterative, input_number)
    assert expected == result


@pytest.mark.benchmark(group='fibonacci_generator')
@pytest.mark.parametrize(
    argnames='input_number, expected',
    argvalues=[
        (5, 5),
        (20, 6765),
        (30, 832_040)
    ],
    ids=['case1', 'case2', 'case3'])
def test_fibonacci_generator(benchmark, input_number, expected):
    result = benchmark(fibonacci.fibonacci_generator, input_number)
    assert expected == deque(result, maxlen=1).pop()
