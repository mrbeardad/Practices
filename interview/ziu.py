#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> list[int]:
        nums = list(range(left, right + 1))
        ret = []
        for thisNum in nums:
            origNum = thisNum
            notThis = False
            while thisNum:
                if thisNum % 10 == 0 or origNum % (thisNum % 10):
                    notThis = True
                    break
                thisNum //= 10
            if not notThis:
                ret.append(origNum)
        return ret

print(Solution().selfDividingNumbers(1, 22))
