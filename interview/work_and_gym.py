#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    input()
    workDays = input().split()
    gymDays = input().split()
    for idx, val in enumerate(workDays):
        workDays[idx] = int(val)
    for idx, val in enumerate(gymDays):
        gymDays[idx] = int(val)

    memList = workDays[:]
    idx = len(workDays) - 1
    memList[idx] = (int(workDays[idx] == 0), int(gymDays[idx] == 0))
    idx -= 1
    while idx >= 0:
        memList[idx] = (1 + min(memList[idx + 1]) if workDays[idx] == 0 else memList[idx + 1][1],
                        1 + min(memList[idx + 1]) if gymDays[idx] == 0 else memList[idx + 1][0])
        idx -= 1
    #  print(memList)
    print(min(memList[0]))


main()
