#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool isnumeric(const std::string& numeric)
{
    size_t idx{}, origIdx{};

    if ( numeric[0] == '+' || numeric[0] == '-' )
        ++idx;

    origIdx = idx;
    for ( ; std::isdigit(numeric[idx]); ++idx );
    bool hasDigitsBeforePoint{idx != origIdx};

    if ( numeric[idx] == '.' )
        ++idx;

    origIdx = idx;
    for ( ; std::isdigit(numeric[idx]); ++idx );
    bool hasDigitsAfterPoint{idx != origIdx};

    bool isExpRight{true};
    if ( numeric[idx] == 'e' || numeric[idx] == 'E' ) {
        ++idx;
        if ( numeric[idx] == '+' || numeric[idx] == '-' )
            ++idx;
        origIdx = idx;
        for ( ; std::isdigit(numeric[idx]); ++idx );
        isExpRight = idx != origIdx;
    }

    bool hasAnyOtherChar{idx != numeric.size()};

    // std::cout << "\e[31mfuck:\e[m " << std::boolalpha
    //     << hasDigitsBeforePoint << hasDigitsAfterPoint << isExpRight << !hasAnyOtherChar << std::endl;

    return (hasDigitsBeforePoint || hasDigitsAfterPoint) && isExpRight && !hasAnyOtherChar;
}

TEST(TestSuit, TestCase)
{
    EXPECT_TRUE(isnumeric("123"));
    EXPECT_TRUE(isnumeric("+123"));
    EXPECT_TRUE(isnumeric("-123"));
    EXPECT_FALSE(isnumeric("x123"));
    EXPECT_FALSE(isnumeric("1x23"));
    EXPECT_FALSE(isnumeric("123x"));

    EXPECT_TRUE(isnumeric("1."));
    EXPECT_TRUE(isnumeric(".1"));
    EXPECT_TRUE(isnumeric("1.1"));
    EXPECT_TRUE(isnumeric("1.e1"));
    EXPECT_TRUE(isnumeric(".1e+1"));
    EXPECT_TRUE(isnumeric("1.1e-1"));
    EXPECT_TRUE(isnumeric("11e-1"));
    EXPECT_FALSE(isnumeric("."));
    EXPECT_FALSE(isnumeric("1e"));
    EXPECT_FALSE(isnumeric("1e+"));
    EXPECT_FALSE(isnumeric("1e+1e"));
}
