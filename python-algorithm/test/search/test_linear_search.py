from algorithm.search.linear_search import linear_search


def test_linear_search():
    assert linear_search([1, 2, 3, 4, 5], 5) == 4
    assert linear_search([1, 2, 3, 4, 5], 6) == -1
