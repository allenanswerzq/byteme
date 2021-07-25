/* created   : 2020-09-28 23:22:10
 * accepted  : 2020-09-28 23:22:10
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int findMin(vector<int>& A) {
    int n = A.size();
    int lo = 0;
    int hi = n - 1;
    while (lo + 1 < hi) {
      int md = (lo + hi) >> 1;
      if (A[lo] == A[md] && A[md] == A[hi]) {
        lo++, hi--;
      }
      else if (A[md] <= A[hi]) {
        hi = md;
      }
      else if (A[lo] <= A[md]) {
        lo = md;
      }
      else {
        assert(false);
      }
    }
    return min(A[lo], A[hi]);
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
