#ifndef CPP_ALGORITHM_TRADE_STOCK_H
#define CPP_ALGORITHM_TRADE_STOCK_H

#include <vector>

namespace TradeStock
{
    /// @brief Buy and sell stock once. This is brute force.
    /// @param prices prices of stock
    /// @return best profit
    double BuyAndSellStockOnceBruteForce(const std::vector<int>& prices);

    /// @brief Buy and sell stock once. 
    /// @param prices prices of stock
    /// @return best profit
    double BuyAndSellStockOnce(const std::vector<int>& prices);

    /// @brief Buy and sell stock twice.
    /// @param prices prices of stock
    /// @return best profit
    double BuyAndSellStockTwice(const std::vector<double>& prices);
}

#endif
