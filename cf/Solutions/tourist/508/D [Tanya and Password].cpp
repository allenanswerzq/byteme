/**
 *    author:  tourist
 *    created: 11.11.2017 22:04:39       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };

  vector<edge> edges;
  vector< vector<int> > g;
  int n;

  function<bool(int)> ignore;

  graph(int _n) : n(_n) {
    g.resize(n);
    ignore = nullptr;
  }

  virtual int add(int from, int to, T cost) = 0;

  virtual void set_ignore_edge_rule(const function<bool(int)> &f) {
    ignore = f;
  }

  virtual void reset_ignore_edge_rule() {
    ignore = nullptr;
  }
};

template <typename T>
class digraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
  using graph<T>::ignore;

  digraph(int _n) : graph<T>(_n) {
  }

  int add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  }

  digraph<T> reverse() {
    digraph<T> rev(n);
    for (auto &e : edges) {
      rev.add(e.to, e.from, e.cost);
    }
    if (ignore != nullptr) {
      rev.set_ignore_edge_rule([&](int id) {
        return ignore(id);
      });
    }
    return rev;
  }
};

template <typename T>
vector<int> find_eulerian_path_directed(const digraph<T> &g) {
  vector<int> in_deg(g.n, 0);
  vector<int> out_deg(g.n, 0);
  for (int id = 0; id < (int) g.edges.size(); id++) {
    if (g.ignore != nullptr && g.ignore(id)) {
      continue;
    }
    auto &e = g.edges[id];
    out_deg[e.from]++;
    in_deg[e.to]++;
  }
  int root = -1;
  int diff = 0;
  for (int i = 0; i < g.n; i++) {
    if (in_deg[i] < out_deg[i]) {
      diff += out_deg[i] - in_deg[i];
      root = i;
    }
  }
  if (diff > 1) {
    return vector<int>();
  }
  if (root == -1) {
    root = 0;
    while (root < g.n && out_deg[root] == 0) {
      root++;
    }
    if (root == g.n) {
      // but actually an empty path exists...
      return vector<int>();
    }
  }
  vector<int> ptr(g.n, 0);
  vector<int> res;
  function<void(int)> dfs = [&](int v) {
    while (ptr[v] < (int) g.g[v].size()) {
      int id = g.g[v][ptr[v]++];
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ v;
      dfs(to);
      res.push_back(id);
    }
  };
  dfs(root);
  if (res.size() != g.edges.size()) {
    return vector<int>();
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  const int ALPHA = 126;
  digraph<int> g(ALPHA * ALPHA);
  char foo[7];
  for (int i = 0; i < n; i++) {
    scanf("%s", foo);
    int x = (int) (foo[0] - ' ') * ALPHA + (int) (foo[1] - ' ');
    int y = (int) (foo[1] - ' ') * ALPHA + (int) (foo[2] - ' ');
    g.add(x, y);
  }
  vector<int> res = find_eulerian_path_directed(g);
  if (res.empty()) {
    puts("NO");
  } else {
    puts("YES");
    int start = g.edges[res[0]].from;
    putchar(start / ALPHA + ' ');
    putchar(start % ALPHA + ' ');
    for (int id : res) {
      int v = g.edges[id].to;
      putchar(v % ALPHA + ' ');
    }
    putchar('\n');
  }
  return 0;
}
