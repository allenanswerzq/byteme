#!/usr/bin/env python

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # more shorter or cleaner solu
    def addTwoNumber(self, a, b):
        ret = ListNode(-1)
        ans = ret  # remeber linklist head
        s = 0
        while a or b:
            s /= 10     # got carry
            if a:
                s += a.val
                a = a.next
            if b:
                s += b.val
                b = b.next
            ret.next = ListNode( s % 10 )
            ret = ret.next

        if s / 10:
            ret.next = ListNode(1)

        return ans.next

    ### Accepted
    def addTwoNumber1(self, a, b):
        ret = ListNode(-1)
        ans = ret  # remeber linklist head
        c = 0
        while a and b:
            s = a.val + b.val + c 
            c = s / 10
            t = s % 10
            ret.next = ListNode(t)
            ret = ret.next
            # print ret.val
            a = a.next
            b = b.next

        while a:
            s = a.val + c
            c = s / 10
            t = s % 10
            ret.next = ListNode(t)
            ret = ret.next
            a = a.next

        while b:
            s = b.val + c
            c = s / 10
            t = s % 10
            ret.next = ListNode(t)
            ret = ret.next
            b = b.next

        # NOTE: c may be equal 1
        # that's a point I easily forget 
        if c:
            ret.next = ListNode(1)

        return ans.next


if __name__ == "__main__":
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)
    # ans = l1
    # while ans:
    #     print ans.val
    #     ans = ans.next

    l2 = ListNode(5)
    l2.next = ListNode(6)
    # ans = l2
    # while ans:
    #     print ans.val
    #     ans = ans.next

    s = Solution()
    ans = s.addTwoNumber(l1, l2)
    while ans:
        print ans.val
        ans = ans.next
    
