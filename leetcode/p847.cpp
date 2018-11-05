#include <bits/stdc++.h>
using namespace std;

// TODO
// dp[i][j] i stands for visiting states and j stands for
// ending at node j.
const int size = 12;
int dp[1 << size][size];

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& g) {
    int n = sz(g);
    mst(dp, 0x7f);
    deque<pii> q;

    fori (i, 0, n) {
      // Only node i visited and the stopping node is i.
      dp[1 << i][i] = 0;
      q.pb({1<<i, i});
    }

    while (sz(q)) {
      auto cur = q.front(); q.pop_front();
      int state = cur.fi, start = cur.se;
      fora(node, g[start]) {
        // Add this node as a visited node.
        int new_state = state | (1 << node);
        if (dp[new_state][node] > dp[state][start] + 1) {
          dp[new_state][node] = dp[state][start] + 1;
          q.pb(new_state, node);
        }
      }
    }

    int ret = inf;
    fori(i, 0, n) ret = min(ret, dp[(1<<n) - 1][i]);
    return ret;
  }
};

int main() {
  return 0;
}
