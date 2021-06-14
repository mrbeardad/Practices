#!/usr/bin/env python
# -*- coding: utf-8 -*-

class ListNode:
   def __init__(self, x):
       self.val = x
       self.next = None
class TreeNode:
   def __init__(self, x):
       self.val = x
       self.left = None
       self.right = None

#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
# 你需要返回m个指针，第i个指针指向一条链，表示第i个问题的答案
# @param root TreeNode类 指向链表树的根
# @param b int整型一维数组 表示每个问题是什么
# @return ListNode类一维数组
#
class Solution:
    def solve(self , root: TreeNode , b: [int] ):
        # write code here
        stack = []

        def find(curRoot: TreeNode, tag: int):
            if not curRoot:
                return False
            elif curRoot.val == tag:
                stack.append(tag)
                return True

            if find(curRoot.left, tag) or find(curRoot.right, tag):
                stack.append(curRoot.val)
                return True
            else:
                return False

        retArray = []
        for i in b:
            find(root, i)
            retList = ListNode(0)
            nextNode = retList
            for i in stack[::-1]:
                nextNode.val = i
                nextNode.next = ListNode(0)
                lastNode = nextNode
                nextNode = nextNode.next
            lastNode.next = None
            retArray.append(retList)
            stack.clear()
        return retArray


T = TreeNode(1)
T.left = TreeNode(3)
T.right = TreeNode(3)
T.left.left = TreeNode(4)
T.left.right = TreeNode(5)
T.right.left = TreeNode(6)
T.right.right = TreeNode(7)

ret = Solution().solve(T,[1,3])
for i in ret:
    while i:
        print(i.val, end=',')
        i = i.next
    print()


