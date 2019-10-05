/*
 * Name        : c
 * Creat       : Thu Jul 11 21:47:30 CST 2019
 * Accept      : Thu Jul 11 22:11:07 CST 2019
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
  int l, r;
  cin >> l >> r;
  int x = (l - 1) / 2019;
  int y = r / 2019;
  if (y > x) {
    cout << 0 << "\n";
    return;
  }
  int ans = (1 << 30);
  for (int i = l; i <= r; ++i) {
    for (int j = i + 1; j <= r; ++j) {
      int t = (i * 1ll * j) % 2019;
      ans = min(ans, t);
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
