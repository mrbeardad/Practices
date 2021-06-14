#include <cctype>
#include <gtest/gtest.h>
#include <limits>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        size_t idx{};
        for ( ; idx < s.size() && s[idx] == ' '; ++idx );
        if ( idx == s.size() )
            return 0;
        int sign{1};
        if ( s[idx] == '-' ) {
            sign = -1;
            ++idx;
        } else if ( s[idx] == '+' ) {
            ++idx;
        }
        int num{};
        for ( ; idx < s.size() && isdigit(s[idx]); ++idx ) {
            int signedNum{num * sign};
            if ( signedNum > std::numeric_limits<int>::max() / 10
                    || signedNum == std::numeric_limits<int>::max() / 10 && s[idx] > '7' )
                return std::numeric_limits<int>::max();
            else if ( signedNum < std::numeric_limits<int>::min() / 10
                    || signedNum == std::numeric_limits<int>::min() / 10 && s[idx] > '8' )
                return std::numeric_limits<int>::min();

            num = num * 10 + s[idx] - '0';
        }
        return num * sign;
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.myAtoi("123"), 123);
    EXPECT_EQ(Solution{}.myAtoi("2147483647"), 2147483647);
    EXPECT_EQ(Solution{}.myAtoi("2147483648"), 2147483647);
    EXPECT_EQ(Solution{}.myAtoi("21474836460"), 2147483647);
    EXPECT_EQ(Solution{}.myAtoi("-2147483648"), -2147483648);
    EXPECT_EQ(Solution{}.myAtoi("-2147483649"), -2147483648);
}
