#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def trap(self, height: list[int]) -> int:
        monoStack = []
        rainDrops = 0
        for idx, hei in enumerate(height):
            if not monoStack or hei < monoStack[-1][1]:
                monoStack.append((idx, hei))
            else:
                nextPopElemHei = 0
                while monoStack and monoStack[-1][1] <= hei:
                    popElem = monoStack.pop()
                    rainDrops += (idx - popElem[0] - 1) * (popElem[1] - nextPopElemHei)
                    nextPopElemHei = popElem[1]
                if monoStack:
                    rainDrops += (idx - monoStack[-1][0] - 1) * (hei - nextPopElemHei)
                monoStack.append((idx, hei))
        return rainDrops

print(Solution().trap(list(map(int, input().split()))))
