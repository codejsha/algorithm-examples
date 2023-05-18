import pytest

from algorithm.math.greatest_common_divisor import gcd_euclidean, gcd_euclidean_divmod, gcd_extended_euclidean


@pytest.mark.benchmark(group="gcd_euclidean")
@pytest.mark.parametrize("pair, expected", [
    ((24, 36), 12),
    ((17, 22), 1),
    ((120, 500), 20),
])
def test_gcd_euclidean(benchmark, pair, expected):
    assert is_positive_integer(*pair) is True
    result = benchmark(gcd_euclidean, *pair)
    assert result == expected


@pytest.mark.benchmark(group="gcd_euclidean_divmod")
@pytest.mark.parametrize("pair, expected", [
    ((24, 36), 12),
    ((17, 22), 1),
    ((120, 500), 20),
])
def test_gcd_euclidean_divmod(benchmark, pair, expected):
    assert is_positive_integer(*pair) is True
    result = benchmark(gcd_euclidean_divmod, *pair)
    assert result == expected


@pytest.mark.benchmark(group="gcd_extended_euclidean")
@pytest.mark.parametrize("pair, expected", [
    ((24, 36), (12, -1, 1)),
    ((17, 22), (1, -9, 7)),
    ((120, 500), (20, -4, 1)),
])
def test_gcd_extended_euclidean(benchmark, pair, expected):
    assert is_positive_integer(*pair) is True
    result = benchmark(gcd_extended_euclidean, *pair)
    assert result == expected


def is_positive_integer(a: int, b: int) -> bool:
    if (a > 0) and (b > 0):
        return True
