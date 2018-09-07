#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shortestPalindrome(string ss) {
    string ret = "";
    for (auto c : ss) ret = c + ret;
    for (int i = 0; i < ret.size(); ++i) {
      string front = ret.substr(0, i);
      string rest = ret.substr(i); 
      if (ss.substr(0, rest.size()) == rest)
        return front + ss;
    }
    return "";
  }
};