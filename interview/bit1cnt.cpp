#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans{};
        for ( ; n > 0; n >>= 1 )
            ans = n & 0x1 ? ans + 1 : ans;
        return ans;
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.hammingWeight(7), 3);
    EXPECT_EQ(Solution{}.hammingWeight(6), 2);
    EXPECT_EQ(Solution{}.hammingWeight(8), 1);
}
