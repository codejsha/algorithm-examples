import pytest

from algorithm.math.binary_operation import addition_binary_number


@pytest.mark.benchmark(group="addition_of_binary_number")
@pytest.mark.parametrize("a, b, expected", [
    ('1110', '1011', '11001'),
], ids=["successful"])
def test_addition_of_binary_number(benchmark, a, b, expected):
    result = benchmark(addition_binary_number, a, b)
    assert result == expected
