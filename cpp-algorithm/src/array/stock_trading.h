#ifndef CPP_ALGORITHM_STOCK_TRADING_H
#define CPP_ALGORITHM_STOCK_TRADING_H

#include <limits>
#include <vector>

namespace StockTrading
{
    /**
     * \brief Buy and sell stock once. This is brute force.
     * \param prices prices of stock
     * \return best profit
     */
    double BuyAndSellStockOnceBruteForce(
        const std::vector<int>& prices);

    /**
     * \brief Buy and sell stock once.
     * \param prices prices of stock
     * \return best profit
     */
    double BuyAndSellStockOnce(
        const std::vector<int>& prices);

    /**
     * \brief Buy and sell stock twice.
     * \param prices prices of stock
     * \return best profit
     */
    double BuyAndSellStockTwice(
        const std::vector<double>& prices);
}

// ----------------------------------------------------------------------------
inline double StockTrading::BuyAndSellStockOnceBruteForce(
    const std::vector<int>& prices)
{
    double max_profit = 0.0;

    for (int i = 0; i < static_cast<int>(prices.size()); ++i)
    {
        for (int j = i + 1; j < static_cast<int>(prices.size()); ++j)
        {
            if (const int profit = prices[j] - prices[i]; profit > max_profit)
            {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

// ----------------------------------------------------------------------------
inline double StockTrading::BuyAndSellStockOnce(
    const std::vector<int>& prices)
{
    double min_price_so_far = std::numeric_limits<double>::infinity();
    double max_profit = 0.0;

    for (double price : prices)
    {
        double max_profit_sell_today = price - min_price_so_far;
        max_profit = std::max(max_profit, max_profit_sell_today);
        min_price_so_far = std::min(min_price_so_far, price);
    }

    return max_profit;
}

// ----------------------------------------------------------------------------
inline double StockTrading::BuyAndSellStockTwice(
    const std::vector<double>& prices)
{
    double max_total_profit = 0;
    std::vector<double> first_buy_sell_profits(prices.size(), 0);
    double min_price_so_far = std::numeric_limits<double>::infinity();

    for (int i = 0; i < static_cast<int>(prices.size()); ++i)
    {
        min_price_so_far = std::min(min_price_so_far, prices[i]);
        max_total_profit = std::max(max_total_profit, prices[i] - min_price_so_far);
        first_buy_sell_profits[i] = max_total_profit;
    }

    double max_price_so_far = std::numeric_limits<double>::min();
    for (int i = static_cast<int>(prices.size()) - 1; i > 0; --i)
    {
        max_price_so_far = std::max(max_price_so_far, prices[i]);
        max_total_profit = std::max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profits[i]);
    }

    return max_total_profit;
}

#endif
