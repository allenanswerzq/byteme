/* created   : 2020-11-21 12:38:25
 * accepted  : 2020-11-21 12:45:53
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Dsu {
  vector<int> e;
  set<int> st;
  int n;

  Dsu(int n_) : n(n_) {
    e.resize(n, -1);
  }

  int find(int u) {
    return e[u] < 0 ? u : e[u] = find(e[u]);
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return;
    }
    if (-e[a] < -e[b]) swap(a, b);
    st.erase(-e[b]);
    e[a] += e[b];
    e[b] = a;
    st.insert(-e[a]);
    n--;
  }
};

void solve() {
  int N, M; cin >> N >> M;
  Dsu dsu(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    dsu.unite(u, v);
    cout << dsu.n << " " << *dsu.st.rbegin() << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
