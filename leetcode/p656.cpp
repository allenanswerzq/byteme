#include <bits/stdc++.h>
using namespace std;

vector<int> cheapestJump(vector<int>& A, int B) {
  int n = A.size();
  vector<int> dp(n, 2000000);
  vector<int> steps(n+1, 0);
  dp[0] = A[0];
  for (int i=1; i<n; ++i) {
    if (A[i] == -1) {
      if (i == n-1) return {};
      else {
        continue;
      }
    }
    for (int j=i-1; j>=i-B; --j)
      if (j>=0 && dp[j] + A[i] <= dp[i]) {
        dp[i] = dp[j] + A[i];
        steps[i+1] = j+1;
      }
  }

  if (dp[n-1] >= 2000000) return {};
  vector<int> res;
  int x = n-1;
  res.push_back(n);
  while (steps[x]) {
    res.insert(res.begin(), steps[x]);
    x = steps[x] - 1;
  }

  return res;
}

int main() {
  return 0;
}
