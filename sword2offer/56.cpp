#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <optional>

std::optional<std::pair<int, int> > two_number_appear_once(std::vector<int>& nums)
{
    std::optional<std::pair<int, int> > ret{};
    if ( nums.size() < 2 )
        return ret;
    int xorNum{std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>{})};
    if ( xorNum == 0 )
        return ret;

    unsigned flag{0x1};
    for ( ; (xorNum & flag) == 0; flag <<= 1 );

    auto mid = std::partition(nums.begin(), nums.end(), [flag] (int elem) {
        return elem & flag;
    });
    ret.emplace(std::accumulate(nums.begin(), mid, 0, std::bit_xor<int>{}),
            std::accumulate(mid, nums.end(), 0, std::bit_xor<int>{}));
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<int> nums{1,2,3,3,4,8,6,5,6,5,7,7,8,1};
    EXPECT_EQ(two_number_appear_once(nums).value(), std::make_pair(2, 4));
    nums.clear();
    EXPECT_ANY_THROW(two_number_appear_once(nums).value());
}
