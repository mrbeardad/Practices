#include <gtest/gtest.h>
#include <unordered_map>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, size_t> lastCharIdx{};
        size_t maxLen{};
        for ( size_t start{}, idx{}; ; ) {
            auto tagItr = lastCharIdx.find(s[idx]);
            size_t charIdx{tagItr != lastCharIdx.end() ? tagItr->second : 500000};
            if ( charIdx >= start && charIdx < idx ) {
                maxLen = std::max(maxLen, idx - start);
                start = charIdx + 1;
            }
            lastCharIdx[s[idx]] = idx;
            if ( ++idx == s.size() ) {
                maxLen = std::max(maxLen, idx - start);
                break;
            }
        }
        return maxLen;
    }
};

TEST(TestSuit, TestCase)
{
    EXPECT_EQ(Solution{}.lengthOfLongestSubstring("abcabcde"), 5);
}
