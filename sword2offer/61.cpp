#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool is_continuous(std::vector<int>& cards)
{
    std::sort(cards.begin(), cards.end());
    int zeroCount{};
    size_t idx{};
    for ( ; idx < cards.size() && cards[idx] == 0; ++idx )
        ++zeroCount;
    if ( idx == cards.size() )
        return false;
    for ( ; idx + 1 < cards.size(); ) {
        if ( cards[idx] + 1 == cards[idx + 1] )
            ++idx;
        else if ( zeroCount )
            ++cards[idx], --zeroCount;
        else
            return false;
    }
    return true;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> cards{1,2,3,4,5};
    EXPECT_TRUE(is_continuous(cards));
    cards.assign({0,1,2,3,4,5});
    EXPECT_TRUE(is_continuous(cards));
    cards.assign({0,0,1,2,3,4,5});
    EXPECT_TRUE(is_continuous(cards));

    cards.assign({1,2,5,6});
    EXPECT_FALSE(is_continuous(cards));
    cards.assign({0,1,2,5,6});
    EXPECT_FALSE(is_continuous(cards));
    cards.assign({0,0,1,2,5,6});
    EXPECT_TRUE(is_continuous(cards));
    cards.assign({0,0,0,1,2,5,6});
    EXPECT_TRUE(is_continuous(cards));

    cards.assign({1,2,3,5,7});
    EXPECT_FALSE(is_continuous(cards));
    cards.assign({0,1,2,3,5,7});
    EXPECT_FALSE(is_continuous(cards));
    cards.assign({0,0,1,2,3,5,7});
    EXPECT_TRUE(is_continuous(cards));
    cards.assign({0,0,0,1,2,3,5,7});
    EXPECT_TRUE(is_continuous(cards));

    cards.assign({0});
    EXPECT_FALSE(is_continuous(cards));
    cards.assign({});
    EXPECT_FALSE(is_continuous(cards));
    cards.assign({1});
    EXPECT_TRUE(is_continuous(cards));
}
