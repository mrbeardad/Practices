#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int find_index_eq_element(const std::vector<int>& nums)
{
    if ( nums.empty() )
        throw std::logic_error{"no element that equal to it's index."};
    int left{}, right{static_cast<int>(nums.size()) - 1};
    for ( ; left < right; ) {
        int mid{(left + right) / 2};
        if ( nums[mid] == mid ) {
            right = mid;
            break;
        } else if ( nums[mid] > mid ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if ( nums[right] != right )
        throw std::logic_error{"no element that equal to it's index."};
    return right;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{0,1,2,3,4,5};
    EXPECT_EQ(find_index_eq_element(nums), 2);
    nums.assign({-3,-1,1,3,5});
    EXPECT_EQ(find_index_eq_element(nums), 3);
    nums.assign({0,2,3,5});
    EXPECT_EQ(find_index_eq_element(nums), 0);
    nums.assign({-1,0,1,3});
    EXPECT_EQ(find_index_eq_element(nums), 3);
    nums.assign({0});
    EXPECT_EQ(find_index_eq_element(nums), 0);

    nums.assign({1});
    EXPECT_ANY_THROW(find_index_eq_element(nums));
    nums.assign({-1,0,1,2,3});
    EXPECT_ANY_THROW(find_index_eq_element(nums));
    nums.assign({1,2,3,4,5});
    EXPECT_ANY_THROW(find_index_eq_element(nums));
    nums.assign({});
    EXPECT_ANY_THROW(find_index_eq_element(nums));
}
