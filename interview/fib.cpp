#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Solution {
    std::vector<int> dp_;
public:
    Solution() : dp_{0, 1} {  }
    int fib(int n) {
        for ( size_t idx{dp_.size()}; idx <= n; ++idx ) {
            dp_.emplace_back((dp_[idx - 2] + dp_[idx - 1]) % int(1e9+7));
        }
        return dp_[n];
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.fib(3), 2);
    EXPECT_EQ(Solution{}.fib(5), 5);
    EXPECT_EQ(Solution{}.fib(45), 134903163);
}
