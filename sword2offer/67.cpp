#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <optional>

int string_to_int(const std::string& number)
{
    if ( number.empty() )
        throw std::length_error{"bad number"};

    size_t idx{};
    int sign{1};

    if ( number[0] == '+' ) {
        ++idx;
    } else if ( number[0] == '-' ) {
        ++idx;
        sign = -1;
    }

    size_t origIdx{idx};

    int num{};
    if ( sign == 1 ) {
        for ( ; idx < number.size() && std::isdigit(number[idx]); ++idx ) {
            if ( num > std::numeric_limits<int>::max() / 10
                    || num == std::numeric_limits<int>::max() / 10 && number[idx] > '7' )
                throw std::overflow_error{"too large"};
            num = num * 10 + (number[idx] - '0');
        }
    } else {
        for ( ; idx < number.size() && std::isdigit(number[idx]); ++idx ) {
            if ( num < std::numeric_limits<int>::min() / 10
                    || num == std::numeric_limits<int>::min() / 10 && number[idx] > '8' )
                throw std::overflow_error{"too large"};
            num = num * 10 - (number[idx] - '0');
        }
    }

    if ( origIdx == idx || idx != number.size() )
        throw std::length_error{"bad number"};

    return num;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(string_to_int("123"), 123);
    EXPECT_EQ(string_to_int("+123"), 123);
    EXPECT_EQ(string_to_int("-123"), -123);
    EXPECT_EQ(string_to_int("2147483647"), 2147483647);
    EXPECT_EQ(string_to_int("-2147483648"), -2147483648);
    EXPECT_ANY_THROW(string_to_int("2147483648"));
    EXPECT_ANY_THROW(string_to_int("-2147483649"));
    EXPECT_ANY_THROW(string_to_int(""));
    EXPECT_ANY_THROW(string_to_int("+"));
    EXPECT_ANY_THROW(string_to_int("e"));
    EXPECT_ANY_THROW(string_to_int("8e"));
    EXPECT_ANY_THROW(string_to_int("+e"));
    EXPECT_ANY_THROW(string_to_int("+8e"));
}
