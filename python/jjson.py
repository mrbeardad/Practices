#!/usr/bin/env python
# -*- coding: utf-8 -*-

import json

def main():
    with open('json.json', 'r+') as jf:
        print(json.load(jf))

if __name__ == '__main__':
    main()
