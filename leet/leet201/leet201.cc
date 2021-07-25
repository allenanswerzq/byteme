/* created   : 2020-10-02 17:45:57
 * accepted  : 2020-10-02 18:02:55
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int rangeBitwiseAnd(int M, int N) {
    // 1000
    // 1000
    int d = N - M;
    int c = 0;
    while ((1u << c) <= N) c++;
    // trace(c);
    int ans = 0;
    unsigned int t = 1;
    unsigned int m = 0;
    for (int i = 0; i < c; i++) {
      int b = ((M >> i) & 1);
      if (m + d >= (1u << i)) {
        b = 0;
      }
      ans = b * t + ans;
      m = ((M >> i) & 1) * t + m;
      t <<= 1;
      // trace(i, d, m, b, ans);
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

// 1000000000
// 1000000001
// ......
// 1111111111

int test(int M, int N) {
  Solution sol;
  return sol.rangeBitwiseAnd(M, N);
}

void solve() {
  EXPECT(test(8, 8), 8);
  EXPECT(test(512, 1023), 512);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
