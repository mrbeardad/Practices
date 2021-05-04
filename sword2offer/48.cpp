#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>

std::string longest_substring_without_duplicate(const std::string& str)
{
    std::string ans{};
    size_t begin{}, end{};
    std::unordered_map<char, size_t> lastVisitedIdx{};
    for ( ; end < str.size(); ++end ) {
        auto lastVisited = lastVisitedIdx.find(str[end]);
        if ( lastVisited == lastVisitedIdx.end() || lastVisited->second < begin ) {
            lastVisitedIdx[str[end]] = end;
        } else {
            if ( end - begin > ans.size() )
                ans = str.substr(begin, end - begin);
            begin = lastVisited->second + 1;
            lastVisited->second = end;
        }
    }
    if ( end - begin > ans.size() )
        ans = str.substr(begin, end - begin);
    return ans;
}

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(longest_substring_without_duplicate("abcde"), "abcde");
    EXPECT_EQ(longest_substring_without_duplicate("aacde"), "acde");
    EXPECT_EQ(longest_substring_without_duplicate("abcdd"), "abcd");
    EXPECT_EQ(longest_substring_without_duplicate("abcce"), "abc");
    EXPECT_EQ(longest_substring_without_duplicate("aaaa"), "a");
    EXPECT_EQ(longest_substring_without_duplicate("a"), "a");
    EXPECT_EQ(longest_substring_without_duplicate(""), "");
}
