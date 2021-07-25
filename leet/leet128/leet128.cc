/* created   : 2020-09-25 11:27:45
 * accepted  : 2020-09-25 11:40:50
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int longestConsecutive(vector<int>& A) {
    unordered_map<int, int> cnt;
    int ans = 0;
    for (int a : A) {
      if (cnt[a] > 0) continue;
      cnt[a] = 1;
      int x = cnt[a - 1];
      int y = cnt[a + 1];
      int s = a - 1 - x + 1;
      int t = a + 1 + y - 1;
      // trace(a, x, y, s, t, x + y + 1);
      cnt[s] = x + y + 1;
      cnt[t] = x + y + 1;
      ans = max(ans, x + y + 1);
    }
    // trace(cnt);
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A) {
  Solution sol;
  return sol.longestConsecutive(A);
}

void solve() {
  EXPECT(dbg(test({100, 4, 200, 1, 3, 2})), 4);
  EXPECT(test({4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3}), 5);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
