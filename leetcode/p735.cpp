#include<bits/stdc++.h>
using namespace std;

vi asteroidCollision(vi& asts) {
  vi stk;
  for (auto x: asts) {
    if (x > 0) stk.push_back(x);
    else {
      bool flag = 0;
      while (stk.size() && stk.back() > 0) {
        int t = abs(a.back()), w = abs(x);
        if (t == w) {
          stk.pop_back();
          flag = 1;
          break;
        } else if (t > w) {
          flag = 1;
          break;
        } else {
          stk.pop_back();
        }
      }
      if (flag == 0) stk.push_back(x);
    }
  }
  return stk;
}
