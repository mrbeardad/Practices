#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<typename RandomIter>
int reverse_pair(RandomIter begin, RandomIter end, RandomIter tempBegin)
{
    if ( end - begin <= 1 )
        return 0;

    auto mid = begin + (end - begin) / 2;
    int count{reverse_pair(begin, mid, tempBegin) + reverse_pair(mid, end, tempBegin)};
    auto left = begin, right = mid, tempIter = tempBegin;
    for ( ; left < mid && right < end; ) {
        if ( *left < *right ) {
            *tempIter++ = *left++;
        } else {
            count += mid - left;
            *tempIter++ = *right++;
        }
    }
    for ( ; left < mid; ++left )
        *tempIter++ = *left;
    for ( ; right < mid; ++right )
        *tempIter++ = *right;
    std::copy(tempBegin, tempIter, begin);
    return count;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,4,5}, temp(5);
    EXPECT_EQ(reverse_pair(nums.begin(), nums.end(), temp.begin()), 0);
    nums.assign({5,4,3,2,1});
    EXPECT_EQ(reverse_pair(nums.begin(), nums.end(), temp.begin()), 10);
    nums.assign({2,1,5,3,4});
    EXPECT_EQ(reverse_pair(nums.begin(), nums.end(), temp.begin()), 3);
    nums.assign({1});
    EXPECT_EQ(reverse_pair(nums.begin(), nums.end(), temp.begin()), 0);
    nums.assign({});
    EXPECT_EQ(reverse_pair(nums.begin(), nums.end(), temp.begin()), 0);
}
