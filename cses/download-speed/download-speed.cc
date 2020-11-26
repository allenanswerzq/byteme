/* created   : 2020-11-25 15:37:08
 * accepted  : 2020-11-25 20:12:01
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

template <class T>
class DinicFlow {
 public:
  DinicFlow(int n, int s, int t) : n_(n), src_(s), dst_(t) {
    g_.resize(n_);
    d_.resize(n_);
    cnt_.resize(n_);
  }

  void add(int u, int v, int forward_cap, int backward_cap = 0) {
    int su = g_[u].size();
    int sv = g_[v].size();
    g_[u].push_back(Edge{v, forward_cap, 0, sv});
    g_[v].push_back(Edge{u, backward_cap, 0, su});
  }

  T max_flow() {
    T flow = 0;
    while (level_graph()) {
      fill(cnt_.begin(), cnt_.end(), 0);
      while (true) {
        T f = dfs(src_, numeric_limits<T>::max());
        if (f == 0) break;
        flow += f;
      }
    }
    return flow;
  }

  vector<bool> min_cut() {
    max_flow();
    vector<bool> ans(n_);
    for (int i = 0; i < n_; i++) {
      ans[i] = (d_[i] != -1);
    }
    return ans;
  }

 private:
  T dfs(int u, T w) {
    if (u == dst_) {
      return w;
    }
    for (int& i = cnt_[u]; i < (int)g_[u].size(); i++) {
      Edge& e = g_[u][i];
      if (e.c > e.f && d_[e.v] == d_[u] + 1) {
        T t = dfs(e.v, min(e.c - e.f, w));
        if (t > 0) {
          e.f += t;
          g_[e.v][e.rev].f -= t;
          return t;
        }
      }
    }
    return 0;
  }

  bool level_graph() {
    deque<int> qu;
    qu.push_back(src_);
    fill(d_.begin(), d_.end(), -1);
    d_[src_] = 0;
    while (qu.size()) {
      int u = qu.front();
      qu.pop_front();
      for (Edge& e : g_[u]) {
        if (e.c > e.f && d_[e.v] == -1) {
          d_[e.v] = d_[u] + 1;
          if (e.v == dst_) {
            return true;
          }
          qu.push_back(e.v);
        }
      }
    }
    return false;
  }

  struct Edge {
    int v;
    T c;
    T f;
    int rev;  // The reverse edge position.
    friend ostream& operator<<(ostream& os, const Edge& e) {
      return os << "(" << e.v << ", " << e.c << ", " << e.f << ", " << e.rev
                << ")";
    }
  };

  int n_;
  int src_;
  int dst_;
  vector<int> d_;
  vector<int> cnt_;
  vector<vector<Edge>> g_;
};

void solve() {
  int N, M;
  cin >> N >> M;
  DinicFlow<ll> df(N, 0, N - 1);
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    df.add(u, v, c);
  }
  cout << df.max_flow() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
