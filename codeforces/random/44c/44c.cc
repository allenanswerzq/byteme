/*
 * Name        : 44c
 * Creat       : Thu Jul 11 15:52:13 CST 2019
 * Accept      : Thu Jul 11 15:55:36 CST 2019
 * Author      : landcold7
 * Description : Action speaks louder more than words
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
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j <= y; ++j) {
      cnt[j]++;
    }
  }
  trace(cnt);
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > 1 || cnt[i] == 0) {
      cout << i << " " << cnt[i] << "\n";
      return;
    }
  }
  cout << "OK" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
