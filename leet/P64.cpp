#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}
// perfect!!!
// accepted
int minPathSum(vector<vector<int>>& grid) {
	int m=grid.size(), n=grid[0].size();
	vector<vector<int>> dp(m+1, vector<int> (n+1, INT_MAX));
	dp[0][1] = 0;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
		}	
	return dp[m][n];
}
// optimized for extra space
int minPathSum(vector<vector<int>>& grid) {
	int m=grid.size(), n=grid[0].size();
	vector<int> dp(n+1, INT_MAX);
	dp[1] = 0;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++) {
			dp[j] = min(dp[j], dp[j-1]) + grid[i-1][j-1];
		}	
	return dp[n];
}

int main(int argc, char** argv) {
  return 0;
}
