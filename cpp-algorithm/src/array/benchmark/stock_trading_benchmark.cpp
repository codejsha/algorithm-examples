#include "stock_trading.h"

#include <benchmark/benchmark.h>

static void BM_BuyAndSellStockOnceBruteForce(benchmark::State& state)
{
    const auto prices = std::vector<int>{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    for (auto _ : state)
    {
        StockTrading::BuyAndSellStockOnceBruteForce(prices);
    }
}

BENCHMARK(BM_BuyAndSellStockOnceBruteForce);

static void BM_BuyAndSellStockOnce(benchmark::State& state)
{
    const auto prices = std::vector<int>{310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    for (auto _ : state)
    {
        StockTrading::BuyAndSellStockOnce(prices);
    }
}

BENCHMARK(BM_BuyAndSellStockOnce);

static void BM_BuyAndSellStockTwice(benchmark::State& state)
{
    const auto prices = std::vector<double>{12.0, 11.0, 13.0, 9.0, 12.0, 8.0, 14.0, 13.0, 15.0};
    for (auto _ : state)
    {
        StockTrading::BuyAndSellStockTwice(prices);
    }
}

BENCHMARK(BM_BuyAndSellStockTwice);

BENCHMARK_MAIN();
