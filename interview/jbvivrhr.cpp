#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


std::string convert(int num)
{
    std::string ans{};

    for ( ; num > 0; num = num / 26 )
        ans += num % 26 ? '@' + num % 26 : 'Z';

    for ( size_t idx{}; idx < ans.size(); ++idx ) {
        if ( ans[idx] == 'Z' )
            if ( ans[idx + 1] == 'A' )
                ans.erase(idx + 1);
            else
                --ans[idx + 1];
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(convert(0), "");
    EXPECT_EQ(convert(1), "A");
    EXPECT_EQ(convert(26), "Z");
    EXPECT_EQ(convert(27), "AA");
    EXPECT_EQ(convert(28), "AB");
}
