#include <bits/stdc++.h>
using namespace std;

// Brute force DFS.
// Got a TLE. 5 cases can't be passed.
const int size = 10000;
unordered_map<int, vi> g;
vi visit(size, 0);
void dfs(int start, int& sum, int path) {
  if (visit[start]) return;
  visit[start] = 1;
  fora (node, g[start]) {
    if (!visit[node]) {
      sum += path;
      // trace(start, node, path, sum);
      dfs(node, sum, path + 1);
    }
  }
}

class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vvi& edges) {
    vi res;
    g.clear();
    fora (e, edges) {
      g[e[0]].pb(e[1]);
      g[e[1]].pb(e[0]);
    }

    fori (i, 0, n) {
      int sum = 0;
      dfs(i, sum, 1);
      res.pb(sum);
      // trace(sum);
      visit.clear();
      visit.resize(size);
    }
    return res;
  }
};

int main() {
  return 0;
}
