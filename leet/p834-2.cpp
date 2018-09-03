#include<bits/stdc++.h>
using namespace std;




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

const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 
  return 0;
}
