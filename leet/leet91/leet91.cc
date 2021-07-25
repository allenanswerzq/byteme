/* created   : 2020-09-20 09:05:37
 * accepted  : 2020-09-20 09:15:38
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int numDecodings(string S) {
    int n = S.size();
    vector<int> f(n + 1);
    f[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (S[i] != '0') {
        f[i] += f[i + 1];
      }
      if (i < n - 1 && (S[i] == '1' || (S[i] == '2' && '0' <= S[i + 1] &&
                                        S[i + 1] <= '6'))) {
        f[i] += f[i + 2];
      }
    }
    return f[0];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(const string& S) {
  Solution sol;
  return sol.numDecodings(S);
}

void solve() {
  EXPECT(test("0"), 0);
  EXPECT(dbg(test("12")), 2);
  EXPECT(test("226"), 3);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
