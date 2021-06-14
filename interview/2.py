#!/usr/bin/env python
# -*- coding: utf-8 -*-

memList = [(), (1, float('inf'), float('inf')), (2, float('inf'), 2), (3, float('inf'), 2)]

def min_cnt(num):
    memLen = len(memList)
    if num < memLen:
        return min(memList[num])
    while memLen <= num:
        m1 = 1 + min(memList[memLen - 1])
        d3 = 1 + min(memList[memLen // 3]) if memLen % 3 == 0 else float('inf')
        d2 = 1 + min(memList[memLen // 2]) if memLen % 2 == 0 else float('inf')
        memList.append((m1, d3, d2))
        memLen += 1
    return min(memList[num])


def main():
    lines = int(input())
    for i in range(lines):
        num = int(input())
        print(min_cnt(num))

main()
