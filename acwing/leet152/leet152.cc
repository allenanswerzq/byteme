/* created   : 2020-09-28 22:08:50
 * accepted  : 2020-09-28 22:37:20
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int maxProduct(vector<int>& A) {
    int mx = 1;
    int mi = 1;
    int ans = -1e9;
    for (int a : A) {
      int nx = max({mx * a, a, mi * a});
      int ni = min({mi * a, a, mx * a});
      mx = nx, mi = ni;
      ans = max(ans, mx);
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A) {
  Solution sol;
  return sol.maxProduct(A);
}

void solve() {
  EXPECT(test({2, 3, -2, 4}), 6);
  EXPECT(test({-2, 0, -1}), 0);
  EXPECT(test({3, -1, 4}), 4);
  EXPECT(test({-4, -3, -2}), 12);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
