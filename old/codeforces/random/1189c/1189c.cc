/*
 * created   : 2019-07-21 10:02:27
 * accepted  : 2019-07-21 14:40:52
 * author    : landcold7
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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<pair<int, int>>> dp(20);
  for (int i = 0; i < n; ++i) {
    dp[0].emplace_back(a[i], 0);
  }
  int len = 1;
  for (int depth = 1; depth < 20; depth++) {
    len *= 2;
    for (int i = 0; i + len <= n; ++i) {
      int x = dp[depth - 1][i].x;
      int y = dp[depth - 1][i + len / 2].x;
      int z = dp[depth - 1][i].y;
      int g = dp[depth - 1][i + len / 2].y;
      z = z + g;
      if (x + y >= 10) {
        z++;
      }
      dp[depth].emplace_back((x + y) % 10, z);
    }
  }
  trace(dp);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    int z = (y - x + 1);
    int t = 1;
    int p = 0;
    while (t < z) {
      p++;
      t <<= 1;
    }
    cout << dp[p][x - 1].y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
