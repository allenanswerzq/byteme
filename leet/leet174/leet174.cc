/* created   : 2022-05-15 14:36:23
 * accepted  : 2022-05-15 14:36:26
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  void trace(vector<vector<int>> &v) {
    for (auto &t : v) {
      cout << "[";
      for (auto &x : t) {
        cout << x << " ";
      }
      cout << "]\n";
    }
  }

  int calculateMinimumHP(vector<vector<int>> &B) {
    int m = B.size();
    int n = B[0].size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 1e9));
    f[m - 1][n] = f[m][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        f[i][j] = max(1, min(f[i + 1][j], f[i][j + 1]) - B[i][j]);
      }
    }
    // trace(f);
    return f[0][0];
  }
};
