def gcd_euclidean(a: int, b: int) -> int:
    """
    Find the greatest common divisor of two numbers using the Euclidean algorithm.
    :param a: dividend
    :param b: divisor
    :return: the greatest common divisor
    """
    while b != 0:
        a, b = b, a % b
    return a


def gcd_euclidean_divmod(a: int, b: int) -> int:
    """
    Find the greatest common divisor of two numbers using the Euclidean algorithm.
    If the numbers are large, use divmod to calculate them.
    :param a: dividend
    :param b: divisor
    :return: the greatest common divisor
    """
    while b != 0:
        a, b = b, divmod(a, b)[1]
    return a


def gcd_extended_euclidean(a: int, b: int) -> tuple:
    """
    Find the greatest common divisor of two numbers using the extended Euclidean algorithm.
    :param a: dividend
    :param b: divisor
    :return: the greatest common divisor, x, y (where ax + by = gcd(a, b))
    """
    if b == 0:
        return a, 1, 0
    else:
        d, x, y = gcd_extended_euclidean(b, a % b)
        return d, y, x - (a // b) * y
