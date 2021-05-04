#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

bool regex_match(const std::string& str, const std::string& pat)
{
    std::vector<std::vector<bool> > dp(str.size() + 1, std::vector<bool>(pat.size() + 1));
    dp[0][0] = true;

    for ( size_t strLen{}; strLen <= str.size(); ++strLen ) {
        for ( size_t patLen{1}; patLen <= pat.size(); ++patLen ) {
            if ( pat[patLen - 1] != '*' )
                dp[strLen][patLen] = strLen >= 1 && dp[strLen - 1][patLen - 1]
                    && (str[strLen - 1] == pat[patLen - 1] || pat[patLen - 1] == '.');
            else if ( strLen >= 1 && patLen >= 2
                    && (str[strLen - 1] == pat[patLen - 2] || pat[patLen - 2] == '.') )
                dp[strLen][patLen] = dp[strLen - 1][patLen] || dp[strLen][patLen - 2];
            else
                dp[strLen][patLen] = patLen >= 2 && dp[strLen][patLen - 2];
        }
    }
    return dp[str.size()][pat.size()];
}

TEST(TestSuit, TestCase)
{
    EXPECT_TRUE(regex_match("abcde", "abcde"));
    EXPECT_FALSE(regex_match("abcde", "abcd"));
    EXPECT_FALSE(regex_match("abcde", "bcde"));
    EXPECT_FALSE(regex_match("abcde", "abde"));

    EXPECT_TRUE(regex_match("abcde", "..cde"));
    EXPECT_TRUE(regex_match("abcde", "ab..e"));
    EXPECT_TRUE(regex_match("abcde", "abc.."));

    EXPECT_TRUE(regex_match("bcde", "a*bcde"));
    EXPECT_TRUE(regex_match("abde", "abc*de"));
    EXPECT_TRUE(regex_match("abcd", "abcde*"));

    EXPECT_TRUE(regex_match("abcde", "a*bcde"));
    EXPECT_TRUE(regex_match("abcde", "abc*de"));
    EXPECT_TRUE(regex_match("abcde", "abcde*"));

    EXPECT_TRUE(regex_match("aabcde", "a*bcde"));
    EXPECT_TRUE(regex_match("abccde", "abc*de"));
    EXPECT_TRUE(regex_match("abcdee", "abcde*"));

    EXPECT_TRUE(regex_match("aab", "a*aab"));
    EXPECT_TRUE(regex_match("aab", "a*ab"));
    EXPECT_TRUE(regex_match("aaab", "a*ab"));

    EXPECT_TRUE(regex_match("asdfsfsdf", ".*"));
}
