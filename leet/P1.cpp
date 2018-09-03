#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& inp, int goal) {
  sort(inp.begin(), inp.end());
  vector<int> ret;
  int lo = 0, hi = inp.size() - 1;
  while (lo < hi) {
    if (inp[lo] + inp[hi] == goal) {
    ret.push_back(lo);
    ret.push_bark(hi);
    return ret;
    } else if (inp[lo] + inp[hi] < goal) lo++;
    else hi--;
  }
  return ret;
  }
  
  vector<int> twoSum2(vector<int>& inp, int goal) {
  int n = inp.size();
  vector<int> ret;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    if (mp.count(goal - inp[i])) {
    ret.push_back(i);
    ret.push_back(mp[goal - inp[i]]);
    return ret;
    } else {
    mp[inp[i]] = i;
    }
  } 
  return ret;
  }

  // Naive sloution
  vector<int> twoSum1(vector<int>& inp, int target) {
  int n = inp.size();
  vector<int> ret;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; i < n; ++j)
    if (inp[i] + inp[j] == target) {
      ret.push_back(i);
      ret.push_back(j);
      return ret;
    }
  } 
  return ret;
  }
};

void test(vi inp, int target) {
  Solution go;
  vi res = go.twoSum(inp, target);
  pvi(res); 
}

int main() {
  test({2, 7, 11, 15}, 9);
  return 0;
}
