/* created   : 2020-08-23 20:58:09
 * accepted  : 2020-09-09 08:08:21
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int search(vector<int> A, int target) {
    int n = A.size();
    int lo = 0;
    int hi = n - 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      trace(lo, hi, md);
      if (A[md] > A[lo]) {
        // if (target == A[md]) {
        //   return md;
        // }
        if (A[lo] <= target && target <= A[md]) {
          hi = md;
        } else {
          lo = md;
        }
      } else {
        // if (target == A[md]) {
        //   return md;
        // }
        if (A[md] < target && target <= A[hi]) {
          lo = md;
        } else {
          hi = md;
        }
      }
    }
    trace(lo, hi, A[lo], A[hi]);
    if (lo >= 0 && A[lo] == target) return lo;
    if (hi < n && A[hi] == target) return hi;
    return -1;
  }
};

#define EXPECT(a, b) assert(a == b)

void solve() {
  Solution s;
  EXPECT(s.search({4, 5, 6, 7, 0, 1, 2}, 0), 4);
  EXPECT(s.search({4, 5, 6, 7, 0, 1, 2}, 5), 1);
  EXPECT(s.search({4, 5, 6, 7, 0, 1, 2}, 2), 6);
  EXPECT(dbg(s.search({4, 5, 6, 7, 0, 1, 2}, 4)), 0);
  EXPECT(s.search({4, 5, 6, 7, 0, 1, 2}, 3), -1);
  EXPECT(s.search({1}, 0), -1);
  // EXPECT(s.search({}, 0), -1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
