#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<typename RandomItr>
RandomItr get_min(RandomItr begin, RandomItr end)
{
    if ( begin == end )
        return end;

    auto left = begin;
    auto right = std::prev(end);
    for ( ; left < right; ) {
        auto mid = left + (right - left) / 2;
        if ( *mid == *left && *mid == *right ) {
            ++left;
        } else if ( *mid <= *right ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> rotate{};
    rotate.assign({});
    EXPECT_EQ(get_min(rotate.begin(), rotate.end()), rotate.end());
    rotate.assign({1});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), 1);
    rotate.assign({1,2});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), 1);
    rotate.assign({1,2,3,4,5});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), 1);
    rotate.assign({1,2,3,4,5,-1,0});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), -1);
    rotate.assign({1,2,3,4,5,-1,0,1,1});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), -1);
    rotate.assign({1,1,1,1,-1,1,1});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), -1);
    rotate.assign({1,1,-1,1,1,1,1});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), -1);
    rotate.assign({1,1,1,1,1,1,1});
    EXPECT_EQ(*get_min(rotate.begin(), rotate.end()), 1);
}
