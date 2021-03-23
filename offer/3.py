#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    lines = int(input())
    arrays = [[]]
    for i in range(lines):
        arrays.append(list(map(int, input().split())))
    lines = int(input())
    for ii in range(lines):
        mergeLine = list(map(int, input().split()))
        merge = []
        for i in mergeLine[1:-1]:
            merge.extend(arrays[i][1:])
        merge = sorted(merge)
        print(merge[mergeLine[-1] - 1])


main()
