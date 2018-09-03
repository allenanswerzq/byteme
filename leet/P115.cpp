#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

int numDistinct(string s, string t) {
  int n=s.size(), m=t.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); 
  // Note: boundary case
  for (int i=0; i<n; ++i)
    dp[0][i] = 1;
  // dp[i][j] t[1...i] s[1...j]
  for (int i=1; i<=m; ++i) {
    for (int j=1; j<=n; ++j) {
      dp[i][j] = s[j-1]==t[i-1] ? dp[i][j-1]+dp[i-1][j-1] : dp[i][j-1];
      //printf("%d ", dp[i][j]);
    }
    //printf("\n");
  }
  return dp[m][n];
}

int numDistinct(string s, string t) {
  int n=s.size(), m=t.size();
  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
  // dp[i][j] s[0...i] t[0....j] 
  for (int i=0; i<n; ++i)
    dp[i][0] = 1;
  for (int i=1; i<=m; ++i) 
    for (int j=1; j<=n; ++j) {
      //dp[j][i] = s[j-1] == t[i-1] ? dp[j-1][i-1]+dp[j-1][i] : dp[j-1][i];
      dp[j][i] = dp[j-1][i] + (s[j-1]==t[i-1] ? dp[j-1][i-1] : 0);
    }
  return dp[n][m];
}

// optimized for space
int numDistinct(string s, string t) {
}

int main(int argc, char** argv) {
  return 0;
}
