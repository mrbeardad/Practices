#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "gtest/gtest.h"

using namespace std;

int search(vector<int>& nums, int target) {
    ssize_t left{}, right{static_cast<ssize_t>(nums.size()) - 1};
    for ( ; left <= right; ) {
        ssize_t mid{(left + right) / 2};
        if ( nums[mid] == target ) {
            return mid;
        } else if ( nums[mid] > target ) {
            if ( nums[mid] >= nums.front() && target < nums.front() ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if ( nums[mid] < nums.front() && target >= nums.front() ) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

TEST(TestSuit, TestCase)
{
    vector<int> nums{2,3,4,0,1};
    EXPECT_EQ(search(nums, 2), 0);
    EXPECT_EQ(search(nums, 3), 1);
    EXPECT_EQ(search(nums, 4), 2);
    EXPECT_EQ(search(nums, 0), 3);
    EXPECT_EQ(search(nums, 1), 4);

    nums.assign({2,3,0,1});
    EXPECT_EQ(search(nums, 2), 0);
    EXPECT_EQ(search(nums, 3), 1);
    EXPECT_EQ(search(nums, 0), 2);
    EXPECT_EQ(search(nums, 1), 3);

    nums.assign({3,4,0,1,2});
    EXPECT_EQ(search(nums, 3), 0);
    EXPECT_EQ(search(nums, 4), 1);
    EXPECT_EQ(search(nums, 0), 2);
    EXPECT_EQ(search(nums, 1), 3);
    EXPECT_EQ(search(nums, 2), 4);

    nums.assign({0,1,2});
    EXPECT_EQ(search(nums, 0), 0);
    EXPECT_EQ(search(nums, 1), 1);
    EXPECT_EQ(search(nums, 2), 2);

    nums.assign({0,1});
    EXPECT_EQ(search(nums, 0), 0);
    EXPECT_EQ(search(nums, 1), 1);

    nums.assign({1,0});
    EXPECT_EQ(search(nums, 1), 0);
    EXPECT_EQ(search(nums, 0), 1);

    nums.assign({1});
    EXPECT_EQ(search(nums, 1), 0);

    nums.assign({});
    EXPECT_EQ(search(nums, 1), -1);
}
