#!/usr/bin/env python
# -*- coding: utf-8 -*-

class T:
    def __init__(self):
        self.i = 1
        self.f = 2.5

t = T()
print(t.i)
t2 = t
t2.i = 2
print(t.i, t2.i)
