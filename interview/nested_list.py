#!/usr/bin/env python
# -*- coding: utf-8 -*-

class NestedInteger:
    def isInteger(self) -> bool:
        """
        @return True if this NestedInteger holds a single integer, rather than a nested list.
        """

    def getInteger(self) -> int:
        """
        @return the single integer that this NestedInteger holds, if it holds a single integer
        Return None if this NestedInteger holds a nested list
        """

    def getList(self) -> [NestedInteger]:
        """
        @return the nested list that this NestedInteger holds, if it holds a nested list
        Return None if this NestedInteger holds a single integer
        """


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.topList_ = nestedList
        self.topIdx_ = 0
        self.nestListStack_ = []
        self.idxStack_ = []


    def next(self) -> int:
        ret = self.nestListStack_[-1].getList()[self.idxStack_[-1]].getInteger()
        self.idxStack_[-1] += 1
        return ret


    def hasNext(self) -> bool:
        while self.topIdx_ < len(self.topList_):
            if not self.nestListStack_:
                self.nestListStack_.append(self.topList_[self.topIdx_])
                self.idxStack_.append(0)

        while self.nestListStack_ and not self.nestListStack_[-1].getList()[self.idxStack_[-1]].isInteger():
            # 如果该层到边界则返回上层
            if self.idxStack_[-1] >= len(self.nestListStack_[-1].getList()):
                self.nestListStack_.pop()
                self.idxStack_.pop()
                if self.idxStack_:
                    self.idxStack_[-1] += 1
                else:   # 如果顶层为空则跳出循环，进入下一个顶层
                    self.topIdx_ += 1
                    break
            else:
                self.nestListStack_.append(self.nestListStack_[-1].getList()[self.idxStack_[-1]])
                self.idxStack_.append(0)

        if self.nestListStack_[-1].getList()[self.idxStack_[-1]].isInteger():
            return True
        return False
