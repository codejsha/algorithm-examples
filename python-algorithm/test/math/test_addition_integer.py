from algorithm.math.binary_operation import addition_binary_number, multiplication_binary_number


def test_addition_of_binary_number():
    assert addition_binary_number('1110', '1011') == '11001'
