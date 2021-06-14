#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        # 保持nums1长度小于或等于nums2，则二分搜索nums1不可能导致nums2的索引越界
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        # 特殊情况包括：
        # 头部与尾部    ：二分搜索到头尾表示穷尽了，中位数左侧元素全在一个list中
        # 空容器        ：空容器会导致索引越界，需提前特殊处理
        # 前节点与后节点：
        begin, end = 0, len(nums1)
        while begin <= end:
            idx1 = (begin + end) // 2
            idx2 = (len(nums1) + len(nums2)) // 2 - idx1

            #  print(F"idx1: {idx1} ;idx2 {idx2}")
            if idx2 > 0 and idx1 < len(nums1) and nums1[idx1] < nums2[idx2 - 1]:       # nums1选取的左侧元素数量太少
                begin = idx1 + 1
            elif idx1 > 0 and idx2 < len(nums2) and nums2[idx2] < nums1[idx1 - 1]:     # nums1选取的左侧元素数量太多
                end = idx1 - 1
            else:   # 找到了合适的位置，或者下标越界了（即中位数左侧全在一个list中）
                leftMax = max(nums1[idx1 - 1] if idx1 > 0 else -1e7, nums2[idx2 - 1] if idx2 > 0 else -1e7)
                rightMin = min(nums1[idx1] if idx1 < len(nums1) else 1e7, nums2[idx2] if idx2 < len(nums2) else 1e7)
                return rightMin if (len(nums1) + len(nums2)) % 2 else (leftMax + rightMin) / 2


try:
    while True:
        List1 = list(map(int, input().split()))
        List2 = list(map(int, input().split()))
        print(Solution().findMedianSortedArrays(List1, List2))
except EOFError:
    pass
