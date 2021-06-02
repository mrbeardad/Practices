#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.size() < 2 )
            return 0;
        // {idx, hei}
        vector<pair<int, int> > stack{{0, height[0]}};
        int ans{};
        for ( size_t idx{1}; idx < height.size(); ++idx ) {
            auto rightToTop = stack.back();
            for ( ; stack.size() && stack.back().second < height[idx]; ) {
                ans += (stack.back().second - rightToTop.second)
                    * (idx - stack.back().first - 1);
                rightToTop = stack.back();
                stack.pop_back();
            }
            // rightToTop可能为stack.back()没被弹走
            if ( stack.size() )
                ans += (height[idx] - rightToTop.second)
                    * (idx - stack.back().first - 1);
            stack.emplace_back(idx, height[idx]);
        }
        return ans;
    }
};

TEST(TestSuit, TestCase)
{
    vector<int> nums{5,5,1,7,1,1,5,2,7,6};
    EXPECT_EQ(Solution{}.trap(nums), 23);
}
