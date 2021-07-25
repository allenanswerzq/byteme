/* created   : 2020-09-15 22:52:36
 * accepted  : 2020-09-15 23:14:40
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int minDistance(string A, string B) {
    vector<int> f(B.size() + 1);
    iota(f.begin(), f.end(), 0);
    for (int i = 0; i < A.size(); i++) {
      vector<int> ff(B.size(), 1e9);
      for (int j = 0; j < B.size(); j++) {
        ff[j + 1] = min({f[j] + (A[i] != B[j]), f[j + 1] + 1, ff[j] + 1});
      }
      swap(ff, f);
    }
    return f[B.size()];
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(string a, string b) {
  Solution sol;
  return sol.minDistance(a, b);
}

void solve() {
  EXPECT(test("", "a"), 1);
  EXPECT(test("horse", "ros"), 3);
  EXPECT(test("intention", "execution"), 5);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
