#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int get_max_subarray_sum(const std::vector<int>& nums)
{
    if ( nums.empty() )
        throw std::logic_error{"Don't give me empty array!"};
    std::vector<int> dp(nums.size());
    dp[0] = nums[0];
    for ( size_t idx{1}; idx < nums.size(); ++idx ) {
        dp[idx] = dp[idx - 1] < 0 ? nums[idx] : dp[idx - 1] + nums[idx];
    }
    return *std::max_element(dp.begin(), dp.end());
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(get_max_subarray_sum(nums), 45);
    nums.assign({-1,-2,-3,-4,-5,-6,-7,-8,-9});
    EXPECT_EQ(get_max_subarray_sum(nums), -1);
    nums.assign({1,2,-3,4,5,-6,-7,8,-9});
    EXPECT_EQ(get_max_subarray_sum(nums), 9);
}
