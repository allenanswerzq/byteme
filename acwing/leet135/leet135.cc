/* created   : 2020-09-26 15:01:24
 * accepted  : 2020-09-26 15:25:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int candy(vector<int>& A) {
    //    1 2 2
    //    0 1 0
    //    0 0 0

    //   1 0 2
    //   0 0 1
    //   1 0 0

    // 1 2 3 4 5 5 3 1
    // 0 1 1 1 1 0 0 0
    // 0 0 0 0 0 1 1 0
    int n = A.size();
    vector<int> f(n);
    for (int i = 1; i < n; i++) {
      if (A[i] > A[i - 1]) {
        f[i] = f[i - 1] + 1;
      }
    }
    // trace(f);
    vector<int> g(n);
    for (int i = n - 2; i >= 0; i--) {
      if (A[i] > A[i + 1]) {
        g[i] = g[i + 1] + 1;
        f[i] = max(f[i], g[i]);
      }
    }
    // trace(g, f);
    return accumulate(all(f), 0) + n;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A) {
  Solution sol;
  return sol.candy(A);
}

void solve() {
  EXPECT(test({1,0,2}), 5);
  EXPECT(test({1,2,2}), 4);
  EXPECT(test({1,2,3,4,5,5,3,1}), 21);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
