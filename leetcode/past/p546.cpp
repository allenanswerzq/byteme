#include <bits/stdc++.h>
using namespace std;
// Brute force approach.
// TLE.
unordered_map<string, int> mp;
int recu(string& inp) {
  int n, res;
  vi seg;

  // Simple memorization.
  if (mp.count(inp)) return mp[inp];

  n = sz(inp);
  seg.pb(-1);
  fori (i, 0, n) {
    while (i+1<n && inp[i] == inp[i+1]) ++i;
    seg.pb(i);
  }

  res = 0;
  fori (i, 1, sz(seg)) {
    int ans = 0;
    int r = seg[i] - seg[i-1];
    ans += r * r;
    string rem;
    rem += inp.substr(0, seg[i-1] + 1);
    rem += inp.substr(seg[i]+1);
    ans += recu(rem);
    res = max(ans, res);
  }

  mp[inp] = res;
  return res;
}

// TODO
class Solution {
public:
  int removeBoxesBruteForce(vector<int>& aa) {
    int n, lo, hi;
    string inp;
    n = sz(aa);
    fori (i, 0, n) inp += (aa[i] + '0');
    return recu(inp);
  }

  int removeBoxes(vi& aa) {
    return removeBoxesBruteForce(aa);
  }

};

void test(vi aa) {
  Solution go;
  int r = go.removeBoxes(aa);
  output(r);
}

int main() {
  test({1,3,2,2,2,3,4,3,1});
  return 0;
}

