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
  int n, m;
  cin >> n >> m;
  dsu ds(n);
  vector<int> deg(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    ds.join(x, y);
    deg[y]++;
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    g[ds.find(i)].push_back(i);
  }
  trace(g);
  ll ans = 0;
  for (auto t : g) {
    int cnt = 0;
    for (auto x : t) {
      if (deg[x] == 0) {
        cnt++;
      }
    }
    ans += cnt;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
