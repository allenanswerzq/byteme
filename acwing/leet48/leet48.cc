/* created   : 2020-09-13 14:09:56
 * accepted  : 2020-09-13 14:16:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  void rotate(vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        swap(A[i][j], A[j][i]);
      }
    }
    for (int i = 0; i < n; i++) {
      reverse(A[i].begin(), A[i].end());
    }
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
