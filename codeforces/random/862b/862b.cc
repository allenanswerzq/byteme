/*
 * creat   : 2019-07-16 16:04:03
 * accept  : 2019-07-16 17:00:05
 * author  : landcold7
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

const int N = 1e5 + 7;
vector<int> g[N];
ll cnt[2];

void dfs(int u, int col, int pr=-1) {
  cnt[col]++;
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, 1 - col, u);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, 0);
  cout << (ll) cnt[0] * cnt[1] - (n - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
