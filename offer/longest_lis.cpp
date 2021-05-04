#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums) {
        std::vector<int> dp(nums.size());
        for ( size_t idx{}; idx < nums.size(); ++idx ) {
            int longest{};
            for ( ssize_t dpIdx = idx - 1; dpIdx >= 0; --dpIdx ) {
                if ( nums[dpIdx] >= nums[idx] )
                    continue;
                longest = std::max(dp[dpIdx], longest);
            }
            dp[idx] = longest + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}), 4);
}
