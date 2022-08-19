from algorithm.math.least_common_multiple import lcm


def test_lcm():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert lcm(*pair) == 72

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert lcm(*pair) == 374

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert lcm(*pair) == 3000


def is_positive_integer(a: int, b: int) -> bool:
    if (a > 0) and (b > 0):
        return True
