#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

template<int CUR_NUM>
int sum()
{
    return CUR_NUM + sum<CUR_NUM - 1>();
}

template<>
int sum<1>()
{
    return 1;
}

class Sum
{
public:
    Sum()
    {
        GetSum() += CurNum()++;
    }

    static int& CurNum()
    {
        static int Val{1};
        return Val;
    }
    static int& GetSum()
    {
        static int Val{};
        return Val;
    }
};

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(sum<1>(), 1);
    EXPECT_EQ(sum<5>(), 15);
    Sum s[5];
    EXPECT_EQ(Sum::GetSum(), 15);
}
