#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

size_t fibonacci(size_t n)
{
    if ( n <= 1 )
        return n;
    size_t fm1{1}, fm2{0};
    for ( size_t i{2}; i <= n; ++i ) {
        size_t tmp4fm2{fm1};
        fm1 += fm2;
        fm2 = tmp4fm2;
    }
    return fm1;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(fibonacci(0), 0);
    EXPECT_EQ(fibonacci(1), 1);
    EXPECT_EQ(fibonacci(2), 1);
    EXPECT_EQ(fibonacci(3), 2);
    EXPECT_EQ(fibonacci(4), 3);
    EXPECT_EQ(fibonacci(5), 5);
}
