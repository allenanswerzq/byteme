/* created   : 2020-09-20 20:22:16
 * accepted  : 2020-09-21 22:13:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void amax(int& a, int b) { a = max(a, b); }

class Solution {
public:
  int maxProfit(vector<int>& A, int K = 2) {
    // f[i][k] = max(f[i - 1][k], max(f[j - 1][k - 1] - a[j]) + a[i])
    int n = A.size();
    if (K > n / 2) {
      int ans = 0;
      for (int i = 0; i < n - 1; i++) {
        int d = A[i + 1] - A[i];
        ans += (d > 0 ? d : 0);
      }
      return ans;
    }
    vector<vector<int>> f(n + 1, vector<int>(K + 1));
    for (int k = 1; k <= K; k++) {
      int mx = -1e9;
      for (int i = 1; i <= n; i++) {
        amax(f[i][k], f[i - 1][k]);
        amax(f[i][k], mx + A[i - 1]);
        mx = max(mx, f[i - 1][k - 1] - A[i - 1]);
      }
    }
    return f[n][k];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A, int k = 2) {
  Solution sol;
  return sol.maxProfit(A, k);
}

void solve() {
  EXPECT(dbg(test({1,2,4,2,5,7,2,4,9,0})), 13);
  EXPECT(test({3,2,6,5,0,3}), 7);
  EXPECT(test({3, 2, 1}), 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
