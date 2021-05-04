#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

size_t count1(const std::string& maxNum)
{
    size_t count{}, times{1};
    for ( size_t idx{maxNum.size() - 1}; idx < maxNum.size(); --idx ) {
        if ( maxNum[idx] == '0' ) {
            size_t thisCnt{static_cast<size_t>(std::atoi(maxNum.substr(0, idx).data()))};
            count += thisCnt * times;
        } else if ( maxNum[idx] == '1' ) {
            size_t thisCnt{static_cast<size_t>(std::atoi(maxNum.substr(0, idx).data()))};
            count += thisCnt * times + std::atoi(maxNum.substr(idx + 1).data()) + 1;
        } else {
            count += (std::atoi(maxNum.substr(0, idx).data()) + 1) * times;
        }
        times *= 10;
    }
    return count;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(count1("0"), 0);
    EXPECT_EQ(count1("1"), 1);
    EXPECT_EQ(count1("2"), 1);
    EXPECT_EQ(count1("102"), 11+10+3);
}
