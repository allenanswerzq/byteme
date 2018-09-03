#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& a) {
  const int MOD = 1000000007;
  int n = a.size();
  sort(ALL(a));
  unordered_map<int, int> mp;
  for (int i=0; i<n; ++i)
  mp[a[i]] = i;

  vector<long> dp(n+1, 0);
  for (int i=0; i<n; ++i) {
  int ans = 1;
  for (int j=0; j<i; ++j) {
    if (a[i] % a[j] == 0) {
    auto it = mp.find(a[i] / a[j]);
    if (it != mp.end())
    // Error
    // ans += (dp[j] * dp[it->second]) % MOD; 
    // Right
    ans = (ans + dp[j] * dp[it->second]) % MOD;
    }
  }
  dp[i] = ans;
  }

  long res = 0;
  for (auto p : dp)
  res += p;
  return  res % MOD;
  }
};
