#!/usr/bin/env python
# -*- coding: utf-8 -*-

def ext_gcd(a, b, x=0, y=0):
    if b == 0:
        return a, 1, 0

    gcd, y, x = ext_gcd(b, a % b, y, x)
    y -= a // b * x
    return gcd, x, y

def inverse(b, mod):
    for i in range(mod):
        if i * b % mod == 1:
            return i
    return 0

def main():
    A = int(input('A: '))
    B = int(input('B: '))
    N = int(input('N: '))
    gcd, Bi, ignore = ext_gcd(B, N)
    if gcd == 1:
        print(F"({A} / {B}) % {N} == ({A} % {N} * {Bi} % {N}) % N == {(A % N * Bi % N) % N}")

    print(F"Bi == {inverse(B, N)}")


if __name__ == '__main__':
    main()
