#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<std::pair<int, int> > find_subarray(const std::vector<int>& nums, int key)
{
    std::vector<std::pair<int, int> > ret{};
    int left{}, right{static_cast<int>(nums.size()) - 1};
    int curSum{};
    for ( ; left < right; ) {
        int curSum{nums[left] + nums[right]};
        if ( curSum == key ) {
            ret.emplace_back(nums[left], nums[right]);
            --right;
            ++left;
        } else if ( curSum > key ) {
            --right;
        } else {
            ++left;
        }
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,4,5,6,7};
    std::vector<std::pair<int, int> > ans{{1, 7}, {2, 6}, {3, 5}};
    EXPECT_EQ(find_subarray(nums, 8), ans);
}
