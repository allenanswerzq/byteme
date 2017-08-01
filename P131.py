#!/usr/bin/env python

class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        # Idea: front + partition(back)
        # front + back = entire s
        return [[s[:i]] + rest
                for i in range(1, len(s)+1)
                if s[:i] == s[i-1::-1]
                for rest in self.partition(s[i:])] or [[]]
