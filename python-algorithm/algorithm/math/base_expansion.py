def base_expansion(number: int, base: int) -> str:
    """
    Convert a number to a different base. This is base b expansion of a number.
    :param number: number to convert
    :param base: base to convert to
    :return: number in the new base
    """
    result = []
    expansion_table = {0: '0', 1: '1', 2: '2', 3: '3', 4: '4',
                       5: '5', 6: '6', 7: '7', 8: '8', 9: '9',
                       10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E',
                       15: 'F'}

    while number > 0:
        remainder = number % base
        result.append(expansion_table[remainder])
        number //= base

    result.reverse()

    return ''.join(result)
