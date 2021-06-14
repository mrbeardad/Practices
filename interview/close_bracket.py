#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for char in s:
            if char == ')':
                if stack and stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            elif char == ']':
                if stack and stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            elif char == '}':
                if stack and stack[-1] == '{':
                    stack.pop()
                else:
                    return False
            elif char in '([{':
                stack.append(char)
            else:
                return False
        if not stack:
            return True
        else:
            return False

print(Solution().isValid(input()))
