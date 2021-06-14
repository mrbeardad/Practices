#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Test():
    """docstring for Test"""

    def __init__(self, arg):
        self.arg = arg

    @property
    def mem(self): self.a = 1

t = Test(1)
t.mem = 1
