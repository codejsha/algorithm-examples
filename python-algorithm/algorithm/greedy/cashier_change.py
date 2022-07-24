def cashier_change(denominations: list[int], price: int) -> int:
    change = price
    coins = 0

    for i in range(len(denominations)):
        while change >= denominations[i]:
            coins += 1
            change -= denominations[i]

    return coins
