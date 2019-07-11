//=============================================================
// Name        : 1090a
// Date        : Sat Jul  6 09:24:10 CST 2019
// Accepted    : Sat Jul  6 09:31:41 CST 2019
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
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      mx = max(mx, x);
      a[i].push_back(x);
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int tx = *max_element(a[i].begin(), a[i].end());
    if (tx < mx) {
      ans += sz(a[i]) * 1ll * (mx - tx);
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
