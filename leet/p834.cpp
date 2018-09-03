#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int N = 1e4 + 10;
vector<int> graph[N];
int num_nodes[N]; // The number of child nodes for root i.
int dist[N];      // The sum of the distance from root i to it's all children. 

void dfs(int u, int parent) {
  num_nodes[u] = 1;
  dist[u] = 0;
  fora(v, graph[u]) {
  if (v == parent) continue;
  dfs(v, u);
  num_nodes[u] += num_nodes[v];
  dist[u] += num_nodes[v] + dist[v];
  }
}

void dfs2(int u, int parent, int n, vi &res) {
  fora(v, graph[u]) {
  if (v == parent) continue; 
  // When root node changed from u to v, The distance of `num_nodes[v]` nodes
  // will be decreased by 1, and the distance of `n - num_nodes[v]` nodes will
  // be increased by 1.
  res[v] = res[u] - num_nodes[v] + (n - num_nodes[v]);
  dfs2(v, u, n, res);
  }
}

// TODO
class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    // Reset.
    mst(num_nodes, 0);
    mst(dist, 0);
    fori(i, 0, N)
    graph[i].clear();

    fora(e, edges) {
    int src = e[0];
    int dst = e[1];
    graph[src].pb(dst);
    graph[dst].pb(src);
    }

    dfs(0, -1);
    vi res(n, 0);
    res[0] = dist[0];
    dfs2(0, -1, n, res);
    return res;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);

  Solution go;
  vvi edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
  vi r = go.sumOfDistancesInTree(6, edges);
  pvi(r);
  // vvi edges = {{0,2}, {2,1}};
  // go.sumOfDistancesInTree(3, edges);
  return 0;
}
