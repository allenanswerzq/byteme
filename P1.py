#!/usr/bin/env python

def twoSum(a, target):
    m = {}
    for i in range(len(a)):
        if target - a[i] in m:
            return [i, m[target-a[i]]]
        else:
            m[ a[i] ] = i
    return []


if __name__ == "__main__":
    ret = twoSum([1, 2, 7, 8], 9)
    print "%d %d" %(ret[0], ret[1])
