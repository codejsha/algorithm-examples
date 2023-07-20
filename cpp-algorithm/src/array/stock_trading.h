#ifndef CPP_ALGORITHM_STOCK_TRADING_H
#define CPP_ALGORITHM_STOCK_TRADING_H

#include <vector>

namespace StockTrading
{
    /**
     * \brief Buy and sell stock once. This is brute force.
     * \param prices prices of stock
     * \return best profit
     */
    auto BuyAndSellStockOnceBruteForce(const std::vector<int>& prices) -> double;

    /**
     * \brief Buy and sell stock once.
     * \param prices prices of stock
     * \return best profit
     */
    auto BuyAndSellStockOnce(const std::vector<int>& prices) -> double;

    /**
     * \brief Buy and sell stock twice.
     * \param prices prices of stock
     * \return best profit
     */
    auto BuyAndSellStockTwice(const std::vector<double>& prices) -> double;
}

#endif
