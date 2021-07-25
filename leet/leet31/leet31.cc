/* created   : 2020-09-08 23:36:23
 * accepted  : 2020-09-08 23:36:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
public:
  void nextPermutation(vector<int> &A) {
    // if (A.size() == 1) return;
    int n = A.size();
    int p = -1;
    for (int i = n - 1; i >= 1; i--) {
      if (A[i - 1] < A[i]) {
        p = i - 1;
        break;
      }
    }
    // cout << p << " " << A[p] << "\n";
    for (int k = n - 1; ~p && k > p; k--) {
      if (A[k] > A[p]) {
        swap(A[k], A[p]);
        break;
      }
    }
    reverse(A.begin() + p + 1, A.end());
  }
};

// 1 2 3 4 5
// 1 2 3 5 4
// 1 2 4 3 5
// 1 2 4 5 3
// 1 2 5 3 4
// 1 2 5 4 3
// 1 3 2 4 5
// 1 3 2 5 4
// 1 3 4 2 5
// 1 3 4 5 2
// 1 3 5 4 2
// 1 4 2 3 5

// ...a[i - 1] < a[i] > a[i + 1] > a[i + 2]...
//        |_________________j

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
