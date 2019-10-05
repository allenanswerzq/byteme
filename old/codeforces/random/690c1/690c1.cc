/* created   : 2019-08-21 17:33:40
 * accepted  : 2019-08-21 17:37:36
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
  vector<set<int>> g(n);
  dsu d(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].insert(y);
    d.join(x, y);
  }
  int e = 0;
  for (int i = 0; i < n; i++) {
    e += g[i].size();
  }
  cout << (e == n - 1 && d.n == 1 ? "yes" : "no") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
