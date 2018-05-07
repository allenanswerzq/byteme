#include <stdio.h>
#include <iostream>
#include <vector>

int sum(vector<int>& A, int start, int end) {
	int sum = 0;
	for (int i=start; i<=end; ++i) 
		sum += A[i];
	return sum
}

// Of course TLE
// O(n2) complextity
int maxSubArray1(vector<int>& A) {
	int res = 0;
	for (int i=0; i<A.size(); ++i) 
		for (int j=i; j<A.size(); ++j) 
			res = max(sum(A, i, j), res);
	return res;	
}

// I dont totally understand this approach
int maxSubArray(vector<int>& A) {
	int res = INT_MIN;
	int sum = 0;
	for (int i=0; i<A.size(); ++i) {
		sum += A[i];
		res = max(sum, res);
		sum = max(sum, 0);
	}
	return res;
}
// dp approach
// dp(i) means maximum subarray ends with A[i]
// dp(i) = A[i] + dp(i-1) if dp(i-1) > 0
// 		   A[i]		      else 
int maxSubArray(vector<int>& A) {
	int n = A.size();
	int res = INT_MIN;
/*	int dp[n] = {0};
	dp[0] = A[0];	
	for (int i=1; i<n; ++i) {
		dp[i] = A[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
		res = max(res, dp[i]);	
	}
	*/
	int a = A[0];
	for (int i=1; i<n; ++i) {
		b = A[i] + (a > 0 ? dp[i-1] : 0);
		res = max(res, b);	
		a = b;
	}
	
	return res;
}
int main() 
{
}
