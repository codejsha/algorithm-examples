from algorithm.math.greatest_common_divisor import gcd_euclidean


def lcm(a: int, b: int) -> int:
    """
    Find the least common multiple of two numbers.
    LCM(a,b) = a * b / GCD(a,b)
    """

    return a * b // gcd_euclidean(a, b)
