#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

/*************************************************************************************************/
// 数组长度n，数字范围[1,n-1]，求任一重复数字值
/*************************************************************************************************/
int duplicate(const std::vector<int>& nums)
{
    if ( nums.size() <= 1 )
        return 0;
    int left{1}, right{static_cast<int>(nums.size()) - 1};
    for ( ; left < right; ) {
        int mid{(left + right) / 2};
        int cntLow = std::count_if(nums.begin(), nums.end(),
                [left, mid] (int elem) {return left <= elem && elem <= mid;});
        if ( cntLow > mid - left + 1 )
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}


TEST(TestSuit, TestCase)
{
    std::vector<int> nums{};
    nums.assign({1,2,3,3,5});
    EXPECT_EQ(duplicate(nums), 3);
    nums.assign({1,2,3,3,5,5});
    EXPECT_EQ(duplicate(nums), 3);
    nums.assign({1,1,2,3,3,5,5,5,5,5});
    EXPECT_EQ(duplicate(nums), 1);
    nums.assign({});
    EXPECT_EQ(duplicate(nums), 0);
    nums.assign({0});
    EXPECT_EQ(duplicate(nums), 0);
}
