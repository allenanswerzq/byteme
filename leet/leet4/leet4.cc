/* created   : 2020-10-05 12:01:28
 * accepted  : 2020-10-05 12:01:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int k = (n + m) / 2; // 1 |2 3 4,  |1 2 3
    int cur = -1;
    int first = -1;
    int second = -1;
    for (int i = 0, j = 0; i < n || j < m; ) {
      if (j >= m || (i < n && A[i] < B[j])) {
        cur = A[i++];
      }
      else {
        cur = B[j++];
      }
      if (i + j == k) {
        first = cur;
      }
      if (i + j == k + 1) {
        second = cur;
      }
    }
    return (n + m) % 2 ? second : (first + second) / 2.0;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {}

int main() {
  solve();
  return 0;
}
