#include "trade_stock.h"

#include <benchmark/benchmark.h>

static void BmBuyAndSellStockOnceBruteForce(benchmark::State& state)
{
    const auto prices = std::vector<int>{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    for (auto _ : state)
    {
        TradeStock::BuyAndSellStockOnceBruteForce(prices);
    }
}
BENCHMARK(BmBuyAndSellStockOnceBruteForce);

static void BmBuyAndSellStockOnce(benchmark::State& state)
{
    const auto prices = std::vector<int>{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    for (auto _ : state)
    {
        TradeStock::BuyAndSellStockOnce(prices);
    }
}
BENCHMARK(BmBuyAndSellStockOnce);

static void BmBuyAndSellStockTwice(benchmark::State& state)
{
    const auto prices = std::vector<double>{12.0, 11.0, 13.0, 9.0, 12.0, 8.0, 14.0, 13.0, 15.0};
    for (auto _ : state)
    {
        TradeStock::BuyAndSellStockTwice(prices);
    }
}
BENCHMARK(BmBuyAndSellStockTwice);

BENCHMARK_MAIN();
