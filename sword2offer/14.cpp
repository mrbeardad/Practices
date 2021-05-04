#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int cut_rope(unsigned int len)
{
    return len >= 4 ? std::pow(3, len / 3) * 4 / (4 - len % 3) : len - 1;
}

int cut_rope_dp(unsigned int len)
{
    // 当len <= 3时不剪的结果才最大，而题目要求至少剪一次，故特殊处理
    // 无效参数的结果未定义，由调用者承担
    if ( len <= 3 )
        return len - 1;
    std::vector<int> dp{0,1,2,3};
    dp.resize(len + 1);

    // 当len > 3时，剪了必定比不剪的结果大
    for ( size_t idx{3}; idx <= len; ++idx ) {
        for ( size_t dpIdx{1}; dpIdx < idx; ++dpIdx ) {
            dp[idx] = std::max(dp[idx], dp[dpIdx] * dp[idx - dpIdx]);
        }
    }
    return dp[len];
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(cut_rope(2), 1);
    EXPECT_EQ(cut_rope(3), 2);
    EXPECT_EQ(cut_rope(4), 4);
    EXPECT_EQ(cut_rope(5), 6);
    EXPECT_EQ(cut_rope(8), 18);
}
