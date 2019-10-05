/*
 * Name        : 48b
 * Creat       : Thu Jul 11 09:58:47 CST 2019
 * Accept      : Thu Jul 11 10:42:20 CST 2019
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
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  auto get = [&](int h, int w) {
    int ans = (1 << 30);
    for (int i = 0; i + h <= n; ++i) {
      for (int j = 0; j + w <= m; ++j) {
        int cur = 0;
        for (int x = 0; x < h; ++x) {
          for (int y = 0; y < w; ++y) {
            cur += g[i + x][j + y];
          }
        }
        ans = min(ans, cur);
      }
    }
    return ans;
  };
  int a, b;
  cin >> a >> b;
  int ans = get(a, b);
  ans = min(ans, get(b, a));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
