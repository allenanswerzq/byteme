#include<bits/stdc++.h>
using namespace std;

const int size = 3002;
char grid[size][size];
ll dp[size][size];

ll solve() {
  int rr, cc, kk; cin >> rr >> cc >> kk;
  fori (i, 0, rr) 
    fori (j, 0, cc) {
      grid[i][j] = 0;
      dp[i][j] = 0;
    }

  fori (i, 0, kk) {
    int x, y; cin >> x >> y;
    grid[x][y] = 1;
  }

  fori (i, 0, rr) {
    fori (j, 0, cc) {
      if (grid[i][j] == 1) continue;
      if (i == 0)
        dp[0][j] = 1;
      else if (j == 0)
        dp[i][0] = 1;
      else {
        ll len = inf;
        if (i >= 1) len = min(dp[i-1][j], len);
        if (j >= 1) len = min(dp[i][j-1], len);
        if (i >= 1 && j >= 1) len = min(dp[i-1][j-1], len);
        dp[i][j] = len + 1;
      }
    }
  }

  // fori (i, 0, rr) { 
  //   par(dp[i], cc);
  // }

  ll res = 0;
  fori (i, 0, rr) {
    fori (j, 0, cc) {
      res += dp[i][j];
    }
  }
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  int t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    output(i, r); 
  }  

  return 0;
}
