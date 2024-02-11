def cashier_change(denominations: list[int], price: int) -> int:
    """
    Find the minimum number of coins needed to make change for a given amount of money.
    :param denominations: list of coin denominations
    :param price: amount of money
    :return: minimum number of coins
    """
    change = price
    coins = 0

    for i in range(len(denominations)):
        while change >= denominations[i]:
            coins += 1
            change -= denominations[i]

    return coins
