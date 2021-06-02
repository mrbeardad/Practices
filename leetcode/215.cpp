#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, size_t kth) {
        if ( kth < 1 || kth > nums.size() ) {
            throw logic_error{"out-of-range kth"};
        }
        kth = nums.size() + 1 - kth;
        return findKthLargest(nums, 0, nums.size(), kth);
    }
    int findKthLargest(vector<int>& nums, size_t begin, size_t end, size_t kth) {
        if ( end - begin <= 1 ) {
            return nums[begin];
        }

        size_t last{end - 1};
        size_t mid{(begin + last) / 2};
        if ( nums[begin] < nums[last] )
            swap(nums[begin], nums[last]);
        if ( nums[mid] < nums[last] )
            swap(nums[mid], nums[last]);
        if ( nums[mid] < nums[begin] )
            swap(nums[mid], nums[begin]);
        swap(nums[begin], nums[last]);
        int& pivot{nums[last]};

        ssize_t left{static_cast<ssize_t>(begin)}, right{static_cast<ssize_t>(last)};
        for ( ; ; ) {
            for ( ; nums[++left] < pivot; );
            for ( ; nums[--right] > pivot; );
            if ( left >= right )
                break;
            swap(nums[left], nums[right]);
        }
        swap(nums[left], pivot);
        if ( left == kth - 1 )
            return nums[left];
        else if ( left < kth - 1 )
            return findKthLargest(nums, left + 1, end, kth);
        else
            return findKthLargest(nums, begin, left, kth);
    }
};

TEST(TestSuit, TestCase)
{
    vector<int> nums{3,2,1,5,6,4};
    EXPECT_ANY_THROW(Solution{}.findKthLargest(nums, 0));
    EXPECT_EQ(Solution{}.findKthLargest(nums, 1), 6);
    EXPECT_EQ(Solution{}.findKthLargest(nums, 2), 5);
    EXPECT_EQ(Solution{}.findKthLargest(nums, 3), 4);
    EXPECT_EQ(Solution{}.findKthLargest(nums, 4), 3);
    EXPECT_EQ(Solution{}.findKthLargest(nums, 5), 2);
    EXPECT_EQ(Solution{}.findKthLargest(nums, 6), 1);
    EXPECT_ANY_THROW(Solution{}.findKthLargest(nums, 7));
}
