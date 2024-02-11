import pytest

from algorithm.greedy.cashier_change import cashier_change


@pytest.mark.benchmark(group='cashier_change')
@pytest.mark.parametrize(
    argnames='denominations, price, expected_count',
    argvalues=[
        ([25, 10, 5, 1], 30, 2),
        ([25, 10, 5, 1], 24, 6)
    ],
    ids=['case1', 'case2'])
def test_cashier_change(benchmark, denominations, price, expected_count):
    coin_count = benchmark(cashier_change, denominations, price)
    assert expected_count == coin_count
