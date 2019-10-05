/*
 * Name        : 413b
 * Creat       : Thu Jul 11 15:19:25 CST 2019
 * Accept      : Thu Jul 11 15:45:02 CST 2019
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  trace(g);
  vector<int> chat(m);
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    chat[y]++;
    dp[x][y]++;
  }
  trace(chat, dp);
  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i][j] == 1) {
        ans[i][j] = chat[j] - dp[i][j];
      }
    }
  }
  trace(ans);
  for (int i = 0; i < n; ++i) {
    ll ret = accumulate(ans[i].begin(), ans[i].end(), 0ll);
    cout << ret << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
