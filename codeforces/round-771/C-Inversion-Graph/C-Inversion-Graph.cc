/* created   : 2022-03-15 21:40:26
 * accepted  : 2022-03-15 22:52:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

struct Dsu {
  int n;
  int m;
  int gid;
  vector<int> e;
  vector<int> root_hash;
  vector<int> gid_hash;

  Dsu(int n_) : n(n_) {
    m = n;
    gid = 0;
    e.resize(n, -1);
    root_hash.resize(n, -1);
    gid_hash.resize(n, -1);
  }

  int size(int x) { return -e[find(x)]; }

  int find_rec(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

  int find(int u) {
    int root = u;
    while (e[root] >= 0) {
      root = e[root];
    }
    while (u != root) {
      int t = e[u];
      e[u] = root;
      u = t;
    }
    return root;
  }

  bool same(int a, int b) { return find(a) == find(b); }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (-e[a] < -e[b]) {
      swap(a, b);
    }
    // the tree with fewer nodes been added.
    e[a] += e[b];
    e[b] = a;
    m--;
    return true;
  }

  // Given a gid, finds the root of that group
  int get_groot(int ix) {
    assert(0 <= ix && ix < n);
    assert(root_hash[ix] != -1);
    return root_hash[ix];
  }

  // Given a root, finds the gid.
  int get_gid(int root) {
    assert(0 <= root && root < n);
    if (gid_hash[root] == -1) {
      gid_hash[root] = gid;
      root_hash[gid] = root;
      gid++;
    }
    return gid_hash[root];
  }

  vector<vector<int>> groups() {
    vector<vector<int>> ret(m);
    // Note: zero index based.
    for (int i = 0; i < n; i++) {
      int root = find(i);
      ret[get_gid(root)].push_back(i);
    }
    return ret;
  }
};

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  trace(A);
  Dsu dsu(N);
  set<int> st;
  // 6 5 4 3 2 1
  for (int i = N - 1; i >= 0; i--) {
    auto it = st.lower_bound(A[i]);
    trace(i, A[i], st);
    while (st.size() && it != st.begin()) {
      int x = *--it;
      dsu.join(A[i], x);
    }
    // NOTE: erase everything smaller than A[i], because
    // we already connect them together.
    st.erase(st.begin(), it);
    st.insert(A[i]);
  }
  cout << dsu.m << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
