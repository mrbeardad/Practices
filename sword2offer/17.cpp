#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::vector<std::string> print_nums(size_t len)
{
    if ( len == 0 )
        return {};

    auto plusone = [] (char& digit) {
        digit = digit < '9' ? digit + 1 : '0';
        return digit == '0';
    };
    std::string curNum(len, '0');
    std::vector<std::string> ret{};

    for ( ssize_t idx{}; idx >= 0; ) {
        ret.emplace_back(curNum);

        idx = static_cast<ssize_t>(len) - 1;
        for ( ; idx >= 0 && plusone(curNum[idx]); --idx );
    }
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<std::string> comp{};
    EXPECT_EQ(print_nums(0), comp);

    comp.assign({"0","1","2","3","4","5","6","7","8","9"});
    EXPECT_EQ(print_nums(1), comp);
}
