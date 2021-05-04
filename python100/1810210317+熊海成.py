#!/usr/bin/env python
# -*- coding: utf-8 -*-

def print_multi_matrix(n : int):
    print("+" + "----+" * n)
    for i in range(n):
        print("|" + "    |" * n)
        print("|" + "    |" * n)
        print("+" + "----+" * n)

if __name__ == '__main__':
    rank = int(input("input a integer as rank: "))
    print()
    print_multi_matrix(rank)
