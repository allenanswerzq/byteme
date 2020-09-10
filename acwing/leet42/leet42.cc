/* created   : 2020-09-10 22:52:25
 * accepted  : 2020-09-10 23:11:34
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int trap(vector<int>& A) {
    int ans = get(A);
    reverse(all(A));
    return max(ans, get(A));
  }

  int get(vector<int>& A) {
    int n = A.size();
    const int INF = 1e9;
    A.push_back(INF);
    vector<int> big(n);
    vector<int> stk;
    for (int i = 0; i < A.size(); i++) {
      while (stk.size() && A[i] >= A[stk.back()]) {
        int t = stk.back();
        big[t] = i;
        stk.pop_back();
      }
      stk.push_back(i);
    }
    int lo = 0;
    int ans = 0;
    while (lo < n) {
      int p = big[lo];
      // trace(lo, p, ans);
      if (p == n) {
        lo++;
        continue;
      }
      assert(p > lo);
      ans += (p - lo - 1) * A[lo];
      for (int k = lo + 1; k < p; k++) {
        ans -= A[k];
      }
      lo = p;
      // trace(ans);
    }
    // trace(A, big, ans);
    return ans;
  }
};

#define EXPECT(a, b) assert(a == b)

int test(vector<int> a) {
  Solution s;
  return s.trap(a);
}

void solve() {
  EXPECT(test({0,1,0,2,1,0,1,3,2,1,2,1}), 6);
  EXPECT(test({4, 2, 3}), 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
