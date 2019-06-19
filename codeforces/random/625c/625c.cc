//=============================================================
// Name        : 625c
// Date        : Tue Jun 18 16:55:30 CST 2019
// Accepted    : Tue Jun 18 17:00:17 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  int x = n * n;
  k--;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= k; --j) {
      a[i][j] = x--;
    }
  }
  trace(a);
  for (int i = 0; i < n; ++i) {
    for (int j = k - 1; j >= 0; --j) {
      a[i][j] = x--;
    }
  }
  trace(a);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i][k];
  }
  cout << sum << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << (j == n - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
