/*
 * created   : 2019-08-06 23:39:08
 * accepted  : 2019-08-07 11:40:36
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

const int N = 1e5 + 7;
vector<int> g[N];
vector<int> ans;

void dfs(int u, int pr) {
  int deg = 0;
  for (auto v : g[u]) {
    if (v != pr) {
      deg++;
      if (pr == -1 || deg == 1) {
        dfs(v, u);
      }
      else {
        cout << "No" << "\n";
        exit(0);
      }
    }
  }
  if (deg == 0) {
  // This is a leaf node.
    ans.push_back(u);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = -1;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x = (int) g[i].size();
    if (mx < x) {
      mx = x;
      root = i;
    }
  }
  dfs(root, -1);
  cout << "Yes" << "\n";
  int na = ans.size();
  cout << na << "\n";
  for (int j = 0; j < na; j++) {
    cout << root + 1 << " " << ans[j] + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
