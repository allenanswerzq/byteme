#include<bits/stdc++.h>
using namespace std;

// ref: https://discuss.leetcode.com/topic/19894/1-11-lines-python-9-lines-c/2
vector<int> diffWaysToCompute(string aa) {
  vector<int> output; 
  for (int i=0; i < aa.size(); ++i) {
  char c = aa[i];
  if (c=='+' || c=='-' || c=='*')
  for (auto a : diffWaysToCompute(aa.substr(0, i)))
  for (auto b : diffWaysToCompute(aa.substr(i+1)))
    output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
  } 
  return output.size() ? output : vector<int>{stoi(aa)};
}
