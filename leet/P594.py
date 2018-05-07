#!/usr/bin/env python

import collections

def findLHS(x):
    """
    :type nums: List[int]
    :rtype: int
    """
    c = collections.Counter(x)
    # NOTE: or use method
    return max([c[x]+c[x+1] for x in c if x+1 in c] or [0])

if __name__ == "__main__":
    print(findLHS([1,3,2,2,5,2,3,7]))
