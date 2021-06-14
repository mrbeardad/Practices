#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Solution {
    std::vector<int> dp_;
    int              mins_[4];
public:
    Solution() : dp_{0, 1, 2, 3, 4}, mins_{0, 0, 1, 2} {  }
    int cuttingRope_v1(int n)
    {
        if ( n <= 3 )
            return mins_[n];
        for ( size_t idx{dp_.size()}; idx <= n; ++idx ) {
            int max{};
            for ( size_t cut1st{1}; cut1st <= idx / 2; ++cut1st ) {
                max = std::max(max, dp_[cut1st] * dp_[idx - cut1st]);
            }
            dp_.emplace_back(max);
        }
        return dp_[n];
    }

    int cuttingRope(int n)
    {
        return n <= 3 ? n - 1 : std::pow(3, n / 3) * 4 / (4 - n % 3);
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.cuttingRope(2), 1);
    EXPECT_EQ(Solution{}.cuttingRope(10), 36);
}
