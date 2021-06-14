#!/usr/bin/env python
# -*- coding: utf-8 -*-

counter=1
num=0

def tvb():
    global counter
    for i in (1,2,3):
        counter+=1
        num=10

tvb()
print(counter,num)
print(eval("5/2+5%2+5//2"))
