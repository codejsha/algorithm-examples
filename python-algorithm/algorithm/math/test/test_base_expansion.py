import pytest

from algorithm.math.base_expansion import base_expansion


@pytest.mark.benchmark(group='base_expansion')
@pytest.mark.parametrize(
    argnames='number, base, expected',
    argvalues=[
        (12345, 8, '30071'),
        (177130, 16, '2B3EA'),
        (241, 2, '11110001')
    ],
    ids=['base8', 'base16', 'base2'])
def test_base_expansion(benchmark, number, base, expected):
    result = benchmark(base_expansion, number, base)
    assert expected == result
