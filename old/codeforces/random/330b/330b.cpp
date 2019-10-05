//=============================================================
// Name        : 330b
// Date        : Wed Jun  5 17:17:02 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
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
  vector<bool> was(n + 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    was[x] = 1;
    was[y] = 1;
  }
  int root = -1;
  for (int i = 1; i <= n; ++i) {
    if (!was[i]) {
      root = i;
      break;
    }
  }
  assert(root != -1);
  vector<pair<int, int>> ret;
  for (int i = 1; i <= n; ++i) {
    if (root != i) {
      ret.emplace_back(root, i);
    }
  }
  cout << sz(ret) << "\n";
  for (int i = 0; i < sz(ret); ++i) {
    cout << ret[i].x << " " << ret[i].y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
