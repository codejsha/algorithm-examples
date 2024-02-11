import pytest

from algorithm.search.binary_search import binary_search


@pytest.mark.benchmark(group='binary_search')
@pytest.mark.parametrize(
    argnames='sequence, target, expected_index',
    argvalues=[
        ([1, 2, 3, 4, 5], 5, 4),
        ([1, 2, 3, 4, 5], 6, -1)
    ],
    ids=['found', 'not_found'])
def test_binary_search(benchmark, sequence, target, expected_index):
    index = benchmark(binary_search, sequence, target)
    assert expected_index == index
