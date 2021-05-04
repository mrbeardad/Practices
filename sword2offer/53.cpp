#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<typename RandomIter>
std::pair<RandomIter, RandomIter>
my_equal_range(RandomIter begin, RandomIter end, const typename RandomIter::value_type& key)
{
    if ( begin == end )
        return {end, end};

    auto left = begin, right = end - 1;

    for ( ; left < right; ) {
        auto mid = left + (right - left) / 2;
        if ( *mid == key ) {
            right = mid;
            break;
        } else if ( *mid > key ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if ( *right != key )
        return {right, right};

    auto leftLower = begin, rightLower = right;
    for ( ; leftLower < rightLower; ) {
        auto mid = leftLower + (rightLower - leftLower) / 2;
        if ( *mid >= key ) {
            rightLower = mid;
        } else {
            leftLower = mid + 1;
        }
    }
    auto& lower = rightLower;

    auto leftUpper = right, rightUpper = end - 1;
    for ( ; leftUpper < rightUpper; ) {
        auto mid = leftUpper + (rightUpper - leftUpper) / 2;
        if ( *mid > key ) {
            rightUpper = mid;
        } else {
            leftUpper = mid + 1;
        }
    }
    if ( *rightUpper <= key )
        ++rightUpper;
    auto& upper = rightUpper;


    return {lower, upper};
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,2,3,3,3,4,4,4,4};
    auto er = my_equal_range(nums.begin(), nums.end(), 0);
    EXPECT_EQ(er.second - er.first, 0);
    er = my_equal_range(nums.begin(), nums.end(), 1);
    EXPECT_EQ(er.second - er.first, 1);
    er = my_equal_range(nums.begin(), nums.end(), 2);
    EXPECT_EQ(er.second - er.first, 2);
    er = my_equal_range(nums.begin(), nums.end(), 3);
    EXPECT_EQ(er.second - er.first, 3);
    er = my_equal_range(nums.begin(), nums.end(), 4);
    EXPECT_EQ(er.second - er.first, 4);
    er = my_equal_range(nums.begin(), nums.end(), 5);
    EXPECT_EQ(er.second - er.first, 0);

    nums.assign({1});
    er = my_equal_range(nums.begin(), nums.end(), 1);
    EXPECT_EQ(er.second - er.first, 1);
    er = my_equal_range(nums.begin(), nums.end(), 2);
    EXPECT_EQ(er.second - er.first, 0);

    nums.clear();
    er = my_equal_range(nums.begin(), nums.end(), 2);
    EXPECT_EQ(er.second - er.first, 0);
}
