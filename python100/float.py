#!/usr/bin/env python
# -*- coding: utf-8 -*-

class D(int, float):
    def __init__(self):
        super(D, self).__init__()
        #  super(float, self).__init__()


d = D()
