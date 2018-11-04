#include<bits/stdc++.h>
using namespace std;

bool check(int x) {
  fori (i, 1, sqrt(x) + 4) {
    if (i * i == x)
      return 1;
  }
  return 0;
}

const int mxn = 10002;
int dp[mxn];
int solve(int x) {
  mst(dp, 0);
  dp[1] = 1;
  fori (i, 2, x + 1) {
    if (check(i)) dp[i] = 1;
    else {
      int tmp = inf;
      fori (j, 1, i)
        tmp = min(dp[j] + dp[i - j], tmp);
      dp[i] = tmp;
    }
  }
  // par(dp, x + 1);
  return dp[x];
}

int main() {
 
  int t; cin >> t;
  fori (i, 1, t + 1) {
    int a; cin >> a;
    int r = solve(a);
    output(i, r);
  }

  return 0;
}
