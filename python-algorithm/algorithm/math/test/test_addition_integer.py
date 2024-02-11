import pytest

from algorithm.math.binary_operation import addition_binary_number


@pytest.mark.benchmark(group='addition_of_binary_number')
@pytest.mark.parametrize(
    argnames='a, b, expected_binary',
    argvalues=[('1110', '1011', '11001')],
    ids=['case1'])
def test_addition_of_binary_number(benchmark, a, b, expected_binary):
    binary_string = benchmark(addition_binary_number, a, b)
    assert expected_binary == binary_string
