from turtle import *    # 导入turtle库全部符号

def koch(size,n):       # 递归函数主体
    if n == 0:          # 递归基准，n等于0则画直线
        fd(size)
    else:               # 一般情况，画方块
        for angle in [0,90,-90,-90,90]:
            left(angle)
            koch(size/3,n-1)


def main():
    pencolor('red')     # 设置画笔颜色为红色
    setup(900,900)      # 设置窗口宽度和高度为900
    speed(0)            # 设置速度为0（最快）
    pensize(2)          # 设置画笔粗细度为2
    penup()             # 起笔
    goto(-300,250)      # 移动画笔到初始位置
    pendown()           # 落笔
    size,n=300,3        # 设置递归函数参数
    koch(size,n)        # 调用递归函数
    right(60)           # 右转60度
    koch(size,n)        # 继续画
    right(60)           # 右转60度
    koch(size,n)        # 调用递归函数
    right(60)           # 继续。。
    koch(size,n)        # 所以干嘛不用循环？
    right(60)
    koch(size,n)
    right(60)
    koch(size,n)
    right(60)


main()                  # 执行main函数画边框
pensize(10)             # 设置画笔粗细为10
#绘制福字的偏旁
penup(),seth(-90),fd(150),
pendown(),seth(-45),fd(50)    #绘制上边的“丶”
seth(45),penup(),bk(100)
seth(15),pendown(),fd(115)    
seth(55),pendown(),bk(200),fd(150)    #绘制“横折”
seth(-90),fd(220)                      #绘制“竖”
bk(200),seth(-45),pendown(),fd(50)     #绘制右边的“丶”
#绘制福字的‘一’
seth(70),penup(),fd(190)
seth(10),pendown(),fd(122)
#绘制福字的‘口’
seth(37),penup(),bk(150)
seth(-85),pendown(),fd(75)                   #绘制左“竖”
penup(),bk(70),seth(10),pendown(),fd(122)    #绘制上“横”
right(105),fd(70)                            #绘制右“竖”
seth(10),penup(),bk(90),pendown(),fd(90)     #绘制下“横”
#绘制福字的‘田’
seth(37),penup(),bk(165)
seth(-85),pendown(),fd(110),penup(),bk(105)  #绘制左“竖”
seth(10),pendown(),fd(175)                   #绘制上“横”
right(105),fd(145),bk(85)                    #绘制右“竖”
seth(10),penup(),bk(150),pendown(),fd(150)   #绘制十的“横”
seth(-15),penup(),bk(85),right(75),pendown(),fd(90)   #绘制十的“竖”
seth(3),penup(),bk(60),pendown(),fd(115)     #绘制下“横”
hideturtle()
exitonclick()


