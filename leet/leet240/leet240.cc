/* created   : 2020-10-05 09:46:17
 * accepted  : 2020-10-05 10:28:10
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// t(n) = 3t(n/4) + O(1)
class Solution {
 public:
  bool rec(vector<vector<int>>& A, int x1, int y1, int x2, int y2, int target) {
    int n = A.size();
    int m = A[0].size();
    trace(x1, y1, x2, y2, target);
    if (x1 > x2 || y1 > y2 || x1 < 0 || y1 < 0 || x2 >= n || y2 >= m) {
      return false;
    }
    assert(0 <= x1 && x1 < n);
    assert(0 <= x2 && x2 < n);
    assert(0 <= y1 && y1 < m);
    assert(0 <= y2 && y2 < m);
    assert(x1 <= x2 && y1 <= y2);
    if (x1 == x2 && y1 == y2) {
      return A[x1][y1] == target;
    }
    int x = (x1 + x2) / 2;
    int y = (y1 + y2) / 2;
    // trace(x1, y1, x2, y2, target, x, y);
    if (target == A[x][y]) {
      return true;
    }
    else if (A[x][y] < target) {
      bool ans = 0;
      ans |= rec(A, x1, y + 1, x2, y2, target);
      ans |= rec(A, x + 1, y1, x2, y, target);
      return ans;
    } else {
      bool ans = 0;
      ans |= rec(A, x1, y1, x2, y - 1, target);
      ans |= rec(A, x1, y, x - 1, y2, target);
      return ans;
    }
  }

  bool searchMatrix(vector<vector<int>>& A, int target) {
    if (A.empty()) return false;
    return rec(A, 0, 0, A.size() - 1, A[0].size() - 1, target);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(vector<vector<int>> A, int target) {
  Solution sol;
  return sol.searchMatrix(A, target);
}

void solve() {
  EXPECT_TRUE(test({{1, 4, 7, 11, 15},
                    {2, 5, 8, 12, 19},
                    {3, 6, 9, 16, 22},
                    {10, 13, 14, 17, 24},
                    {18, 21, 23, 26, 30}},
                   5));

  EXPECT_TRUE(test({{1, 4, 7, 11},
                    {2, 5, 8, 12},
                    {3, 6, 9, 16},
                    {10, 13, 14, 17}},
                   17));

  EXPECT_FALSE(test({{1, 4, 7, 11, 15},
                     {2, 5, 8, 12, 19},
                     {3, 6, 9, 16, 22},
                     {10, 13, 14, 17, 24},
                     {18, 21, 23, 26, 30}},
                    20));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
