#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool is2exp(unsigned int num)
{
    if ( num == 0 )
        return false;
    num &= num - 1;
    return num == 0;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(is2exp(0x10), true);
    EXPECT_EQ(is2exp(0x0), false);
    EXPECT_EQ(is2exp(0x1), true);
    EXPECT_EQ(is2exp(0x8), true);
}
