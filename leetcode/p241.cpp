#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  // ref: https://discuss.leetcode.com/topic/19894/1-11-lines-python-9-lines-c/2
  vector<int> diffWaysToCompute(string aa) {
    vector<int> ret; 
    for (int i = 0; i < aa.size(); ++i) {
      char op = aa[i];
      if (op == '+' || op == '-' || op == '*')
        for (auto a : diffWaysToCompute(aa.substr(0, i)))
          for (auto b : diffWaysToCompute(aa.substr(i + 1)))
            ret.push_back(op == '+' ? a + b : op == '-' ? a - b : a * b);
    } 
    return ret.size() ? ret : vector<int>{stoi(aa)};
  }
};
