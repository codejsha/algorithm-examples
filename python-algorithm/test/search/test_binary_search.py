from algorithm.search.binary_search import binary_search


def test_binary_search():
    assert binary_search([1, 2, 3, 4, 5], 5) == 4
    assert binary_search([1, 2, 3, 4, 5], 6) == -1
