#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calculate(string ss) {
    stack<int> stk;
    int sign = 1, res = 0;
    for (int i = 0; i < ss.size(); ++i) {
      if (ss[i] >= '0') {
        int num = 0;
        while (i < ss.size() && ss[i] >= '0')
          num = num*10 + ss[i++]-'0';
        --i;
        res += sign * num;
      }
      else if (ss[i] == '+') sign = 1;
      else if (ss[i] == '-') sign = -1; 
      else if (ss[i] == '(') {
        stk.push(res);
        stk.push(sign);
        res = 0;
        sign = 1;
      } else if (ss[i] == ')') {
        int ss = stk.top(); stk.pop();
        int t = stk.top(); stk.pop();
        res = t + ss * res;
      }
    }
    return res;
  }
};
