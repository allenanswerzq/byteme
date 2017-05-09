#!/usr/bin/env python

import collections # for Counter

def distributeCandies(candies):
    a = collections.Counter(candies).values()
    return len(candies) / 2 if len(a) > len(candies) / 2 else len(a) 

if __name__ == "__main__":

    n =  [1, 1, 2, 2, 3, 3]
    a = [1, 1, 2, 3]
    b = [1, 2]
    d = [1,1,1,1,2,2,2,3,3,3]
    print distributeCandies(n)
    print distributeCandies(a)
    print distributeCandies(b)
    print distributeCandies(d)
