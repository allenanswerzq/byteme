#include<bits/stdc++.h>
using namespace std;

// DP
int numSquaresDP(int n) {
  int sq = 0;
  vector<int> dp(n + 1, (1<<31) - 1);
  for (int i = 1; i <= n; ++i) {
    if (sq * sq < i && i < (sq + 1) * (sq + 1)) {
      int t = sq;
      while (t > 0) { 
        dp[i] = min(dp[i], dp[i - t * t] + dp[t * t]);
        --t;
      }
    } else if (i == (sq + 1) * (sq + 1)) {
      dp[i] = 1;
      sq += 1;
    }
  }
  return dp[n];
}

// BFS
class Solution {
public:
  int numSquares(int n) {
    deque<int> dq;
    dq.push_back(n);
    int level = 0;
    while (!dq.empty()) {
      level++;
      int len = dq.size();
      for (int i = 0; i < len; i++) {
        auto p = dq.front(); dq.pop_front();
        for (int j = 1; j * j <= p; j++) {
          int k = p - j * j;
          if (k == 0) return level;
          dq.push_back(k);
        }
      }
    }
    return 0;
  }
};

int main() {
  return 0;
}
