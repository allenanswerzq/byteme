#!/usr/bin/env python

# Accepted
# divide and conquer approach
class Solution(object):
    def largestRectangleArea(self, A):
        """
        :type heights: List[int]
        :rtype: int
        """
        if len(A) == 0:
            return 0
        if len(A) == 1:
            return A[0]
        n = len(A)
        m1 = self.largestRectangleArea(A[0:n/2])
        m2 = self.largestRectangleArea(A[n/2:])
        # NOTE: expanding from the middle two bars to find a maximum area 
        i, j = n/2-1, n/2
        m3, h = 0, min(A[i], A[j]) 
        while i>=0 and j<=n-1:
            h = min(h, A[i], A[j])
            m3 = max(m3, (j-i+1) * h)
            if i == 0:
                j += 1
            elif j == n-1:
                i -= 1
            else:
                if A[i-1] > A[j+1]:
                    i -= 1
                else:
                    j += 1
        return max(m1, m2, m3)
if __name__ == "__main__":

