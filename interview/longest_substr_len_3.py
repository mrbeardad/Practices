#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen, startIdx, idxOfLastArvChar = 0, 0, {}
        for idx, char in enumerate(s):
            if idxOfLastArvChar.get(char, -1) >= startIdx:
                maxLen = max(maxLen, idx - startIdx)
                startIdx = idxOfLastArvChar[char] + 1
            idxOfLastArvChar[char] = idx
        return maxLen


print(Solution().lengthOfLongestSubstring("abcade"))
print(Solution().lengthOfLongestSubstring("abcabcbb"))
