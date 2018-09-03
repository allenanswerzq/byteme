#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Solution {
public:

  bool check(string a, string b) {
  int n = a.find(b);
  return n == a.size()-b.size();
  }

  int minimumLengthEncoding(vector<string>& words) {
  int n = SZ(words);
  sort(ALL(words), [](string a, string b) {
  return a.size() > b.size();
  });

  vector<int> dp(n, 0);
  dp[0] = words[0].size() + 1;

  for (int i=1; i<n; ++i) {
  int flag = 0;
  for (int j=0; j<i; ++j) {
    if (check(words[j], words[i])) {
    dp[i] = dp[i-1];
    flag = 1;
    break;
    } 
  }
  if (!flag)
    dp[i] = dp[i-1] + words[i].size() + 1; 
  }
  return dp[n-1];
  }
};
