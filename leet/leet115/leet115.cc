/* created   : 2020-09-20 17:10:30
 * accepted  : 2020-09-20 18:03:38
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  // f[i][j] = f[i - 1][j] + f[i - 1][j - 1] (iff S[i] == T[i])
  int numDistinct(string S, string T) {
    int n = S.size();
    int m = T.size();
    vector<vector<ll>> f(n + 1, vector<ll>(m + 1));
    for (int i = 0; i <= n; i++) {
      f[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = f[i - 1][j];
        if (S[i - 1] == T[j - 1]) {
          f[i][j] += f[i - 1][j - 1];
        }
        // trace(i, j, f[i][j], S.substr(0, i), T.substr(0, j));
      }
    }
    return f[n][m];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& S, const string& T) {
  Solution sol;
  return sol.numDistinct(S, T);
}

void solve() {
  EXPECT(dbg(test("rabbbit", "rabbit")), 3);
  EXPECT(dbg(test("babgbag", "bag")), 5);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
