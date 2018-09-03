#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// TODO
const int size = 12;
// dp[i][j] i stands for visiting states and j stands for
// ending at node j.
int dp[1 << size][size];  

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& g) {
  int n = sz(g);
  mst(dp, 0x7f);
  deque<pii> q; 

  fori(i, 0, n) {
  // Only node i visited and the stopping node is i.
  dp[1<<i][i] = 0; 
  q.eb(1<<i, i);
  } 

  while (sz(q)) {
  auto cur = q.front(); q.ppf();
  int state = cur.fi;
  int start = cur.se;
  // cout << state << " " << start << endl;
  fora(node, g[start]) {
  // Add this node as a visited node.
  int new_state = state | (1 << node); 
  if (dp[new_state][node] > dp[state][start] + 1) {
    dp[new_state][node] = dp[state][start] + 1;
    q.eb(new_state, node);
  }
  }      
  }
  
  int ret = inf; 
  fori(i, 0, n)
  ret = min(ret, dp[(1<<n) - 1][i]);
  return ret;
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vector<int> v;
  v.emplace_back(4);
  // v.emplace(5);
  deque<int> dq;
  dq.emplace_back(4);
  // dq.emplace(3);
  queue<int> qu;
  // qu.emplace(3);
  return 0;
}
