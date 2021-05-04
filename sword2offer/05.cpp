#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

/*************************************************************************************************/
// 将字符串中空格转换为"%20"
/*************************************************************************************************/
std::string& replace_blanks(std::string& str)
{
    ssize_t cntBlank{std::count(str.begin(), str.end(), ' ')};
    ssize_t lastIdx{static_cast<ssize_t>(str.size()) - 1};
    str.resize(str.size() + cntBlank * 2);
    for ( size_t newLastIdx{str.size() - 1}; lastIdx >= 0; --lastIdx ) {
        if ( str[lastIdx] == ' ' ) {
            str[newLastIdx--] = '0';
            str[newLastIdx--] = '2';
            str[newLastIdx--] = '%';
        } else {
            str[newLastIdx--] = str[lastIdx];
        }
    }
    return str;
}


TEST(TestSuit, TestCase)
{
    std::string hasBlanks{"what are you fxxxing doing?"};
    EXPECT_EQ(replace_blanks(hasBlanks), "what%20are%20you%20fxxxing%20doing?");
    EXPECT_EQ(hasBlanks.size(), sizeof("what%20are%20you%20fxxxing%20doing?") - 1);
    EXPECT_EQ(replace_blanks(hasBlanks), "what%20are%20you%20fxxxing%20doing?");
    EXPECT_EQ(hasBlanks.size(), sizeof("what%20are%20you%20fxxxing%20doing?") - 1);
    hasBlanks.clear();
    EXPECT_EQ(replace_blanks(hasBlanks), "");
}
