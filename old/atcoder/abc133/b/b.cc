/*
 * Name        : b
 * Creat       : Thu Jul 11 21:43:16 CST 2019
 * Accept      : Thu Jul 11 21:46:04 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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
  int n, d;
  cin >> n >> d;
  vector<vector<int>> a(n, vector<int>(d));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int s = 0;
      for (int k = 0; k < d; ++k) {
        int v = abs(a[i][k] - a[j][k]);
        s += v * v;
      }
      int x = floor(sqrt(s));
      if (x * x == s) {
        ans++;
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
