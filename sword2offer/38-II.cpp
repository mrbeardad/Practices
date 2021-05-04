#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

void combination(std::string& str, size_t idx, size_t len, std::vector<std::string>& comb)
{
    if ( len == 0 ) {
        comb.emplace_back(comb.back());
        return;
    }
    if ( len > str.size() - idx ) {
        return;
    }

    comb.back().push_back(str[idx]);
    combination(str, idx + 1, len - 1, comb);
    comb.back().pop_back();
    combination(str, idx + 1, len, comb);
    return;
}

std::vector<std::string> combination(std::string str)
{
    std::vector<std::string> ret{};
    ret.emplace_back("");
    for ( size_t len{1}; len <= str.size(); ++len ) {
        combination(str, 0, len, ret);
    }
    ret.pop_back();
    return ret;
}

std::vector<std::string> combination_by_dp(const std::string& str)
{
    std::vector<std::string> dp{};
    if ( str.empty() )
        return dp;
    dp.emplace_back(str.substr(0, 1));
    for ( size_t idx{1}; idx < str.size(); ++idx ) {
        size_t lastDpLen{dp.size()};
        for ( size_t lastDpIdx{}; lastDpIdx < lastDpLen; ++lastDpIdx ) {
            dp.emplace_back(dp[lastDpIdx] + str[idx]);
        }
        dp.emplace_back(str.substr(idx, 1));
    }
    return dp;
}

TEST(TestSuit, TestCase)
{
    std::vector<std::string> ans{}, comb{};
    comb = combination_by_dp("");
    EXPECT_TRUE(std::is_permutation(comb.begin(), comb.end(), ans.begin()));
    ans.assign({"a"});
    comb = combination_by_dp("a");
    EXPECT_TRUE(std::is_permutation(comb.begin(), comb.end(), ans.begin()));
    ans.assign({"a", "b", "ab"});
    comb = combination_by_dp("ab");
    EXPECT_TRUE(std::is_permutation(comb.begin(), comb.end(), ans.begin()));
    ans.assign({"a", "b", "c", "ab", "ac", "bc", "abc"});
    comb = combination_by_dp("abc");
    EXPECT_TRUE(std::is_permutation(comb.begin(), comb.end(), ans.begin()));
    ans.assign({"a", "b", "c", "d", "ab", "ac", "ad", "bc", "bd", "cd", "abc", "abd", "acd", "bcd", "abcd"});
    comb = combination_by_dp("abcd");
    EXPECT_TRUE(std::is_permutation(comb.begin(), comb.end(), ans.begin()));
}
