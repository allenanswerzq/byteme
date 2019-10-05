//=============================================================
// Name        : 796b
// Date        : Sun Jun  9 10:26:58 CST 2019
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> hole(n + 1);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    hole[x] = 1;
  }
  int cur = 1;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    trace(i, cur);
    if (hole[cur]) {
      break;
    }
    if (cur == x) {
      cur = y;
    } else if (cur == y) {
      cur = x;
    }
  }
  cout << cur << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
