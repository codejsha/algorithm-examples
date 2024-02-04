import pytest

from algorithm.search.binary_search import binary_search


@pytest.mark.benchmark(group="binary_search")
@pytest.mark.parametrize("sequence, target, expected", [
    ([1, 2, 3, 4, 5], 5, 4),
    ([1, 2, 3, 4, 5], 6, -1),
], ids=["successful1", "successful2"])
def test_binary_search(benchmark, sequence, target, expected):
    result = benchmark(binary_search, sequence, target)
    assert expected == result
