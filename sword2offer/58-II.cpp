#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<typename Iter>
Iter my_rotate(Iter begin, Iter mid, Iter end)
{
    std::reverse(begin, mid);
    std::reverse(mid, end);
    std::reverse(begin, end);
    return begin + (end - mid);
}

TEST(TestSuit, TestCase)
{
    std::string str{"w DNMD gj"};
    my_rotate(str.begin(), str.begin() + 1, str.end());
    EXPECT_EQ(str, " DNMD gjw");
}
