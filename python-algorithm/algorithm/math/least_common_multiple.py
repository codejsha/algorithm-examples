from algorithm.math.greatest_common_divisor import gcd_euclidean


def lcm_with_gcd(a: int, b: int) -> int:
    """
    Find the least common multiple of two numbers.
    LCM(a, b) = a * b / GCD(a, b)
    :param a: number1
    :param b: number2
    :return: the least common multiple
    """
    return a * b // gcd_euclidean(a, b)
