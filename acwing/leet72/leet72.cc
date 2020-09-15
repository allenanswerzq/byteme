/* created   : 2020-09-15 22:52:36
 * accepted  : 2020-09-15 23:14:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  void amin(int& a, int b) { a = min(a, b); }

  int minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    const int INF = 1e9;
    vector<vector<int>> f(n + 2, vector<int>(m + 2, INF));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      f[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
      f[0][i] = i;
    }
    // f[i][j] = min{f[i - 1][j - 1] + x, f[i - 1][j] + 1, f[i][j - 1] + 1};
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        amin(f[i][j], f[i - 1][j - 1] + (A[i - 1] != B[j - 1]));
        amin(f[i][j], f[i - 1][j] + 1); // delete
        amin(f[i][j], f[i][j - 1] + 1); // insert
      }
    }
    return f[n][m];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(string a, string b) {
  Solution sol;
  return sol.minDistance(a, b);
}

void solve() {
  EXPECT(test("", "a"), 1);
  EXPECT(test("horse", "ros"), 3);
  EXPECT(test("intention", "execution"), 5);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
