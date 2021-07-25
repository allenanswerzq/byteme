/* created   : 2020-09-10 22:52:25
 * accepted  : 2020-09-11 07:58:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  int trap(vector<int>& A) {
    int n = A.size();
    vector<int> stk;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (stk.size() && A[i] > A[stk.back()]) {
        int cur = stk.back(); stk.pop_back();
        if (stk.empty()) break;
        int left = stk.back();
        // left >= cur < A[i]
        ans += max(min(A[i], A[left]) - A[cur], 0) * (i - left - 1);
      }
      stk.push_back(i);
    }
    return ans;
  }

  int traptwo(vector<int>& A) {
    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i - 1], A[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      right[i] = max(right[i + 1], A[i + 1]);
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      ans += max(min(left[i], right[i]) - A[i], 0);
    }
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
