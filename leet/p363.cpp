#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int upper(set<int> st, int inp) {
  int lo = 0; 
  int hi = sz(st) - 1;
  auto it = st.begin();
  while (lo < hi) {
  int mid = lo + (hi - lo) / 2;
  if (*next(it, mid) >= inp) 
  hi = mid;
  else 
  lo = mid + 1;
  }
  int res = *next(it, lo); 
  return res >= inp ? res : -0x3f3f3f3f;
}

// Time: O(nlogn)
int maxSubArrayNotGreaterThanK(vi& aa, int k) {
  int n, res, sum;
  n = sz(aa);
  if (n <= 0) return 0;
  set<int> st;
  st.insert(0);
  res = -0x3f3f3f3f;
  sum = 0;
  fori (i, 0, n) {
  sum += aa[i];
  int tmp = upper(st, sum - k);
  if (tmp != -0x3f3f3f3f) 
  res = max(res, sum - tmp);
  // cout << sum << " " << tmp << " " << res << "\n";
  st.insert(sum);
  }
  return res;
}

int maxSubArray(vector<int> aa, int& lo, int& hi) {
  int n = sz(aa);
  int t = aa[0];
  int res = aa[0];
  lo = hi = 0;
  fori (i, 1, n) {
  if (t + aa[i] > aa[i]) {
  t = t + aa[i];
  hi = i;
  } else {
  t = aa[i]; 
  lo = i;
  }
  res = max(res, t); 
  } 
  return res;
}

int maxSubMatrix(vvi& aa) {
  int m, n, res, ux, uy, bx, by;
  m = sz(aa);
  if (m == 0) return 0;
  n = sz(aa[0]);
  vi dp(n, 0);
  res = 0; 
  fori (lt, 0, n) {
  fill(all(dp), 0);
  fori (rt, lt, n) {
  fori (k, 0, m)
  dp[k] += aa[k][rt]; 
  int tp, bt, tmp;
  tmp = maxSubArray(dp, tp, bt);
  if (res < tmp) {
  res = tmp;
  ux = lt; uy = tp;
  bx = rt; by = bt;
  }
  }
  }
  return res;
}

class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& aa, int kk) {
  int m, n, res;
  m = sz(aa);
  if (m == 0) return 0;
  n = sz(aa[0]);
  vi dp(m, 0);
  res = -0x3f3f3f3f; 
  fori (lt, 0, n) {
  fill(all(dp), 0);
  fori (rt, lt, n) {
  fori (j, 0, m)
    dp[j] += aa[j][rt]; 
  int tmp = maxSubArrayNotGreaterThanK(dp, kk);
  res = max(res, tmp);
  }
  }
  return res;
  }

};

int test(vvi aa, int k) {
  Solution go;
  int res = go.maxSumSubmatrix(aa, k);
  cout << res << "\n";
  return res;
}

int test_two(vvi aa) {
  int res = maxSubMatrix(aa);
  cout << res << "\n";
  return res;
}

int test_three(vi aa, int k) {
  int res = maxSubArrayNotGreaterThanK(aa, k);
  cout << res << "\n";
  return res;
}

int test_upper(set<int>& aa, int inp) {
  int res = upper(aa, inp);
  cout << res << "\n";
  return res;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 

  // Test find an element greater or equal than input.
  set<int> st = {-1, -2, 3, 5};
  test_upper(st, 3);

  // Test find the maximum submatrix.
  vvi aa = {
  {1, 2, -1, -4, -20}, 
  {-8, -3, 4, 2, 1}, 
  {3, 8, 10, 1, 3}, 
  {-4, -1, 1, 7, -6}};
  test_two(aa);

  // Test find the maximum sum that less or equal to k in an array.
  judge(test_three({1, 0, 1}, 1), 1);
  judge(test_three({2, 2, -1}, 3), 3);
  judge(test_three({2, 2, -1}, 0), -1);

  // Test find the maximum sum that less or equal to k in a matrix.
  judge(test({{1, 0, 1}, {0, -2, 3}}, 2), 2);
  judge(test({{2, 2, -1}}, 3), 3);
  judge(test({{2, 2, -1}}, 0), -1);

  return 0;
}
