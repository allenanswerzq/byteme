#!/usr/bin/env python

def arrayPairSum(nums):
    return sum(sorted(nums)[::2])

if __name__ == "__main__":
    print "Max Sum: %d" % arrayPairSum([1, 4, 3, 2, 6, 5])
