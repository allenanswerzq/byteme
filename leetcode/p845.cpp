#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestMountain(vector<int>& inp) {
    int n = sz(inp);
    if (n < 3) return 0;
    int res = 0, l, r;
    fori (i, 1, n-1) {
      l = 0, k = i;
      while (k - 1 >= 0 && inp[k] > inp[k- 1]) {--k; ++l;}
      r = 0, k = i;
      while(k + 1 < n && inp[k] < inp[k + 1]) {++k; ++r;}
      if (l && r) res = max(res, l + r + 1);
    }
    return res;
  }
};

int main() {
  return 0;
}
