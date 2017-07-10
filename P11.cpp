#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
// dp soultion
//
int maxArea(vector<int>& h) {
	int n = h.size();
	//int dp[n][n] = {0};
	int dp[n] = {0};
	int ret = 0;
	for (int j=n-1; j>=0; --j)
		for (int i=n-2; i>=0; --i) {
			dp[i] = max(dp[i+1], (j-i)*(h[i]<=h[j] ? h[i]:h[j]));
			//dp[i][j] = max(dp[i+1][j], (j-i)*(h[i]<=h[j] ? h[i]:h[j]));
			ret = max(ret, dp[i]);
		}

	return ret;

}

// burte force 
// time limit exceeded
int maxArea1(vector<int>& h) {
	int ret = 0;
	for (int i=0; i<h.size(); ++i)
		for (int j=i+1; j<h.size(); ++j) {
			ret = max(ret, (j-i) * (h[i] <= h[j] ? h[i] : h[j]));
		}
	return ret;
}

int main() {
	vector<int> h({2, 1, 2});
	cout << maxArea(h) << endl;
	return 0;
}
