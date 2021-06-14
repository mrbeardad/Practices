#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int sum(int lhs, int rhs)
{
    int flag{0x1}, sum{}, carry{};
    for ( ; flag; flag <<= 1 ) {
        int s1 = lhs & flag ^ rhs & flag;
        int c1 = lhs & flag & rhs & flag;
        int s2 = s1 ^ carry;
        int c2 = s1 & carry;
        sum |= s2;
        carry = (c1 ^ c2) << 1;
    }
    return sum;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(sum(1, 1), 2);
    EXPECT_EQ(sum(198, 2), 200);
    EXPECT_EQ(sum(0, 0), 0);
    EXPECT_EQ(sum(0, 25), 25);
    EXPECT_EQ(sum(std::numeric_limits<int>::max() - 1, 1), std::numeric_limits<int>::max());
    EXPECT_EQ(sum(std::numeric_limits<int>::max(), 1), std::numeric_limits<int>::min());
    EXPECT_EQ(sum(-1, -1), -2);
}
