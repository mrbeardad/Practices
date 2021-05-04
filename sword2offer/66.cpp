#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<int> products(const std::vector<int>& nums)
{
    if ( nums.size() <= 1 )
        return {};

    std::vector<int> latterProducts(nums.size(), 1);
    for ( size_t idx{nums.size() - 2}; idx < latterProducts.size(); --idx ) {
        latterProducts[idx] = latterProducts[idx + 1] * nums[idx + 1];
    }

    std::vector<int> ret(nums.size());
    int formerProduct{1};
    for ( size_t idx{}; idx < nums.size(); ++idx ) {
        ret[idx] = formerProduct * latterProducts[idx];
        formerProduct *= nums[idx];
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,4,5}, ans{120,60,40,30,24};
    EXPECT_EQ(products(nums), ans);
}
