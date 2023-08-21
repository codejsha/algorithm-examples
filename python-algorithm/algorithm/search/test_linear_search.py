import pytest

from algorithm.search.linear_search import linear_search


@pytest.mark.benchmark(group="linear_search")
@pytest.mark.parametrize("sequence, target, expected", [
    ([1, 2, 3, 4, 5], 5, 4),
    ([1, 2, 3, 4, 5], 6, -1),
], ids=["successful1", "successful2"])
def test_linear_search(benchmark, sequence, target, expected):
    result = benchmark(linear_search, sequence, target)
    assert expected == result
