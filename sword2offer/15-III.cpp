#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int change_bits(unsigned int lhs, unsigned int rhs)
{
    lhs ^= rhs;
    int ans{};
    for ( ; lhs; lhs &= lhs - 1 )
        ++ans;
    return ans;
}


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(change_bits(0x7, 0x0), 3);
    EXPECT_EQ(change_bits(0x0, 0x0), 0);
}
