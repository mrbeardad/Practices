#!/usr/bin/env python
# -*- coding: utf-8 -*-

def binary_search(cont: list, target):
    if not cont:
        return -1
    begin, end = 0, len(cont)
    while begin != end:
        center = (begin + end) // 2
        if target > cont[center]:
            begin = center + 1
        elif target < cont[center]:
            end = center
        else:
            return center
    return -1

#  List = list(map(int, input().split()))
List = []
print(List)
print(binary_search(List, 1))
