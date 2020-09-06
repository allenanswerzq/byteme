/* created   : 2020-09-06 11:44:30
 * accepted  : 2020-09-06 12:34:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

struct Dsu {
  vector<int> e;
  int n;

  Dsu(int n_) : n(n_) {
    e.resize(n, -1);
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (-e[a] < -e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
    n--;
    return true;
  }
};

// @Solution: Dsu + group knapsnack
void solve() {
  int N, M, W; cin >> N >> M >> W;
  vector<int> A(N);
  vector<int> B(N);
  for (auto& a : A) cin >> a;
  for (auto& b : B) cin >> b;
  Dsu dsu(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    dsu.join(u, v);
  }
  unordered_map<int, vector<int>> group;
  for (int i = 0; i < N; i++) {
    group[dsu.find(i)].push_back(i);
  }
  trace(group);
  for (const auto& it : group) {
    int sumw = 0;
    int sumb = 0;
    for (int k : it.second) {
      sumw += A[k];
      sumb += B[k];
    }
    if (it.second.size() > 1) {
      group[it.first].push_back(A.size());
      A.push_back(sumw);
      B.push_back(sumb);
    }
  }
  trace(group);
  assert(dsu.n == group.size());
  vector<int> f(W + 1);
  for (const auto& it : group) {
    for (int w = W; w >= 0; w--) {
      for (int k : it.second) {
        if (w - A[k] >= 0) {
          f[w] = max(f[w], f[w - A[k]] + B[k]);
        }
      }
    }
  }
  cout << *max_element(all(f)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
