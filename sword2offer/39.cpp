#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int find_overhalf(const std::vector<int>& nums)
{
    if ( nums.empty() )
        throw std::logic_error{"Fuck you man! Don't give me a empty array."};

    int overhalfNum{}, NumCnt{};
    for ( size_t idx{}; idx < nums.size(); ++idx ) {
        if ( NumCnt == 0 ) {
            overhalfNum = nums[idx];
            ++NumCnt;
        } else if ( nums[idx] != overhalfNum ) {
            --NumCnt;
        } else {
            ++NumCnt;
        }
    }

    if ( NumCnt > 0 && std::count(nums.begin(), nums.end(), overhalfNum) >= nums.size() / 2 + 1 )
        return overhalfNum;

    throw std::logic_error{"Fuck you man! Don't give me a array that don't have overhalf number."};
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,4,4,4,4};
    EXPECT_EQ(find_overhalf(nums), 4);
    nums.assign({4,4,4,4,1,2,3});
    EXPECT_EQ(find_overhalf(nums), 4);
    nums.assign({1,4,2,4,2,4,3,4,5,4,4});
    EXPECT_EQ(find_overhalf(nums), 4);
    nums.assign({1,2,4,2,4,3,4,5,4,4});
    EXPECT_ANY_THROW(find_overhalf(nums));
    nums.clear();
    EXPECT_ANY_THROW(find_overhalf(nums));
}
