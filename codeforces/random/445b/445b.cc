/* created   : 2019-09-16 00:20:16
 * accepted  : 2019-09-16 01:55:30
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

struct dsu {
  int n;
  vector<int> e;

  dsu(int _n) : n(_n), e(n, -1) {
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : find(e[x]);
  }

  bool join(int u, int v) {
    int x = find(u);
    int y = find(v);
    if (x == y) {
      return false;
    }
    if (e[x] > e[y]) {
      swap(x, y);
    }
    e[x] += e[y];
    e[y] = x;
    n--;
    return true;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  dsu ds(n);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    ds.join(x, y);
  }
  cout << (1ll << (n - ds.n)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
