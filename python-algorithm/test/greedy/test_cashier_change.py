from algorithm.greedy.cashier_change import cashier_change


def test_cashier_change():
    assert cashier_change(denominations=[25, 10, 5, 1], price=30) == 2
    assert cashier_change(denominations=[25, 10, 5, 1], price=24) == 6
