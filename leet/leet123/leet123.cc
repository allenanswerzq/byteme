/* created   : 2020-09-20 20:22:16
 * accepted  : 2020-09-21 22:13:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete at most two transactions.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



// Example 1:

// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.


// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 105

class Solution {
public:
  using ll = long long;
  void amax(ll & a, ll b) { a = max(a, b); }

  template <class T>
  void trace(vector<vector<T>> & v) {
      for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
          cout << v[i][j] << (j == v[i].size() - 1 ? "\n" : " ");
        }
      }
  }

  int maxProfit(vector<int>& P) {
      // f[i][k] = max(f[j-1][k-1] - a[j] + a[i], f[i-1][k]) j < i
      int n = P.size();
      int K = 2;
      vector<vector<ll>> f(n + 1, vector<ll>(K + 1));
      for (int k = 1; k <= K; k++) {
        ll mx = -1e18;
        for (int i = 0; i < n; i++) {
          amax(f[i+1][k], f[i][k]);
          amax(f[i+1][k], mx + P[i]);
          mx = max(mx, f[i][k-1] - P[i]);
        }
      }
      // trace(f);
      return *max_element(f[n].begin(), f[n].end());
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
