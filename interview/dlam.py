#!/usr/bin/env python
# -*- coding: utf-8 -*-


from turtle import *


# 无轨迹跳跃
# 经常需要移动画笔，但不想留下轨迹，封装成函数方便调用
def my_goto(x, y):
    penup()
    goto(x, y)
    pendown()


# 头型
def head():
    penup()
    circle(150, 40)         # 移动画笔
    pendown()
    fillcolor('#00a0de')    # 选择填充蓝色
    begin_fill()
    circle(150, 280)        # 画圆（头部）
    end_fill()


# 围巾
def scarf():
    fillcolor('#e70010')    # 选择填充红色
    begin_fill()
    seth(0)
    fd(200)                 # 画圆矩形表示围巾
    circle(-5, 90)
    fd(10)
    circle(-5, 90)
    fd(207)
    circle(-5, 90)
    fd(10)
    circle(-5, 90)
    end_fill()


# 脸
def face():
    fd(183)                 # 下横线
    lt(45)                  # 调整角度准备画圆
    fillcolor('#ffffff')    # 选择填充白色
    begin_fill()
    circle(120, 100)        # 右画圆
    seth(180)
    # print(pos())
    fd(121)                 # 上横线
    pendown()
    seth(215)
    circle(120, 100)        # 左圆弧
    end_fill()
    my_goto(63,218)         # 调整位置准备画眼睛
    seth(90)
    eyes()                  # 右眼
    seth(180)
    penup()
    fd(60)
    pendown()
    seth(90)
    eyes()                  # 左眼
    penup()
    seth(180)
    fd(64)


# 胡须
def beard():
    # 接下来画六根胡须，调整位置与角度画直线即可
    my_goto(-32, 135)
    seth(165)
    fd(60)

    my_goto(-32, 125)
    seth(180)
    fd(60)

    my_goto(-32, 115)
    seth(193)
    fd(60)

    my_goto(37, 135)
    seth(15)
    fd(60)

    my_goto(37, 125)
    seth(0)
    fd(60)

    my_goto(37, 115)
    seth(-13)
    fd(60)


# 鼻子
def nose():
    # 调整位置画个半径20的圆并用红色填充代表鼻子
    my_goto(-10, 158)
    seth(315)
    fillcolor('#e70010')
    begin_fill()
    circle(20)
    end_fill()


# 嘴巴
def mouth():
    my_goto(5, 148)
    seth(270)
    fd(100)
    seth(0)
    circle(120, 50)     # 逆时针画半径120，角度50的圆弧
    seth(230)
    circle(-120, 100)   # 顺时针画半径120，角度100的圆弧

# 黑眼睛
def black_eyes():
    # 画左眼中黑色眼眸
    seth(0)
    my_goto(-20, 195)
    fillcolor('#000000')
    begin_fill()
    circle(13)
    end_fill()

    # 画右边眯眯眼，用圆弧表示
    pensize(6)
    my_goto(20, 205)
    seth(75)
    circle(-10, 150)
    pensize(3)

    # 在左边黑色眼眸中增加高光
    my_goto(-17, 200)
    seth(0)
    fillcolor('#ffffff')
    begin_fill()
    circle(5)
    end_fill()
    my_goto(0, 0)



# 身体
def body():
    # 身体
    my_goto(0, 0)
    seth(0)
    penup()
    circle(150, 50)
    pendown()
    seth(30)
    fd(40)
    seth(70)
    circle(-30, 270)

    fillcolor('#00a0de')
    begin_fill()

    seth(230)
    fd(80)
    seth(90)
    circle(1000, 1)
    seth(-89)
    circle(-1000, 10)

    seth(180)
    fd(70)
    seth(90)
    circle(30, 180)
    seth(180)
    fd(70)

    seth(100)
    circle(-1000, 9)

    seth(-86)
    circle(1000, 2)
    seth(230)
    fd(40)

    circle(-30, 230)
    seth(45)
    fd(81)
    seth(0)
    fd(203)
    circle(5, 90)
    fd(10)
    circle(5, 90)
    fd(7)
    seth(40)
    circle(150, 10)
    seth(30)
    fd(40)
    end_fill()


# 眼睛
def eyes():
    fillcolor("#ffffff")
    begin_fill()
    # 禁用刷新屏幕，不然画的慢
    tracer(False)
    # 椭圆算法
    a = 2.5
    for i in range(120):
        if 0 <= i < 30 or 60 <= i < 90:
            a -= 0.05
        else:
            a += 0.05
        # 左偏3度，30次共90度
        lt(3)
        # 弧度变长
        fd(a)
    # 重新启用屏幕刷新
    tracer(True)
    end_fill()


# 左手
def left_hand():
    seth(70)                # 来左手跟我一起画个圆~
    fillcolor('#ffffff')
    begin_fill()
    circle(-30)
    end_fill()


# 脚
def foot():
    # 右脚
    my_goto(103, -182)
    seth(0)
    fillcolor('#ffffff')
    begin_fill()
    fd(15)
    circle(-15, 180)
    fd(90)
    circle(-15, 180)
    fd(10)
    end_fill()
    # 左脚
    my_goto(-96.26, -182.59)
    seth(180)
    fillcolor('#ffffff')
    begin_fill()
    fd(15)
    circle(15, 180)
    fd(90)
    circle(15, 180)
    fd(10)
    end_fill()


# 右手
def right_hand():
    my_goto(-133, -91)      # 调整画笔位置
    seth(50)                # 调整方向
    fillcolor('#ffffff')    # 填充白色
    begin_fill()            # 开始填充
    circle(30)              # 画右手
    end_fill()              # 结束填充


# 口袋
def bag():
    my_goto(-103, 15)       # 移动画笔至适当位置
    seth(0)                 # 调整角度
    fd(38)                  # 画横线
    seth(230)               # 调整方向
    fillcolor('#ffffff')    # 设置颜色
    begin_fill()            # 开始填充
    circle(90, 260)         # 画大白肚子
    end_fill()              # 结束填充

    my_goto(5, -40)         # 移动画笔
    seth(0)                 # 调整方向
    fd(70)                  # 画口袋右上端
    seth(-90)               # 调整方向
    circle(-70, 180)        # 画口袋下端
    seth(0)                 # 调整方向
    fd(70)                  # 画口袋左上端


# 铃铛
def bell():
    my_goto(-103, 15)       # 移动画笔至左脖子处
    fd(90)                  # 画横线

    # 铃铛主体
    seth(70)                # 调整方向
    fillcolor('#ffd200')    # 选择填充颜色黄色
    begin_fill()            # 开始填充
    circle(-20)             # 画圆
    end_fill()              # 结束填充

    # 铃铛横杠
    seth(170)               # 调整方向
    fillcolor('#ffd200')    # 选择填充颜色黄色
    begin_fill()            # 开始填充
    circle(-2, 180)         # 画左边界
    seth(10)                # 调整方向
    circle(-100, 22)        # 画上横杠
    circle(-2, 180)         # 画右边界
    seth(170)               # 调整方向
    circle(100, 22)         # 画下横杠
    end_fill()              # 结束填充

    # 铃铛空隙
    goto(-13, 15)           # 移动画笔
    seth(250)               # 调整方向
    circle(20, 110)         # 画圆调整位置至铃铛正下方
    seth(90)                # 调整方向
    fd(15)                  # 画竖线
    dot(10)                 # 画点
    my_goto(0, -150)        # 移动画笔


# 哆啦A梦和我一起，让梦想发光(●'◡'●)ﾉ♥
def Doraemon():
    head()
    scarf()
    face()
    nose()
    mouth()
    beard()
    body()
    left_hand()
    foot()
    right_hand()
    bag()
    bell()
    black_eyes()


if __name__ == '__main__':
    # 创建窗口，宽800，高600，底色为绿色
    screensize(800, 600, "#00af00")
    # 画笔宽度为3
    pensize(3)
    # 画笔速度极快
    speed(0)
    # 业务主逻辑
    Doraemon()
    # 移动画笔并打印字体
    my_goto(50, -300)
    write('Python点子小组', font=("Comic", 30, "bold"))
    # 主循环防止退出
    mainloop()
