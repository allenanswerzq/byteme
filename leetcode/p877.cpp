#include<bits/stdc++.h>
using namespace std;

bool dfs(vi& aa, int lo, int hi, int sum, int path) {
  if (lo == hi) {
  if (path > sum - path) return 1;
    return 0;
  }

  if (dfs(aa, lo, hi-1, sum, path + aa[hi]))
    return 1;

  if (dfs(aa, lo + 1, hi, sum, path + aa[lo]))
    return 1;

  return 0;
}

class Solution {
public:
  bool stoneGame(vector<int>& aa) {
    int n = sz(aa);
    int sum = accumulate(all(aa), 0);
    return dfs(aa, 0, n - 1, sum, 0);
  }
};


int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  
  return 0;
}
