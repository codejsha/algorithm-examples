from algorithm.math.number import greatest_common_divisor, greatest_common_divisor_divmod, least_common_multiple


def test_greatest_multiple_divisor():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert greatest_common_divisor(*pair) == 12

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert greatest_common_divisor(*pair) == 1

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert greatest_common_divisor(*pair) == 20


def test_greatest_multiple_divisor_divmod():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert greatest_common_divisor_divmod(*pair) == 12

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert greatest_common_divisor_divmod(*pair) == 1

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert greatest_common_divisor_divmod(*pair) == 20


def test_least_common_multiple():
    pair = (24, 36)
    assert is_positive_integer(*pair) is True
    assert least_common_multiple(*pair) == 72

    pair = (17, 22)
    assert is_positive_integer(*pair) is True
    assert least_common_multiple(*pair) == 374

    pair = (120, 500)
    assert is_positive_integer(*pair) is True
    assert least_common_multiple(*pair) == 3000


def is_positive_integer(a: int, b: int) -> bool:
    if (a > 0) and (b > 0):
        return True
