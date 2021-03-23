#!/usr/bin/env python
# -*- coding: utf-8 -*-



def main():
    with open('class.py') as py:
        for oneline in py:
            print(oneline.find('\n'), ':', end='')
            print(oneline, end='')


if __name__ == '__main__':
    main()
