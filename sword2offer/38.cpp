#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>

void dfs(std::string& str, size_t idx, std::vector<std::string>& perm)
{
    if ( idx >= str.size() ) {
        perm.emplace_back(str);
        return;
    }

    for ( size_t swapIdx{idx}; swapIdx < str.size(); ++swapIdx ) {
        std::swap(str[idx], str[swapIdx]);
        dfs(str, idx + 1, perm);
        std::swap(str[idx], str[swapIdx]);
    }
}

std::vector<std::string> permutation(std::string str)
{
    std::vector<std::string> ret{};
    if ( str.empty() )
        return ret;
    dfs(str, 0, ret);
    return ret;
}

TEST(TestSuit, TestCase)
{
    std::vector<std::string> ans{};
    EXPECT_EQ(permutation(""), ans);
    ans.assign({"a"});
    EXPECT_EQ(permutation("a"), ans);
    ans.assign({"ab", "ba"});
    EXPECT_EQ(permutation("ab"), ans);
    ans.assign({"abc", "acb", "bac", "bca", "cba", "cab"});
    EXPECT_EQ(permutation("abc"), ans);
}
