#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

int excel_to_int(const std::string& str)
{
    int ans{};
    for ( size_t idx{}; idx < str.size(); ++idx ) {
        ans = ans * 26 + str[idx] - 'A' + 1;
    }
    return ans;
}
std::string int_to_excel(int num)
{
    std::string ans{};
    for ( ; num; num /= 26 ) {
        ans += num % 26 + 'A' - 1;
    }
    for ( size_t idx{}; idx < ans.size(); ++idx ) {
        if ( ans[idx] == '@' ) {
            if ( idx + 1 < ans.size() ) {
                ans[idx] = 'Z';
                --ans[idx + 1];
            } else {
                ans.erase(idx);
            }
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(excel_to_int("A"), 1);
    EXPECT_EQ(excel_to_int("Z"), 26);
    EXPECT_EQ(excel_to_int("AA"), 27);
    EXPECT_EQ(excel_to_int("AB"), 28);
    EXPECT_EQ(excel_to_int("AZ"), 52);
    EXPECT_EQ(excel_to_int("BA"), 53);

    EXPECT_EQ(int_to_excel(1), "A");
    EXPECT_EQ(int_to_excel(26), "Z");
    EXPECT_EQ(int_to_excel(27), "AA");
    EXPECT_EQ(int_to_excel(28), "AB");
    EXPECT_EQ(int_to_excel(52), "AZ");
    EXPECT_EQ(int_to_excel(53), "BA");
}
