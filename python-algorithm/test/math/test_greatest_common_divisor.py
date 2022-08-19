from algorithm.math.greatest_common_divisor import gcd_euclidean, gcd_euclidean_divmod, gcd_extended_euclidean


def test_gcd_euclidean():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert gcd_euclidean(*pair) == 12

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert gcd_euclidean(*pair) == 1

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert gcd_euclidean(*pair) == 20


def test_gcd_euclidean_divmod():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert gcd_euclidean_divmod(*pair) == 12

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert gcd_euclidean_divmod(*pair) == 1

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert gcd_euclidean_divmod(*pair) == 20


def test_gcd_extended_euclidean():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert gcd_extended_euclidean(*pair) == (12, -1, 1)

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert gcd_extended_euclidean(*pair) == (1, -9, 7)

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert gcd_extended_euclidean(*pair) == (20, -4, 1)


def is_positive_integer(a: int, b: int) -> bool:
    if (a > 0) and (b > 0):
        return True
