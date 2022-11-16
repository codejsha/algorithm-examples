#include "trade_stock.h"

#include <gtest/gtest.h>

GTEST_TEST(TradeStockTest, BuyAndSellStockOnceBruteForce)
{
    const auto prices = std::vector<int>{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    constexpr auto expected = 30;
    const auto result = TradeStock::BuyAndSellStockOnceBruteForce(prices);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(TradeStockTest, BuyAndSellStockOnce)
{
    const auto prices = std::vector<int>{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    constexpr auto expected = 30;
    const auto result = TradeStock::BuyAndSellStockOnce(prices);
    EXPECT_EQ(expected, result);
}

GTEST_TEST(TradeStockTest, BuyAndSellStockTwice)
{
    const auto prices = std::vector<double>{12.0, 11.0, 13.0, 9.0, 12.0, 8.0, 14.0, 13.0, 15.0};
    constexpr auto expected = 10.0;
    const auto result = TradeStock::BuyAndSellStockTwice(prices);
    EXPECT_EQ(expected, result);
}
