#!/usr/bin/env python
# -*- coding: utf-8 -*-

def main():
    s = input()
    if s == s[::-1]:
        print(True)
    else:
        print(False)

if __name__ == '__main__':
    main()
