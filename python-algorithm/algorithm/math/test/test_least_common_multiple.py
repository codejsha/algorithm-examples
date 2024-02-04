import pytest

from algorithm.math.least_common_multiple import lcm


@pytest.mark.benchmark(group="lcm")
@pytest.mark.parametrize(
    argnames="pair, expected",
    argvalues=[
        ((24, 36), 72),
        ((17, 22), 374),
        ((120, 500), 3000)
    ])
def test_lcm(benchmark, pair, expected):
    assert is_positive_integer(*pair) is True
    result = benchmark(lcm, *pair)
    assert expected == result


def is_positive_integer(a: int, b: int) -> bool:
    if (a > 0) and (b > 0):
        return True
