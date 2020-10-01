/* created   : 2020-09-30 21:43:08
 * accepted  : 2020-10-01 09:06:48
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int rec(vector<int>& A, int lo, int hi) {
    if (lo == hi) {
      return -1;
    }
    if (lo + 1 == hi) {
      return -1;
    }
    int md = (lo + hi) >> 1;
    int x = rec(A, lo, md);
    if (x != -1) return x;
    int y = rec(A, md + 1, hi);
    if (y != -1) return y;
    // trace(lo, md, hi, x, y);
    if (A[md - 1] < A[md] && A[md] > A[md + 1]) {
      return md;
    }
    if (md + 2 < A.size() && A[md] < A[md + 1] && A[md + 1] > A[md + 2]) {
      return md + 1;
    }
    return -1;
  }

  int findPeakElement(vector<int>& A) {
    int n = A.size();
    if (n == 1) {
      return 0;
    }
    if (A[0] > A[1]) {
      return 0;
    }
    if (A[n - 2] < A[n - 1]) {
      return n - 1;
    }
    return rec(A, 0, A.size() - 1);
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A) {
  Solution sol;
  return sol.findPeakElement(A);
}

void solve() {
  EXPECT(dbg(test({3, 2, 1})), 0);
  EXPECT(dbg(test({1,2,3,1})), 2);
  EXPECT(test({1,2,1,3,5,6,4}), 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
