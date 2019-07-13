//=============================================================
// Name        : d
// Date        : Mon Jun 10 14:10:24 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      int op = i + j;
      if (op <= m && op <= n) {
        ll tmp = 0;
        vector<int> b;
        for (int k = 0; k < i; ++k) {
          b.push_back(a[k]);
          tmp += a[k];
        }
        for (int k = n - j; k < n; ++k) {
          b.push_back(a[k]);
          tmp += a[k];
        }
        trace(b, tmp, op);
        sort(b.begin(), b.end());
        for (int k = 0; k < sz(b) && op < m; ++k) {
          if (b[k] < 0) {
            op++;
            tmp -= b[k];
          } else {
            break;
          }
        }
        ans = max(ans, tmp);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
