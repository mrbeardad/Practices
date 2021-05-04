#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <optional>

std::optional<int> find_once_number(const std::vector<int>& nums)
{
    std::optional<int> ret{};
    if ( nums.empty() )
        return ret;
    std::vector<int> bitCount(32);
    for ( int thisNum : nums ) {
        size_t bit{};
        for ( unsigned flag{0x1}; flag; flag <<= 1 ) {
            bitCount[bit] += static_cast<bool>(thisNum & flag);
        }
    }
    int retNum{};
    unsigned flag{0x1};
    for ( int count : bitCount ) {
        if ( count % 3 == 1 ) {
            retNum |= flag;
        } else if ( count % 3 == 2 ) {
            return ret;
        }
        flag <<= 1;
    }
    ret.emplace(retNum);
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,2,2,3,3,3,4,4,4};
    EXPECT_EQ(find_once_number(nums).value(), 1);
    nums.emplace_back(1);
    EXPECT_ANY_THROW(find_once_number(nums).value());
    nums.clear();
    EXPECT_ANY_THROW(find_once_number(nums).value());
}
