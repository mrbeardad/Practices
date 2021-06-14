#!/usr/bin/env python
# -*- coding: utf-8 -*-

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        revList = ListNode()
        pos = 1
        curNode = head
        while curNode:
            if pos == left - 1:
                preLeft = curNode
            elif pos == left:
                revRightNode = revList = curNode
            elif left < pos <= right:
                nextNode = curNode.next
                curNode.next = revList
                revList = curNode
                curNode = nextNode
                pos += 1
                continue
            elif pos == right + 1:
                nextRight = curNode
                break
            curNode = curNode.next
            pos += 1

        if left != 1:
            preLeft.next = revList
        else:
            head = revList
        if 'nextRight' in locals():
            revRightNode.next = nextRight
        else:
            revRightNode.next = None

        return head

ListNodes = ListNode()
curNode = ListNodes
for i in range(1, 5):
    curNode.val = i
    curNode.next = ListNode()
    curNode = curNode.next
curNode.val = 5
curNode.next = None

ANS = ListNodes
while ANS:
    print(ANS.val, end=', ')
    ANS = ANS.next
print()
ANS = reverseBetween(ListNodes, 2, 4)
while ANS:
    print(ANS.val, end=', ')
    ANS = ANS.next
