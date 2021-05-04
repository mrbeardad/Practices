#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>



int mypow(long base, int exp)
{
    long ans{1};
    for ( ; exp > 0; exp >>= 1 ) {
        ans = exp & 0x1 ? (ans * base) % int(1e9 + 7) : ans;
        base = (base * base) % int(1e9 + 7);
    }
    return ans;
}

double mypowf(double base, int exp)
{
    if ( exp < 0 ) {
        base = 1 / base;
        exp = -exp;
    }
    double ans{1};
    for ( unsigned int expp = exp; expp > 0; expp >>= 1 ) {
        ans = expp & 0x1 ? ans * base : ans;
        base *= base;
    }
    return ans;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(mypow(2, 3), 8);
    EXPECT_EQ(mypow(3, 54 / 3) * 4 / (4 - 54 % 3), 387420489);
    EXPECT_EQ(mypowf(1.0, std::numeric_limits<int>::min()), 1.0);
    EXPECT_EQ(mypowf(2.0, std::numeric_limits<int>::min()), 0.0);
}
