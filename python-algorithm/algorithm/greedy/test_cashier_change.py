import pytest

from algorithm.greedy.cashier_change import cashier_change


@pytest.mark.benchmark(group="cashier_change")
@pytest.mark.parametrize("denominations, price, expected", [
    ([25, 10, 5, 1], 30, 2),
    ([25, 10, 5, 1], 24, 6),
], ids=["successful1", "successful2"])
def test_cashier_change(benchmark, denominations, price, expected):
    result = benchmark(cashier_change, denominations, price)
    assert result == expected
