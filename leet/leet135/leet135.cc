/* created   : 2020-09-26 15:01:24
 * accepted  : 2020-09-26 15:25:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  void trace(vector<int> & A) {
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
    }
  }
  using ll = long long;
  int candy(vector<int>& A) {
    int n = A.size();
    vector<int> B(n), F(n);
    for (int i = 0; i < n; i++) {
      F[i] = (i > 0 && A[i] > A[i-1] ? F[i-1] + 1 : 1);
    }
    for (int i = n - 1; i >= 0; i--) {
      B[i] = (i + 1 < n && A[i] > A[i+1] ? B[i+1] + 1 : 1);
    }
    // trace(F);
    // trace(B);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      A[i] = max(F[i], B[i]);
      ans += A[i];
    }
    // trace(A);
    return ans;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

int test(vector<int> A) {
  Solution sol;
  return sol.candy(A);
}

void solve() {
  EXPECT(test({1,0,2}), 5);
  EXPECT(test({1,2,2}), 4);
  EXPECT(test({1,2,3,4,5,5,3,1}), 21);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
