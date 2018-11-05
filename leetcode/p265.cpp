#include <bits/stdc++.h>
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

// There are a row of n houses, each house can be painted with one of the k colors. 
// The cost of painting each house with a certain color is different. 
// You have to paint all the houses such that no two adjacent houses have the same color.
// The cost of painting each house with a certain color is represented by a n x k cost matrix. 
// For example, costs[0][0] is the cost of painting house 0 with color 0; 
// costs[1][2] is the cost of painting house 1 with color 2, 
// and so on... Find the minimum cost to paint all houses.

class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    int m = costs[0].size();
    int ret = (1 << 30);
    int dp[n + 1][m]; mst(dp, 0);
    // For each house
    for (int i = 1; i <= n; ++i) {  
      // For each color
      for (int j = 0; j < m; ++j) { 
        int pre = (1 << 30);
        for (int k = 0; k < m; ++k)
          if (k != j) 
            pre = min(pre, dp[i-1][k]);

        dp[i][j] = costs[i-1][j] + pre;
        ret = min(ret, dp[i][j]);
      }
    }
    return ret;
  }

  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = costs.size(), k = costs[0].size();
    // The min value m1, the econd min value m2
    int m1 = 0, m2 = 0;           
    vector<int> dp(k, 0);
    // Paint each house
    for (int i = 0; i < n; i++) { 
      // The previous minimum cost and the previous second minimum cost.
      int t1 = m1, t2 = m2;
      m1 = m2 = (1 << 30);
      // Pick each color
      for (int j = 0; j < k; j++) { 
        // If last time we got min costs on color j for painting house i-1, 
        // now when we pick color j, we can only use second min costs of last time
        // because two adjcent house have different colors
        int pre = dp[j] == t1 ? t2 : t1;  
        dp[j] = pre + costs[i][j];

        if (dp[j] > m1) m2 = min(m2, dp[j]);
        else m2 = m1, m1 = dp[j];
      }
    }
    return m1;
  }
};

int main() {
  return 0;
}
