/* created   : 2019-09-05 22:51:47
 * accepted  : 2019-09-05 23:11:48
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

const int N = 123;

struct dsu {
  int n;
  vector<int> e;

  dsu(int _n) : n(_n), e(n, -1) {
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
    n--;
    return true;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> g(m + 1);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    cnt += (k == 0);
    for (int j = 0; j < k; j++) {
      int x; cin >> x;
      g[x].push_back(i);
    }
  }
  if (cnt == n) {
    cout << n << '\n';
    return;
  }
  dsu d(n);
  for (int i = 1; i <= m; i++) {
    if (!g[i].empty()) {
      int u = g[i][0];
      for (int j = 1; j < (int) g[i].size(); j++) {
        int v = g[i][j];
        d.join(u, v);
      }
    }
  }
  cout << d.n - 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
