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

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-f-d-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 1, t + 1) {
    int a; cin >> a;
    int r = solve(a);
    output(i, r);
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
