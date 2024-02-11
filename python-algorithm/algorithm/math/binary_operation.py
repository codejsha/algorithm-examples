def addition_binary_number(number1: str, number2: str) -> str:
    """
    Add two binary numbers which are represented as strings.
    :param number1: number string 1
    :param number2: number string 2
    :return: sum of the two binary numbers
    """
    result = []
    carry = 0
    number1 = number1[::-1]
    number2 = number2[::-1]
    number1_length = len(number1)
    number2_length = len(number2)

    for i in range(max(number1_length, number2_length)):
        digit1 = int(number1[i]) if i < number1_length else 0
        digit2 = int(number2[i]) if i < number2_length else 0
        digit = digit1 + digit2 + carry
        result.append(str(digit % 2))
        carry = digit // 2

    if carry:
        result.append(str(carry))

    result.reverse()

    return ''.join(result)
