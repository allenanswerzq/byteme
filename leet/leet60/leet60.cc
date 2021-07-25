/* created   : 2020-09-13 20:20:17
 * accepted  : 2020-09-13 23:12:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  string getPermutation(int n, int k) {
    // "123"
    // "132"
    // "213"
    // "231"
    // "312"
    // "321"
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    vector<int> a(n + 1);
    string ans;
    int m = n;
    while (ans.size() < m && n) {
      // NOTE: here we use k minus 1.
      // eg. [1..3][3..6][7...9]
      // assume k = 5 and k = 6, using (k - 1) / 3 we can unite
      // these two operation together.
      int t = (k - 1) / fact[n - 1];
      // trace(t, k, fact[n - 1], ans, n, a);
      int c = 0;
      for (int i = 1; i <= m; i++) {
        if (!a[i] && ++c == t + 1) {
          a[i] = 1;
          ans.push_back(i + '0');
        }
      }
      k -= t * fact[n - 1];
      n--;
    }
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

string test(int n, int k) {
  Solution sol;
  return sol.getPermutation(n, k);
}

void solve() {
  EXPECT(dbg(test(3, 1)), "123");
  EXPECT(dbg(test(3, 2)), "132");
  EXPECT(dbg(test(3, 3)), "213");
  EXPECT(dbg(test(3, 4)), "231");
  EXPECT(dbg(test(3, 5)), "312");
  EXPECT(dbg(test(3, 6)), "321");
  EXPECT(test(4, 9), "2314");
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
