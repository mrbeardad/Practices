#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        mergeNums = []
        idx1, idx2 = 0, 0
        while idx1 < len(nums1) and idx2 < len(nums2):
            if nums1[idx1] < nums2[idx2]:
                mergeNums.append(nums1[idx1])
                idx1 += 1
            elif nums1[idx1] > nums2[idx2]:
                mergeNums.append(nums2[idx2])
                idx2 += 1
            else:
                mergeNums.append(nums1[idx1])
                mergeNums.append(nums1[idx1])
                idx1 += 1
                idx2 += 1
        if idx1 < len(nums1):
            mergeNums.extend(nums1[idx1:])
        elif idx2 < len(nums2):
            mergeNums.extend(nums2[idx2:])

        midIdx = len(mergeNums) / 2
        if midIdx.is_integer():
            return (mergeNums[int(midIdx)] + mergeNums[int(midIdx) - 1]) / 2
        else:
            return mergeNums[int(midIdx)]

def main():
    print(F"{Solution().findMedianSortedArrays([0, 0], [0, 0]):.5f}")

main()
