#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int add(int lhs, int rhs)
{
    int sum{};
    unsigned flag{0x1}, carry{};
    for ( ; flag; flag <<= 1 ) {
        unsigned s1{lhs & flag ^ rhs & flag};
        unsigned c1{lhs & flag & rhs & flag};
        unsigned s2{s1 ^ carry};
        unsigned c2{s1 & carry};
        sum |= s2;
        carry = (c1 ^ c2) << 1;
    }
    return sum;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(add(0, 1), 1);
    EXPECT_EQ(add(0, -1), -1);
    EXPECT_EQ(add(0, std::numeric_limits<int>::max()), std::numeric_limits<int>::max());
    EXPECT_EQ(add(0, std::numeric_limits<int>::min()), std::numeric_limits<int>::min());

    EXPECT_EQ(add(167, 1), 168);
    EXPECT_EQ(add(167, -1), 166);
    EXPECT_EQ(add(167, std::numeric_limits<int>::max()), std::numeric_limits<int>::max() + 167);
    EXPECT_EQ(add(167, std::numeric_limits<int>::min()), std::numeric_limits<int>::min() + 167);

    EXPECT_EQ(add(-167, 1), -166);
    EXPECT_EQ(add(-167, -1), -168);
    EXPECT_EQ(add(-167, std::numeric_limits<int>::max()), std::numeric_limits<int>::max() - 167);
    EXPECT_EQ(add(-167, std::numeric_limits<int>::min()), std::numeric_limits<int>::min() - 167);
}
