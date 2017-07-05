#!/usr/bin/env python

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def node(val, left, right):
            node = TreeNode(node)
            node.left = left
            node.right = right
            return node

        def trees(start, end):
            return [node(x, left, right)
                    for x in range(start, end+1)
                    for left in trees(start, x-1)
                    for right in trees(x+1, end)]
    return trees(1, n)

        
if __name__ == "__main__":

