#!/usr/bin/env python

class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board: return
        m, n = len(board), len(board[0])

        # save all border postion
        border = [ij for k in range(n) for ij in ((0,k), (m-1,k))]
        border += [ij for k in range(1, m-1) for ij in ((k,0), (k,n-1))] 

        while border:
            i, j = border.pop()
            if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
                board[i][j] = 'S'
                # check weather current postion's 
                # all neighbors equals O or not
                border += ((i,j-1), (i, j+1), (i-1, j), (i+1,j)) 

        for row in board:
            for i, c in enumerate(row):
                row[i] = 'XO'[c == 'S']
