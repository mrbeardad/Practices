#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

/*************************************************************************************************/
// 数组长度n，数字范围[0,n-1]，求是否存在重复数字
/*************************************************************************************************/
bool duplicate(std::vector<int>& nums)
{
    for ( size_t idx{}; idx < nums.size(); ) {
        if ( nums[idx] == idx ) {
            ++idx;
        } else if ( nums[nums[idx]] != nums[idx] ) {
            std::swap(nums[nums[idx]], nums[idx]);
        } else {
            return true;
        }
    }
    return false;
}


TEST(TestSuit, TestCase)
{
    std::vector<int> nums{};
    nums.assign({0,1,2,2,3});
    EXPECT_EQ(duplicate(nums), true);
    nums.assign({0,1,2,2,3,4,3});
    EXPECT_EQ(duplicate(nums), true);
    nums.assign({1,0,2,3});
    EXPECT_EQ(duplicate(nums), false);
    nums.assign({});
    EXPECT_EQ(duplicate(nums), false);
}
