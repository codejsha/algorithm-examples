import pytest
from algorithm.search.generic_search import generic_linear_contains, generic_binary_contains


@pytest.mark.benchmark(group='linear_contains')
@pytest.mark.parametrize(
    argnames='elements, target, expected',
    argvalues=[
        ([1, 5, 15, 15, 15, 15, 20], 5, True)
    ],
    ids=['found'])
def test_generic_linear_contains(benchmark, elements, target, expected):
    result = benchmark(generic_linear_contains, elements, target)
    assert expected == result


@pytest.mark.benchmark(group='binary_contains')
@pytest.mark.parametrize(
    argnames='elements, target, expected',
    argvalues=[
        (['a', 'd', 'e', 'f', 'z'], 'f', True),
        (['john', 'mark', 'ronald', 'sarah'], 'sheila', False)
    ],
    ids=['found', 'not_found'])
def test_generic_binary_contains(benchmark, elements, target, expected):
    result = benchmark(generic_binary_contains, elements, target)
    assert expected == result
