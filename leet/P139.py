#!/usr/bin/env python


class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        ok = [True]
        for i in range(1, len(s)+1):
            # Note: comma at the end of line
            # and any how to use any method
            ok += any(ok[j] and s[j:i] in wordDict for j in range(i)),
        return ok[-1]


