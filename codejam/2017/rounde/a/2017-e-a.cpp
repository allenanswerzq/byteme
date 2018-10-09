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

// TODO: 
const int maxn = 120;
int dp[maxn];
int solve(string s) {
  int n = sz(s);
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
    dp[i] = inf;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {

      bool ok = 0;
      int len = j - i + 1;
      for (int k = 0; k + len <= i; k++) {
        ok = 1;
        if (s.substr(k, len) != s.substr(i, len)) {
          ok = 0;
        }
        if (ok) break;
      }

      int cur = dp[i] + 1;
      for (int k = i; k+len <= n; k += len) {
        cur++;
        if (s.substr(k, len) != s.substr(i, len)) {
          ok = 0;
        }
        if (!ok) break;
        dp[k + len] = min(dp[k + len], cur);
      }
    }
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
  }
  return dp[n];
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

  freopen("2017-e-a-SSSSSSmall.txt", "rt", stdin);
  clock_t begin = clock();

  int t; cin >> t;
  fori (i, 1, t + 1) {
    string s; cin >> s;
    int r = solve(s);
    output(i, r);
  }

  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
  return 0;
}
