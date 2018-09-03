#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
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

// #define LOCAL_FILE

class Solution {
public:
  int maxCoins(vector<int>& aa) {
  if (sz(aa) <= 0) return 0;
  aa.insert(aa.begin(), 1);
  aa.insert(aa.end(), 1);
  int n = sz(aa);

  // dp[i][j] denotes max coins we can get from array [i...j].
  // dp[i][j] = max(dp[i][k] + dp[k+1][j] + aa[i-1][k][j+1])
  int dp[n][n]; mst(dp, 0);

  fori (j, 1, n-1) {
    ford (i, j, 0) {
    fori (k, i, j+1) {
      int tmp = dp[i][k-1] + dp[k+1][j] + (aa[i-1] * aa[k] * aa[j+1]);
      dp[i][j] = max(dp[i][j], tmp);
    }
    } 
  }

  // fori(i, 0, n) {
  //   par(dp[i], n);
  // }

  return dp[1][n];
  }
};

void test(vi aa) {
  Solution go;
  cout << go.maxCoins(aa) << "\n";
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({3, 1, 5, 8});
  return 0;
}
