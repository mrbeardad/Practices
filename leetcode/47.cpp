#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

#include "gtest/gtest.h"

template<typename Iter>
bool my_next_permutation(Iter begin, Iter end)
{
    auto alt = prev(end);
    for ( ; --alt >= begin && *alt >= *next(alt); );
    if ( alt < begin )
        return false;
    auto left = next(alt), right = prev(end);
    for ( ; left <= right; ) {
        auto mid = left + (right - left) / 2;
        if ( *mid > *alt ) {
            if ( next(mid) >= end || *next(mid) <= *alt ) {
                left = mid;
                break;
            } else {
                left = mid + 1;
            }
        } else {
            right = mid - 1;
        }
    }
    std::swap(*alt, *left);
    reverse(next(alt), end);
    return true;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,3,4,5}, nums2{1,2,3,3,4,5};
    for ( ; std::next_permutation(nums.begin(), nums.end()); ) {
        my_next_permutation(nums2.begin(), nums2.end());
        EXPECT_EQ(nums, nums2);
    }
    EXPECT_FALSE(my_next_permutation(nums2.begin(), nums2.end()));
}
