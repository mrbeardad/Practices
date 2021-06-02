#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math
from turtle import Turtle, Screen

class PointXY:
    def __init__(self, x=0, y=0):
        self.x = float(x)
        self.y = float(y)

    def __str__(self):
        return str(self.x) + ',' + str(self.y)

def thirdPos(pointA: PointXY, pointB: PointXY):
    third = PointXY()
    distAC = math.dist((pointA.x, pointA.y), (pointB.x, pointB.y))
    theta = math.acos((pointB.x - pointA.x) / distAC) + math.acos(1 / 2)
    third.x = distAC * math.cos(theta) + pointA.x
    third.y = distAC * math.sin(theta) + pointA.y
    return third

if __name__ == '__main__':
    screen_ = Screen()
    turtle_ = Turtle()
    screen_.setup(600, 600)
    turtle_.speed(1)
    pointA = PointXY(0, 0)
    pointB = PointXY(50, -50)
    third = thirdPos(pointA, pointB)
    turtle_.goto(pointB.x, pointB.y)
    turtle_.penup()
    turtle_.goto(pointA.x, pointA.y)
    turtle_.pendown()
    turtle_.goto(third.x, third.y)
    screen_.mainloop()

