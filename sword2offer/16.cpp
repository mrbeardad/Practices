#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

double mypow(double base, int exp)
{
    // 0的负数次方以及0次方结果未定义，由调用者承担
    // 更高效做法是将该判断提出到外封装函数中
    if ( exp < 0 ) {
        base = 1 / base;
        exp = -exp;
    }

    if ( exp == 0 )
        return 1;
    if ( exp == 1 )
        return base;
    double ans{mypow(base, static_cast<unsigned int>(exp) >> 1)}; // 使用逻辑右移指令处理Tmin
    ans *= ans;
    return exp & 0x1 ? ans * base : ans;
}

TEST(TestSuit, TestCase)
{
    std::cout << mypow(0.0, 0) << ',' << mypow(0.0, -1) << std::endl;
    EXPECT_DOUBLE_EQ(mypow(1.0, 8), std::pow(1.0, 8));
    EXPECT_DOUBLE_EQ(mypow(1.0, 0), std::pow(1.0, 0));
    EXPECT_DOUBLE_EQ(mypow(1.0, -8), std::pow(1.0, -8));
    EXPECT_DOUBLE_EQ(mypow(0.0, 8), std::pow(0.0, 8));
    EXPECT_DOUBLE_EQ(mypow(0.0, 0), std::pow(0.0, 0));
    EXPECT_DOUBLE_EQ(mypow(0.0, -8), std::pow(0.0, -8));
    EXPECT_DOUBLE_EQ(mypow(0.1, -8), std::pow(0.1, -8));
    EXPECT_DOUBLE_EQ(mypow(0.1, 8), std::pow(0.1, 8));
    EXPECT_DOUBLE_EQ(mypow(0.1, 0), std::pow(0.1, 0));
}
