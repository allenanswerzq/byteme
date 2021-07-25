/* created   : 2020-09-10 22:50:59
 * accepted  : 2020-09-10 22:50:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  int firstMissingPositive(vector<int>& A) {
    int n = A.size();
    bool ok = false;
    for (int& a : A) {
      if (a < 0 || a > n) {
        a = 0;
      }
      if (a == 1) ok = true;
    }
    if (!ok) return 1;
    for (int i = 0; i < n; i++) {
      int cur = abs(A[i]);
      if (cur > 0) {
        assert(1 <= cur && cur <= n);
        int val = abs(A[cur - 1]);
        A[cur - 1] = min(-val, -1);
      }
    }
    for (int i = 0; i < n; i++) {
      if (A[i] >= 0) {
        return i + 1;
      }
    }
    return n + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
