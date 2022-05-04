/* created   : 2022-05-04 21:45:56
 * accepted  : 2022-05-04 21:45:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  using ll = long long;
  void amax(ll & a, ll b) { a = max(a, b); }

  // the max profits spent the first i days used the k txns
  // f[i][k] = max(f[j-1][k-1] - a[j] + a[i], f[i-1][k]) j < i
  int maxProfit(int K, vector<int>& P) {
    int n = P.size();
    vector<vector<ll>> f(n + 1, vector<ll>(K + 1));
    for (int k = 1; k <= K; k++) {
      ll mx = -1e18;
      for (int i = 0; i < n; i++) {
        amax(f[i+1][k], f[i][k]);
        amax(f[i+1][k], mx + P[i]);
        mx = max(mx, f[i][k-1] - P[i]);
      }
    }
    // trace(f);
    return *max_element(f[n].begin(), f[n].end());
  }
};
