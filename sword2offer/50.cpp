#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>

char first_char_without_duplicate(const std::string& str)
{
    std::unordered_map<char, int> visited{};
    for ( char thisChar : str )
        ++visited[thisChar];
    for ( char thisChar : str )
        if ( visited[thisChar] == 1 )
            return thisChar;
    return 0;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(first_char_without_duplicate("abcde"), 'a');
    EXPECT_EQ(first_char_without_duplicate("aabbe"), 'e');
    EXPECT_EQ(first_char_without_duplicate("aabcc"), 'b');
    EXPECT_EQ(first_char_without_duplicate("aabbcc"), '\0');
    EXPECT_EQ(first_char_without_duplicate("a"), 'a');
    EXPECT_EQ(first_char_without_duplicate(""), '\0');
}
