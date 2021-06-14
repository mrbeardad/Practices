#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def calculate(self, s: str) -> int:
        return eval(s.replace('/', '//'))
        #  stackOP, stackNum = [], []
        #  idx = len(s) - 1
        #  while idx >= 0:
        #      char = s[idx]
        #      if char in '+-*/':
        #          stackOP.append(char)
        #      elif char.isnumeric():
        #          num, times = 0, 1
        #          while idx >= 0 and s[idx].isnumeric():
        #              num = num + int(s[idx]) * times
        #              times *= 10
        #              idx -= 1
        #          stackNum.append(num)
        #          continue
        #      idx -= 1
        #
        #  while stackOP:
        #      num1, op = stackNum[-1], stackOP[-1]
        #      stackNum.pop()
        #      stackOP.pop()
        #      if op in '-+':
        #          while stackOP and stackOP[-1] in '*/':
        #              lhs, rhs = stackNum[-1], stackNum[-2]
        #              seniorOP = '*' if stackOP[-1] == '*' else '//'
        #              stackOP.pop()
        #              stackNum[-2:] = [eval('lhs' + seniorOP + 'rhs')]
        #          stackNum[-1] = eval('num1' + op + 'stackNum[-1]')
        #      else:
        #          op = '*' if op == '*' else '//'
        #          stackNum[-1] = eval('num1' + op + 'stackNum[-1]')
        #
        #  return stackNum[0]


print(Solution().calculate(input()))
