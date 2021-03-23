#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charInCurStr = {}
        maxLen = 0
        curLen = 0
        idx = 0
        while idx < len(s):
            val = s[idx]
            if val not in charInCurStr:
                curLen += 1
                charInCurStr[val] = idx
                idx += 1
            else:
                maxLen = max(maxLen, curLen)
                curLen = 0
                idx = charInCurStr[val] + 1
                charInCurStr = {}
        return maxLen


print(Solution().lengthOfLongestSubstring("''"))
