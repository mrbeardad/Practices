#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>


class Solution {
public:
    bool isMatch(std::string str, std::string pat)
    {
        std::vector<std::vector<bool> > dp(str.size() + 1, std::vector<bool>(pat.size() + 1));
        dp[0][0] = true;

        auto match = [&str, &pat] (size_t i, size_t j) {
            if ( i == 0 )
                return false;
            return pat[j - 1] == '.' || pat[j - 1] == str[i - 1];
        };

        for ( size_t i{}; i <= str.size(); ++i ) {
            for ( size_t j{1}; j <= pat.size(); ++j ) {
                if ( pat[j - 1] != '*' ) {
                    if ( match(i, j) )
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                } else if ( match(i, j - 1) ) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];    // req: 正确正则表达式
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[str.size()][pat.size()];
    }
private:
    bool isMatch_v1_recur(std::string str, std::string pat)
    {
        return isMatch_recur(str, pat, 0, 0);
    }

    bool isMatch_recur(std::string& str, std::string& pat, size_t idxStr, size_t idxPat)
    {
        if ( idxStr == str.size() && idxPat == pat.size() )
            return true;
        if ( idxStr != str.size() && idxPat == pat.size() )
            return false;
        if ( pat[idxPat + 1] != '*' ) {
            if ( idxStr < str.size() && (pat[idxPat] == '.' || pat[idxPat] == str[idxStr]) ) {
                return isMatch_recur(str, pat, idxStr + 1, idxPat + 1);
            } else {
                return false;
            }
        } else if ( idxStr < str.size() && (pat[idxPat] == '.' || pat[idxPat] == str[idxStr]) ) {
            return isMatch_recur(str, pat, idxStr + 1, idxPat)
                || isMatch_recur(str, pat, idxStr, idxPat + 2)
                || isMatch_recur(str, pat, idxStr + 1, idxPat + 2);
        } else {
            return isMatch_recur(str, pat, idxStr, idxPat + 2);
        }
    }

    bool isMatch_broken(std::string str, std::string pat)
    {
        if ( str.empty() || pat.empty() )
            return false;

        size_t idxStr{}, idxPat{};
        bool escape{};
        for ( ; idxStr != str.size() && idxPat != pat.size(); ) {
            if ( pat[idxPat] == '\\' ) {    // 转义
                escape = true;
                ++idxPat;
                continue;
            }
            if ( pat[idxPat + 1] == '*' ) { // 不会越界
                size_t greedyPos{str.size()};   // 贪婪匹配最远点（尾后）
                if ( idxPat + 2 < pat.size() )
                    greedyPos = std::min(greedyPos, str.find_last_of(pat[idxPat + 2]));

                if ( !escape && pat[idxPat] == '.' )
                    idxStr = greedyPos;
                for ( ; idxStr < greedyPos && str[idxStr] == pat[idxPat]; ++idxStr );
                idxPat += 2;
            } else if ( !escape && pat[idxPat] == '.' || str[idxStr] == pat[idxPat] ) {
                ++idxPat;
                ++idxStr;
            } else {
                return false;
            }
            escape = false;
        }
        return idxStr == str.size() && idxPat == pat.size();
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.isMatch("bcc", "a*b*c*"), true);
    // EXPECT_EQ(Solution{}.isMatch("bcc", "a*b*c\\*"), false);
    // EXPECT_EQ(Solution{}.isMatch("bcc", "a*b\\*c*"), false);
    // EXPECT_EQ(Solution{}.isMatch("bcc", "a\\*b*c*"), false);
    EXPECT_EQ(Solution{}.isMatch("abc", "..."), true);
    // EXPECT_EQ(Solution{}.isMatch("abc", "\\..."), false);
    // EXPECT_EQ(Solution{}.isMatch("a..", "\\.*"), false);
    EXPECT_EQ(Solution{}.isMatch("abcde", ".*"), true);
    EXPECT_EQ(Solution{}.isMatch("abcde", "ab.*"), true);
    EXPECT_EQ(Solution{}.isMatch("abcde", ".*de"), true);
    EXPECT_EQ(Solution{}.isMatch("000", "0*0"), true);
    EXPECT_EQ(Solution{}.isMatch("aaaabb", "a*b*c*"), true);
}
