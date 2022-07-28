def greatest_common_divisor(a: int, b: int) -> int:
    """
    Find the greatest common divisor of two numbers.
    """

    while b != 0:
        a, b = b, a % b
    return a


def greatest_common_divisor_divmod(a: int, b: int) -> int:
    """
    Find the greatest common divisor of two numbers.
    If the numbers are large, use divmod to calculate them.
    """

    while b != 0:
        a, b = b, divmod(a, b)[1]
    return a


def least_common_multiple(a: int, b: int) -> int:
    """
    Find the least common multiple of two numbers.
    LCM(a,b) = a * b / GCD(a,b)
    """

    return a * b // greatest_common_divisor(a, b)
