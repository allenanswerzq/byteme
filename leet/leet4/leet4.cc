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

class Solution {
public:
  int dfs(vector<int>& A, vector<int>& B, int ai, int aj, int bi, int bj, int pos) {
    // cout << ai << " " << aj << " " << bi << " " << bj << " " << pos << endl;
    if (ai > aj) return B[bi + pos - 1];
    if (bi > bj) return A[ai + pos - 1];
    int am = (ai + aj) / 2;
    int p = upper_bound(B.begin() + bi, B.begin() + bj + 1, A[am]) - B.begin();
    // cout << p << endl;
    int cnt = p - bi + am - ai + 1;
    if (cnt == pos) {
      return A[am];
    }
    else if (pos < cnt) {
      return dfs(A, B, ai, am - 1, bi, p - 1, pos);
    }
    else {
      return dfs(A, B, am + 1, aj, p, bj, pos - cnt);
    }
  }

  int findKth(vector<int>& A, vector<int> & B, int pos) {
    return dfs(A, B, 0, A.size() - 1, 0, B.size() - 1, pos);
  }

  double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();
    if ((n + m) & 1) {
      return findKth(A, B, (n + m + 1) / 2);
    }
    else {
      int s = findKth(A, B, (n + m) / 2);
         s += findKth(A, B, (m + n) / 2 + 1);;
      return s / 2.0;
    }
  }
};

