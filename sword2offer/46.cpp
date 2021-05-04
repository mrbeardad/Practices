#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int translate_count(const std::string& nums)
{
    if ( nums.size() <= 1 )
        return nums.size();

    std::vector<int> dp(nums.size());
    dp[0] = 1;
    dp[1] = std::stol(nums.substr(0, 2)) < 26 ? 2 : 1;
    for ( size_t idx{2}; idx < dp.size(); ++idx ) {
        dp[idx] = dp[idx - 1];
        int nearTwoNum{std::stoi(nums.substr(idx - 1, 2))};
        if ( nearTwoNum < 26 && nearTwoNum > 9 ) {
            dp[idx] += dp[idx - 2];
        }
    }
    return dp.back();
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(translate_count("12258"), 5);
    EXPECT_EQ(translate_count("1"), 1);
    EXPECT_EQ(translate_count("25"), 2);
    EXPECT_EQ(translate_count("26"), 1);
    EXPECT_EQ(translate_count("206"), 2);
}
