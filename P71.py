#!/usr/bin/env python

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stk = []
        for x in path.split('/'):
            if x=="..":
                if stk:
                    stk.pop()
            elif x and x!=".":
                stk.append(x)

        return '/' + '/'.join(stk)

if __name__ == "__main__":

