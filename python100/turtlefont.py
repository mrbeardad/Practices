#!/usr/bin/env python
# -*- coding: utf-8 -*-

import turtle
import tkinter

pen = turtle.Turtle()
scr = turtle.Screen()
# pen.rotate(45)
# pen.write("values", font=('Arial', 12, 'normal'))
c = scr.getcanvas()
c.create_text(100, 100, angle=90, text='fuck')
pen.hideturtle()
scr.mainloop()
