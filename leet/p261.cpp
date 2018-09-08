#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
// write a function to check whether these edges make up a valid tree.
// Example
// Given n = 5 and edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}}, return true.
// Given n = 5 and edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}, return false.
// Note
// You can assume that no duplicate edges will appear in edges. 
// Since all edges are undirected, {0, 1} is the same as {1, 0} and thus will not appear together in edges.
// Tags Expand 
// Depth First Search Breadth First Search Union Find Facebook Zenefits Google

vvi gg;
vi visit;

bool dfs(int root, int pre) {
  if (visit[root]) return 0;
  visit[root] = 1;
  fora(e, gg[root]) {
    if (e == pre) continue;
    if (!dfs(e, root)) return 0;
  }
  return 1;
}

class Solution {
public:
  bool validTree(int n, vpii& edges) {
    gg.resize(n);
    visit.resize(n);
    fora (e, edges) {
      gg[e.fi].pb(e.se);
      gg[e.se].pb(e.fi);
    }

    fora (g, gg) {
      pvi(g);
    }

    // If there exist cycle.
    if (!dfs(0, -1)) 
      return 0;

    // Graph must be connected. 
    fora (v, visit)
      if (v == 0) 
        return 0;

    return 1;
  }
};

int find(vi& root, int ix) {
  while (root[ix] != -1) 
    ix = root[ix];
  return ix;
}

class Solution {
public:
  // Union find approach.
  bool validTree(int n, vpii& edges) {
  vi root(n, -1);
  fora (e, edges) {
    int x = find(root, e.fi);
    int y = find(root, e.se);
    if (x == y) return 0; 
    // Union two node together.
    root[x] = y;
  }
  return sz(edges) == n - 1;
  }
};

int main() {
  Solution go;
  vpii aa = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  int res = go.validTree(5, aa);
  cout << res << endl;
  
  aa = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  res = go.validTree(5, aa); 
  cout << res << endl;
  return 0;
}
