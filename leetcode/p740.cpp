#include<bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& a) {
  int n = 10001;
  vector<int> cnt(n, 0);
  for (auto x : a)
  cnt[x]++;

  vector<int> dp(n, 0); // each number in range of [1, 10000]
  for (int i=1; i<n; ++i) {
  // Two choices here, first is that we dont pick current number 
  int earn_one = dp[i-1];
  // And second choice is that we pick current number so we need to delete all points we got in previous step
  int earn_two = cnt[i] * i + (i-2 >= 0 ? dp[i-2]: 0);

  dp[i] = max(earn_one, earn_two);
  }
  return dp[n-1];
}
