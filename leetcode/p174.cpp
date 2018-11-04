#include<bits/stdc++.h>
using namespace std;

#define ll long long
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

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& aa) {
    int m, n;
    m = sz(aa), n = sz(aa[0]); 
    // dp[i][j] denotes the minimum points before enter `(i,j)`,
    // that can guarantee himself reaches to the final goal.
    int dp[m][n]; mst(dp, 0);

    ford (i, m - 1, -1) {
      ford (j, n - 1, -1) {
        if (i == m-1 && j == n-1) 
          dp[i][j] = max(1, 1 - aa[i][j]);

        else if (i == m-1) {
          // Last row.
          dp[i][j] = max(dp[i][j+1] - aa[i][j], 1);
        } 
        else if (j == n-1) {
          // Last column.
          dp[i][j] = max(dp[i+1][j] - aa[i][j], 1);
        } 
        else {
          int mi = min(dp[i+1][j], dp[i][j+1]);
          dp[i][j] = max(mi - aa[i][j], 1);
        }
      }
    }
    return dp[0][0];
  }
};

void test(vvi aa) {
  Solution go;
  cout << go.calculateMinimumHP(aa) << "\n"; 
}

int main() {
  test({{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}});
  test({{1,0,0}});
  return 0;
}
