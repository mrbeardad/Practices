#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<std::pair<int, int> > find_subarray(int from1ToN)
{
    std::vector<std::pair<int, int> > ret{};
    if ( from1ToN <= 1 )
        return ret;
    int maxNum{(from1ToN + 1) / 2};
    int left{1}, right{1}, curSum{1};
    for ( ; ; ) {
        if ( curSum == from1ToN ) {
            ret.emplace_back(left, right);
            curSum -= left++;
            if ( right < maxNum )
                curSum += ++right;
        } else if ( curSum > from1ToN ) {
            curSum -= left++;
        } else if ( right < maxNum ) {
            curSum += ++right;
        } else {
            break;
        }
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<std::pair<int, int> > ans{{1,2}};
    EXPECT_EQ(find_subarray(3), ans);
    ans.assign({{2,3}});
    EXPECT_EQ(find_subarray(5), ans);
    ans.assign({{1,5},{4,6},{7,8}});
    EXPECT_EQ(find_subarray(15), ans);
}
