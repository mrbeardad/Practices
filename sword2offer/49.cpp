#include <algorithm>
#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::deque<int> ugly_number(int maxNum)
{
    std::deque<int> ugly{1};
    int idx2{}, idx3{}, idx5{};
    for ( ; ugly.back() < maxNum; ) {
        std::pair<int, int&> p1{ugly[idx2] * 2, idx2}, p2{ugly[idx3] * 3, idx3}, p3{ugly[idx5] * 5, idx5};
        auto& next = std::min(std::min(p1, p2), p3);
        if ( ugly.back() != next.first )
            ugly.emplace_back(next.first);
        ++next.second;
    }
    ugly.pop_front();
    if ( ugly.size() && ugly.back() > maxNum )
        ugly.pop_back();
    return ugly;
}

TEST(TestSuit, TestCase)
{
    std::deque<int> ugly{};
    EXPECT_EQ(ugly_number(1), ugly);
    ugly.assign({2});
    EXPECT_EQ(ugly_number(2), ugly);
    ugly.assign({2,3});
    EXPECT_EQ(ugly_number(3), ugly);
    ugly.assign({2,3,4,5});
    EXPECT_EQ(ugly_number(5), ugly);
    ugly.assign({2,3,4,5,6,8,9,10});
    EXPECT_EQ(ugly_number(10), ugly);
}
