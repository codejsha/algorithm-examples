import pytest

from algorithm.search.binary_search import binary_search


@pytest.mark.benchmark(group='binary_search')
@pytest.mark.parametrize(
    argnames='sequence, target, expected',
    argvalues=[
        ([1, 2, 3, 4, 5], 5, 4),
        ([1, 2, 3, 4, 5], 6, -1)
    ],
    ids=['case1', 'case2'])
def test_binary_search(benchmark, sequence, target, expected):
    result = benchmark(binary_search, sequence, target)
    assert expected == result
