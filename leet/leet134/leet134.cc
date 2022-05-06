/* created   : 2020-09-26 14:45:14
 * accepted  : 2020-09-26 14:53:45
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  using ll = long long;
  int canCompleteCircuit(vector<int>& G, vector<int>& C) {
    //
    //  +1 +2 3 4 5 1 2 3 4 5
    //  -3 -4 5 1 2 3 4 5 1 2
    //
    //  -2 -2 -2 +3 +3 -2 -2 -2 +3 +3
    //
    G.insert(G.end(), G.begin(), G.end());
    C.insert(C.end(), C.begin(), C.end());
    int n = G.size();
    for (int i = 0; i < n; i++) {
      G[i] -= C[i];
    }
    n /= 2;
    ll s = 0;
    int k = 0;
    for (int lo = 0, hi = 0; lo < n; ) {
      while (hi < 2 * n && k < n && s + G[hi] >= 0) {
        s += G[hi++];
        k++;
      }
      // [lo, hi)
      // -1 -1 1 -1 -1 1
      if (k == n) {
        return hi - n;
      }
      k--;
      s -= G[lo++];
    }
    return -1;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> G, vector<int> C) {
  Solution sol;
  return sol.canCompleteCircuit(G, C);
}

void solve() {
  EXPECT(test({2, 3, 4}, {3, 4, 3}), -1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
