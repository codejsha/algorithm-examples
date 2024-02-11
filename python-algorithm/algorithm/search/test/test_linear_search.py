import pytest

from algorithm.search.linear_search import linear_search


@pytest.mark.benchmark(group='linear_search')
@pytest.mark.parametrize(
    argnames='sequence, target, expected',
    argvalues=[
        ([1, 2, 3, 4, 5], 5, 4),
        ([1, 2, 3, 4, 5], 6, -1)
    ],
    ids=['found', 'not_found'])
def test_linear_search(benchmark, sequence, target, expected):
    has_key = benchmark(linear_search, sequence, target)
    assert expected == has_key
