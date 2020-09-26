/* created   : 2020-09-25 18:42:26
 * accepted  : 2020-09-26 11:23:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  vector<vector<int>> F;
  vector<vector<int>> M;
  int dfs(const string& S, int lo, int hi) {
    if (lo >= hi || F[lo][hi]) return 0;
    if (M[lo][hi] != -1) return M[lo][hi];
    int ans = 1e9;
    for (int i = lo; i < hi; i++) {
      if (F[lo][i]) {
        ans = min(ans, 1 + dfs(S, i + 1, hi));
      }
    }
    return M[lo][hi] = ans;
  }

  int minCutDfs(string S) {
    int n = S.size();
    F.resize(n, vector<int>(n));
    M.resize(n, vector<int>(n, -1));
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int j = i + len - 1;
        if (len == 1) {
          F[i][j] = 1;
        }
        else if (len == 2) {
          F[i][j] = (S[i] == S[j]);
        }
        else if (S[i] == S[j] && F[i + 1][j - 1]) {
          F[i][j] = 1;
        }
        else {
          F[i][j] = 0;
        }
      }
    }
    return dfs(S, 0, n - 1);
  }

  int minCutDP(string S) {
    int n = S.size();
    F.resize(n, vector<int>(n));
    // i.j
    // F[i][j] = F[i + 1][j - 1] & (S[i] == S[j]) if (i + 1 <= j - 1)
    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        int j = i + len - 1;
        if (len == 1) {
          F[i][j] = 1;
        }
        else if (len == 2) {
          F[i][j] = (S[i] == S[j]);
        }
        else if (S[i] == S[j] && F[i + 1][j - 1]) {
          F[i][j] = 1;
        }
        else {
          F[i][j] = 0;
        }
      }
    }
    const int INF = 1e9;
    vector<int> c(n, INF);
    c[0] = 0;
    for (int i = 1; i < n; i++) {
      if (F[0][i]) {
        c[i] = 0;
      }
      else {
        // 0...... i
        // 0...j|j+1..i
        for (int j = 0; j < i; j++) {
          if (F[j + 1][i]) {
            c[i] = min(c[i], 1 + c[j]);
          }
        }
      }
    }
    return c[n - 1];
  }

  int minCut(string S) {
    // return minCutDP(S);
    return minCutDfs(S);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& S) {
  Solution sol;
  return sol.minCut(S);
}

void solve() {
  EXPECT(test("leet"), 2);
  EXPECT(test("aaabaa"), 1);
  EXPECT(test("aab"), 1);
  EXPECT(test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
