/* created   : 2020-09-13 17:01:11
 * accepted  : 2020-09-13 18:24:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  vector<vector<string>> ans;
  vector<int> row, col, left, right;
  vector<string> A;

  // t(n) = (n - 1) * t(n - 1) + O(n)
  void dfs(int i) {
    int n = A.size();
    if (i == n) {
      ans.push_back(A);
      return;
    }
    for (int j = 0; j < n; j++) {
      if (A[i][j] == '.' && !col[j] && !left[i + j] && !right[i - j + n]) {
        A[i][j] = 'Q';
        row[i] = 1;
        col[j] = 1;
        left[i + j] = 1;
        right[i - j + n] = 1;
        dfs(i + 1);
        A[i][j] = '.';
        row[i] = 0;
        col[j] = 0;
        left[i + j] = 0;
        right[i - j + n] = 0;
      }
    }
  }

  vector<vector<string>> solveNQueens(int N) {
    A.resize(N, string(N, '.'));
    row.resize(N);
    col.resize(N);
    left.resize(2 * N);
    right.resize(2 * N);
    dfs(0);
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {
  Solution sol;
  auto ans = sol.solveNQueens(10);
  trace(ans);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
