/* created   : 2020-09-11 22:58:43
 * accepted  : 2020-09-12 09:46:15
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  bool canJump(vector<int>& A) {
    return canJumpBest(A);
  }

  bool canJumpBest(vector<int>& A) {
    int n = A.size();
    int last = n - 1;
    for (int i = n - 2; i >= 0; i--) {
      if (i + A[i] >= last) {
        last = i;
      }
    }
    return last == 0;
  }

  bool canJumpInterval(vector<int>& A) {
    int n = A.size();
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
      a.push_back({i, -1});
      a.push_back({i + A[i], 1});
    }
    sort(a.begin(), a.end());
    trace(a);
    int ans = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
      ans += a[i].second;
      if (ans == 0) {
        return false;
      }
    }
    return true;
  }
};

bool test(vector<int> a) {
  Solution sol;
  return sol.canJump(a);
}

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)

void solve() {
  EXPECT_TRUE(test({2,3,1,1,4}));
  EXPECT_FALSE(test({3,2,1,0,4}));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
