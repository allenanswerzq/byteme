/* created   : 2020-09-18 22:00:48
 * accepted  : 2020-09-18 22:44:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  bool search(vector<int>& A, int target) {
    if (A.empty()) return false;
    int n = A.size();
    int lo = 0;
    int hi = n - 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      if (A[lo] == A[md] && A[md] == A[hi]) {
        lo++, hi--;
      }
      else if (A[md] >= A[lo]) {
        if (A[lo] <= target && target <= A[md]) {
          hi = md;
        } else {
          lo = md;
        }
      }
      else {
        if (A[md] <= target && target <= A[hi]) {
          lo = md;
        } else {
          hi = md;
        }
      }
    }
    // trace(lo, hi, A[lo], A[hi]);
    if (lo >= 0 && A[lo] == target) return true;
    if (hi < n && A[hi] == target) return true;
    return false;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

bool test(vector<int> A, int target) {
  Solution sol;
  return sol.search(A, target);
}

void solve() {
  EXPECT_TRUE(test({0,0,1,1,2,0}, 2));
  EXPECT_FALSE(test({1,1,3}, 0));
  EXPECT_TRUE(test({1,3,1,1,1}, 3));
  EXPECT_TRUE(test({1,1,3,1}, 3)); // 1,1,1,3
  EXPECT_TRUE(test({2,5,6,0,0,1,2}, 0));
  EXPECT_FALSE(test({2,5,6,0,0,1,2}, 3));
  EXPECT_TRUE(test({0,1,2,2,5,6,0}, 0));
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
