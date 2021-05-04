#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int find_missing_number(const std::vector<int>& nums)
{
    if ( nums.empty() )
        return 0;
    int left{0}, right{static_cast<int>(nums.size()) - 1};
    for ( ; left < right; ) {
        int mid{(left + right) / 2};
        if ( nums[mid] > mid ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if ( nums[right] == right )
        ++right;
    return right;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{0,1,2,3,4,5,6};
    EXPECT_EQ(find_missing_number(nums), 7);
    nums.assign({1,2,3,4,5,6,7});
    EXPECT_EQ(find_missing_number(nums), 0);
    nums.assign({0,1,3,4,5});
    EXPECT_EQ(find_missing_number(nums), 2);
    nums.assign({});
    EXPECT_EQ(find_missing_number(nums), 0);
}
