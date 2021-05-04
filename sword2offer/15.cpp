#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int num_of_1bit(unsigned int bits)
{
    int sum{};
    for ( ; bits; bits &= bits - 1 )
        ++sum;
    return sum;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(num_of_1bit(0xFF), 8);
    EXPECT_EQ(num_of_1bit(0x11), 2);
    EXPECT_EQ(num_of_1bit(0x0), 0);
    EXPECT_EQ(num_of_1bit(0xFFFFFFFF), 32);
}
