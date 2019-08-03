/*
 * Creat   : Sun Jul 14 15:14:03 CST 2019
 * Accept  : Sun Jul 14 16:34:32 CST 2019
 * Author  : landcold7
 */
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
  vector<vector<ll>> a(n, vector<ll>(n));
  int x = 0, y = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        x = i, y = j;
      }
    }
  }
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  int p = (x == 0 ? 1 : 0);
  ll sum = accumulate(a[p].begin(), a[p].end(), 0ll);
  a[x][y] = sum - accumulate(a[x].begin(), a[x].end(), 0ll);
  if (a[x][y] <= 0) {
    cout << -1 << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    ll r = 0;
    for (int j = 0; j < n; ++j) {
      r += a[i][j];
    }
    if (sum != r) {
      cout << -1 << "\n";
      return;
    }
    ll c = 0;
    for (int j = 0; j < n; ++j) {
      c += a[j][i];
    }
    if (sum != c) {
      cout << -1 << "\n";
      return;
    }
  }
  ll dig = 0;
  for (int i = 0; i < n; ++i) {
    dig += a[i][i];
  }
  if (dig != sum) {
    cout << -1 << "\n";
    return;
  }
  dig = 0;
  for (int i = 0; i < n; ++i) {
    dig += a[i][n - 1 - i];
  }
  if (dig != sum) {
    cout << -1 << "\n";
    return;
  }
  cout << a[x][y] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
