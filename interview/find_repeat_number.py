#!/usr/bin/env python
# -*- coding: utf-8 -*-

def findRepeatNumber(nums: list[int]) -> int:
    idx = 0
    while idx < len(nums):
        val = nums[idx]
        if val == idx:
            idx += 1
            continue
        if val == nums[val]:
            return val
        nums[idx] = nums[val]
        nums[val] = val

def main():
    nums = input().split()
    nums = list(map(int, nums))
    print(findRepeatNumber(nums))

main()
