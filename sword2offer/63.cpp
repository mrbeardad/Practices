#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int max_profit(const std::vector<int>& stocks)
{
    if ( stocks.size() < 2 )
        throw std::logic_error{"stocks.size() is too small."};
    int curMin{stocks[0]}, maxProfit{std::numeric_limits<int>::min()};
    for ( size_t curIdx{1}; curIdx < stocks.size(); ++curIdx ) {
        maxProfit = std::max(maxProfit, stocks[curIdx] - curMin);
        curMin = std::min(curMin, stocks[curIdx]);
    }
    return maxProfit;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> stocks{1,2,3,4,5,6,7};
    EXPECT_EQ(max_profit(stocks), 6);
    stocks.assign({7,6,5,4,3,2,1});
    EXPECT_EQ(max_profit(stocks), -1);
    stocks.assign({1,1,1,1});
    EXPECT_EQ(max_profit(stocks), 0);
    stocks.assign({3,2,4,2,7,1,8});
    EXPECT_EQ(max_profit(stocks), 7);
    stocks.assign({1,2});
    EXPECT_EQ(max_profit(stocks), 1);
    stocks.assign({1});
    EXPECT_ANY_THROW(max_profit(stocks));
    stocks.assign({});
    EXPECT_ANY_THROW(max_profit(stocks));
}
