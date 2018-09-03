#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& aa, int bb) {
  int n = sz(aa);
  vector<int> res;
  if (n == 0) return res;
  int lo = 0, hi = n - 1;
  while (lo < hi) {
  if (aa[lo] + aa[hi] == bb) {
  res.push_back(lo + 1);
  res.push_back(hi + 1);
  return res;
  } else if (aa[lo] + aa[hi] > bb) {
  --hi;
  } else {
  ++lo;
  }
  } 
  return res;
  }
};

