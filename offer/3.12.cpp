#include <algorithm>
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <unordered_map>


class DistinctSubstring {
public:
    int longestSubstring(std::string A, int n) {
        // write code here
        std::unordered_map<char, ssize_t> lastCharIdx{};
        ssize_t startIdx{};
        ssize_t maxLen{};
        for ( ssize_t idx{}; idx < n; ++idx ) {
            char curChar{A[idx]};
            auto repeatChar = lastCharIdx.find(curChar);
            if ( repeatChar != lastCharIdx.end() && repeatChar->second >= startIdx ) {
                maxLen = std::max(maxLen, idx - startIdx);
                startIdx = repeatChar->second + 1;
            }
            lastCharIdx[curChar] = idx;
        }
        maxLen = std::max(maxLen, n - startIdx);
        return maxLen;
    }
};


TEST(TestSuit, TestCase)
{
    EXPECT_EQ(DistinctSubstring{}.longestSubstring("abcade", 6), 5);
    EXPECT_EQ(DistinctSubstring{}.longestSubstring("abcabcbb", 8), 3);
}
