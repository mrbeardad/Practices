#!/usr/bin/env python
# -*- coding: utf-8 -*-

def findBuilding(heights):
    seeing = [1 for i in heights]
    stack = []
    for idx, val in enumerate(heights):
        seeing[idx] += len(stack)
        while stack and stack[-1] <= val:
            stack.pop()
        stack.append(val)

    print(seeing)

    stack = []
    idx = len(heights) - 1
    while idx >= 0:
        val = heights[idx]
        seeing[idx] += len(stack)
        while stack and stack[-1] <= val:
            stack.pop()
        stack.append(val)
        idx -= 1

    return seeing


def main():
    buildings = input().split()
    buildings = list(map(int, buildings))
    print(findBuilding(buildings))


main()
