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

  freopen("2017-p2-b-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();


  int t; cin >> t;
  fori (i, 1, t + 1) {
    ll r = solve();
    output(i, r); 
  }  

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
