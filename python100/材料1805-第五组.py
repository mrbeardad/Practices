#!/usr/bin/env python
# -*- coding: utf-8 -*-

from turtle import Screen, Turtle
import math
import time


class Point:
    """
    用于表示笛卡尔坐标的类
    """
    def __init__(self, x=0, y=0):
        self.x = float(x)
        self.y = float(y)


class Fractcal:
    def __init__(self, screenWidth: int=300, screenHeight: int=400):
        """
        初始化turtle
        """
        self.screen_ = Screen()
        self.turtle_ = Turtle()
        self.screen_.setup(width=screenWidth, height=screenHeight)
        self.turtle_.speed(0)
        self.turtle_.pensize(2)
        self.turtle_.hideturtle()
        self.screen_.tracer(False)


    def drawCore(self, pointA: Point, pointB: Point):
        """
        @param: pointA, pointB分别表示向量AB的起始坐标与终止坐标
        @func:  函数副作用即分形递归绘制向量AB
        """
        # 基准情况：当向量AB长度小于临界值时直接绘制直线
        if math.dist((pointA.x, pointA.y), (pointB.x, pointB.y)) < 5:
            self.turtle_.goto(pointB.x, pointB.y)
            return

        # 根据等边三角形两点坐标，获取第三点坐标，第三点始终在向量AB左侧
        def thirdPos(pointA: Point, pointB: Point):
            third = Point()
            distAC = math.dist((pointA.x, pointA.y), (pointB.x, pointB.y))
            theta = math.atan2(pointB.y - pointA.y, pointB.x - pointA.x) + math.acos(1 / 2)
            third.x = distAC * math.cos(theta) + pointA.x
            third.y = distAC * math.sin(theta) + pointA.y
            return third

        # 将向量AB分为4部分
        # __/\__
        # 图形如上，中间突起形成等边三角形，两边横线为向量AB的三分之一
        pointAB13 = Point((pointB.x - pointA.x) / 3 + pointA.x, (pointB.y - pointA.y) / 3 + pointA.y)
        pointAB23 = Point((pointB.x - pointA.x) * 2 / 3 + pointA.x, (pointB.y - pointA.y) * 2 / 3 + pointA.y)
        third = thirdPos(pointAB13, pointAB23)

        # 递归绘制四部分
        self.drawCore(pointA, pointAB13)
        self.drawCore(pointAB13, third)
        self.drawCore(third, pointAB23)
        self.drawCore(pointAB23, pointB)


    def draw(self, x1, y1, x2, y2):
        """
        绘制每一帧的内容
        """
        self.turtle_.clear()
        self.turtle_.penup()
        self.turtle_.goto(x1, y1)
        self.turtle_.pendown()
        self.drawCore(Point(x1, y1), Point(x2, y2))
        self.screen_.update()


def main():
    """
    对于此分形几何图，当生长后的长度为原长度3倍时会与原图部分重叠
    """
    core = Fractcal()
    while True:
        curHalfLen = 200
        while curHalfLen <= 200 * 3:
            posY = -(curHalfLen / 3 - 200) * math.sqrt(3) - 200
            core.draw(-curHalfLen, posY, curHalfLen, posY)
            curHalfLen += 10
            time.sleep(0.01)
            #  if curHalfLen < 500:
                #  time.sleep(.05)
    core.screen_.mainloop()


if __name__ == '__main__':
    main()
