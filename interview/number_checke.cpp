#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <regex>

// bool number_check(const std::string& number)
// {
//     size_t start{number.find_first_not_of(' ')};
//     auto stiped = number.substr(start, number.find_last_not_of(' ') - start + 1);
//     std::regex integer{R"([+-]?[0-9]+)"};
//     std::regex float1{R"([+-]?([0-9]+\.[0-9]*|[0-9]*\.[0-9]+|[0-9]+)([eE][+-]?[0-9]+)?)"};
//     return std::regex_match(stiped, integer) || std::regex_match(stiped, float1);
// }

bool number_check(const std::string& number)
{
    size_t idx{};
    for ( ; number[idx] == ' '; ++idx );
    if ( number[idx] == '+' || number[idx] == '-' )
        ++idx;

    size_t origIdx{idx};
    for ( ; idx < number.size() && std::isdigit(number[idx]); ++idx );
    bool hasFormerNummber{idx != origIdx};

    if ( number[idx] == '.' )   // '\0'结尾，不会越界
        ++idx;

    origIdx = idx;
    for ( ; idx < number.size() && std::isdigit(number[idx]); ++idx );
    bool hasLatterNummber{idx != origIdx};

    if ( !hasFormerNummber && !hasLatterNummber )
        return false;

    if ( number[idx] == 'e' || number[idx] == 'E' ) {
        ++idx;
        if ( number[idx] == '+' || number[idx] == '-' )
            ++idx;
        origIdx = idx;
        for ( ; idx < number.size() && std::isdigit(number[idx]); ++idx );
        if ( idx == origIdx )
            return false;
    }
    for ( ; number[idx] == ' '; ++idx );

    return idx == number.size();
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(number_check("1"), true);
    EXPECT_EQ(number_check("123456"), true);
    EXPECT_EQ(number_check("+123456"), true);
    EXPECT_EQ(number_check("-123456"), true);
    EXPECT_EQ(number_check("-123456 "), true);
    EXPECT_EQ(number_check(" -123456"), true);
    EXPECT_EQ(number_check(" -123456 "), true);

    EXPECT_EQ(number_check("1."), true);
    EXPECT_EQ(number_check(".1"), true);
    EXPECT_EQ(number_check("1.1"), true);
    EXPECT_EQ(number_check("1.e1"), true);
    EXPECT_EQ(number_check(".1e1"), true);
    EXPECT_EQ(number_check("1.1e1"), true);
    EXPECT_EQ(number_check("1e1"), true);
    EXPECT_EQ(number_check("1e"), false);
    EXPECT_EQ(number_check("1e+"), false);
    EXPECT_EQ(number_check("1e-1"), true);
}
