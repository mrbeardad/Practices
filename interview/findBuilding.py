#!/usr/bin/env python
# -*- coding: utf-8 -*-

def findBuilding(heights):
    seeing = [1 for i in heights]
    for idx, val in enumerate(heights):
        idx += 1
        while idx < len(heights) and heights[idx] < val:
            seeing[idx] += 1
            idx += 1
        if idx < len(heights):
            seeing[idx] += 1

    idx = len(heights) - 1
    while idx >= 0:
        val = heights[idx]
        origIdx = idx
        idx -= 1
        while idx >= 0 and heights[idx] < val:
            seeing[idx] += 1
            idx -= 1
        if idx >= 0:
            seeing[idx] += 1
        idx = origIdx - 1

    return seeing


def main():
    buildings = input().split()
    buildings = list(map(int, buildings))
    print(findBuilding(buildings))


main()
