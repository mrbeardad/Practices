#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

std::string& revers_words(std::string& str)
{
    std::reverse(str.begin(), str.end());
    for ( size_t left{}, right{}; ; ) {
        for ( left = right; left < str.size() && std::isspace(str[left]); ++left );
        if ( left == str.size() )
            break;
        for ( right = left; right < str.size() && !std::isspace(str[right]); ++right );
        std::reverse(&str[left], &str[right]);
    }
    return str;
}

TEST(TestSuit, TestCase)
{
    std::string str{"hello world"};
    EXPECT_EQ(revers_words(str), "world hello");
}
