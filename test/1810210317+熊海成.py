#!/usr/bin/env python
# -*- coding: utf-8 -*-

import turtle

def olympic_rings(penWidth=15, penSpeed=0):
    screen = turtle.Screen()
    pen = turtle.Turtle()

    screen.setup(width=800, height=800)
    pen.pensize(penWidth)
    pen.speed(penSpeed)

    def single_ring(x, y, color):
        pen.penup()
        pen.goto(x, y)
        pen.color(color)
        pen.pendown()
        pen.circle(100, 360)

    single_ring(-250, 0, 'blue')
    single_ring(-130, -100, 'yellow')
    single_ring(-10, 0, 'black')
    single_ring(110, -100, 'green')
    single_ring(230, 0, 'red')

    screen.mainloop()


if __name__ == '__main__':
    olympic_rings()
