/* created   : 2022-05-13 12:51:23
 * accepted  : 2022-05-13 12:51:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  int findMin(vector<int>& A) {
    if (A.size() == 1) return A[0];
    if (A[0] < A[A.size() - 1]) return A[0];
    int lo = 0;
    int hi = A.size() - 1;
    while (lo + 1 < hi) {
      int md = (lo + hi) / 2;
      if (A[lo] < A[md]) {
        lo = md;
      }
      else {
        hi = md;
      }
    }
    return A[hi];
  }

  // leet154
  int findMin(vector<int>& A) {
    int lo = 0;
    int hi = A.size() - 1;
    while (lo <= hi && A[hi] == A[lo]) hi--;
    if (lo > hi) return A[lo];
    if (A[lo] < A[hi]) return A[lo];
    while (lo + 1 < hi) {
      int md = (lo + hi) / 2;
      if (A[lo] <= A[md]) {
        lo = md;
      }
      else {
        hi = md;
      }
    }
    return A[hi];
  }
};
