#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (auto x:v)
        cout << x << " ";
    cout <<"] " << endl;
}

// perfect it accepted
int uniquePathsWithObstacles(vector<vector<int>>& A) {
	int m = A.size(), n = A[0].size();
	vector<vector<int>> dp(m, vector<int> (n, 1));
	for (int i=1; i<m; ++i)
		for (int j=1; j<n; ++j) {
			if(!dp[i-1][j] && !dp[i][j-1])
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			else
				dp[i][j] = dp[i-1][j] == 1 ? 0: dp[i-1][j]
						 + dp[i][j-1] == 1 ? 0: dp[i][j-1];
		}	
	return dp[m-1][n-1];
}

// optimized for extra space
// NOTE: vector variable can directly assign
// like a = b or
// swap like swap(a, b)
int uniquePaths(int m, int n) {

}

int main(int argc, char** argv) {
    return 0;
}
