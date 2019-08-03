/*
 * created   : 2019-07-27 23:07:16
 * accepted  : 2019-07-27 23:36:36
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  n *= 2;
  const int N = 1e6 + 7;
  vector<pair<int, int>> match(N);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      int x;
      cin >> x;
      match[x] = {i, j};
    }
  }
  vector<bool> was(1000);
  vector<int> ans(n + 1);
  for (int i = N - 1; i >= 1; --i) {
    int x = match[i].x;
    int y = match[i].y;
    if (!was[x] && !was[y]) {
      was[x] = 1;
      was[y] = 1;
      ans[x] = y;
      ans[y] = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
