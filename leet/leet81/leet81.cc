/* created   : 2020-09-18 22:00:48
 * accepted  : 2020-09-18 22:44:27
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  bool search(vector<int>& A, int val) {
    int n = A.size();
    int lo = 0;
    int hi = n - 1;
    while (lo + 1 < hi && A[hi] == A[lo]) hi--;
    if (lo > hi) return false;
    while (lo + 1 < hi) {
      int md = (lo + hi) / 2;
      if (A[md] == val) {
        return true;
      }
      else if (A[lo] <= A[md]) {
        if (A[lo] <= val && val < A[md]) {
          hi = md;
        }
        else {
          lo = md;
        }
      }
      else {
        assert(A[md] <= A[hi]);
        if (A[md] < val && val <= A[hi]) {
          lo = md;
        }
        else {
          hi = md;
        }
      }
    }
    if (A[lo] == val || A[hi] == val) return true;
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
