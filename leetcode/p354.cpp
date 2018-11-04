#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxEnvelopes(vector<pair<int, int>>& aa) {
    int n, res;
    n = sz(aa);
    if (n == 0) return 0;

    sort(all(aa));

    int dp[n];
    mst(dp, 0);
    dp[0] = 1;
    res = 1;

    fori (i, 1, n) {
      pii cur = aa[i];
      int ok = 0;
      fori (j, 0, i) {
        pii pre = aa[j];
        if (cur.fi > pre.fi && cur.se > pre.se) {
          dp[i] = max(dp[j] + 1, dp[i]);
          ok = 1;
        }
      }
      if (ok == 0)
      dp[i] = 1;
      res = max(res, dp[i]);
    }

    return res;
  }
};

int test(vector<pii> aa) {
  Solution go;
  int x = go.maxEnvelopes(aa);
  cout << x << "\n";
  return x;
}

int main() {
  test({{5,4}, {6,4}, {6,7}, {2,3}});
  return 0;
}
