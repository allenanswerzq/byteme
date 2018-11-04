#include<bits/stdc++.h>
using namespace std;

// Falied 
vector<int> asteroidCollision(vector<int>& asts) {
  vector<int> stk;
  vector<int> ret;
  for (auto x : asts) {
  if (x > 0) 
    stk.push_back(x);
  else if (stk.empty()) {
    ret.push_back(x);
  } else {
    while (!stk.empty() && x<0) {
    int t = stk.back(); stk.pop_back();
    x = abs(x)>t ? x:t; 
    if (x>0) stk.push_back(x);
    }
  } 
  }
  for (auto x : stk)
  ret.push_back(x);
  return ret;
}

// This one is correct
vector<int> asteroidCollision(vector<int>& asts) {
  vector<int> stk;
  for (auto x: asts) {
  if (x > 0)
    stk.push_back(x);
  else {
    bool flag = false; 
    while (stk.size() && stk.back() > 0) {
    int t = abs(a.back()), w = abs(x);
    if (t == w) {
      stk.pop_back();
      flag = true;
      break;
    } else if (t > w) {
      flag = true; 
      break;
    } else {
      stk.pop_back(); 
    }
    }
    if (flag == false) stk.push_back(x);
  } 
  }
  return stk;
}
