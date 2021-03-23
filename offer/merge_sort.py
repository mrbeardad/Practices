#!/usr/bin/env python
# -*- coding: utf-8 -*-

def merge_sort(needSort: list, begin, end):
    if end - begin <= 1:
        return

    center = (begin + end) // 2
    merge_sort(needSort, begin, center)
    merge_sort(needSort, center, end)
    # merge [begin, center] and [center, end]
    leftIdx, leftEnd, rightIdx, rightEnd = begin, center, center, end
    tmpList = []
    while leftIdx < leftEnd and rightIdx < rightEnd:
        if needSort[leftIdx] < needSort[rightIdx]:
            tmpList.append(needSort[leftIdx])
            leftIdx += 1
        else:
            tmpList.append(needSort[rightIdx])
            rightIdx += 1

    while leftIdx < leftEnd:
        tmpList.append(needSort[leftIdx])
        leftIdx += 1

    while rightIdx < rightEnd:
        tmpList.append(needSort[rightIdx])
        rightIdx += 1

    for val in tmpList:
        needSort[begin] = val
        begin += 1


List = list(map(int, input().split()))
print(List)
merge_sort(List, 0, len(List))
print(List)
