/* created   : 2020-11-15 08:57:42
 * accepted  : 2020-11-15 09:10:53
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

struct Dsu {
  vector<int> e;
  int n;

  Dsu(int n_): n(n_) {
    e.resize(n, -1);
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (-e[a] < -e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    n--;
  }
};

void solve() {
  int N, M; cin >> N >> M;
  Dsu dsu(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    dsu.join(u, v);
  }
  set<int> st;
  for (int i = 0; i < N; i++) {
    st.insert(dsu.find(i));
  }
  vector<int> v(all(st));
  trace(v);
  cout << v.size() - 1 << "\n";
  for (int i = 0; i + 1 < v.size(); i++) {
    cout << v[i] + 1 << " " << v[i + 1] + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
