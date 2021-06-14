import turtle   # 导入turtle库

def draw_tree(branch_length, t):        # 递归函数主体
    if branch_length > 5:   # 树枝长度大于5时递归画树枝
        t.forward(branch_length)        # 向正方向绘制长度为branch_length的线
        t.right(20)                     # 向右转20度
        draw_tree(branch_length-15, t)  # 递归画左树枝
        t.left(40)                      # 向左转40度
        draw_tree(branch_length-15, t)  # 递归画右树枝
        t.right(20)                     # 向右转20度
        t.backward(branch_length)       # 向相反方向绘制长度为branch_length的线
        binaryTree.color('gray')        # 绘制灰色的树干
    else:   # 当树枝长度小于等于5时树枝画为绿色并结束递归
        binaryTree.color('green')       # 绘制绿色的树枝尖


if __name__ == "__main__":
    binaryTree = turtle.Turtle()        # 构造Turtle对象实例
    binaryTree.speed(0)                 # 设置画笔速度
    binaryTree.pensize(3)               # 设置画笔粗细
    paintingBoard = turtle.Screen()     # 构造Screen对象实例
    binaryTree.left(90)                 # 向左转90度
    binaryTree.up()                     # 抬起尾巴
    binaryTree.backward(200)            # 向后画200长度
    binaryTree.down()                   # 放下尾巴
    binaryTree.color('gray')            # 树干为灰色
    draw_tree(100, binaryTree)          # 主题逻辑。画树
    paintingBoard.exitonclick()         # 绘制完成后，点击即可推出
