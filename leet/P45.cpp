#include <cstdio>  
#include <cmath>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
            cout << x << " ";
    cout <<"] " << endl;
}

// that's not true
int dfs(vector<int>& A, int start) {
	int steps = 1000;
	int n = A.size();
	if (start == n-1) return 0;
	if (start + A[start] == n-1) return 1;
	for (int i=1; i<=A[start]; ++i) {
		steps = min(steps, dfs(A, start+i) + i);
	}
	return steps;
}

// Perfect!!!
// It accepted. the greedy idea is we jump to biggest value every time
int jump(vector<int>& A) {
	int n = A.size();
	if (n<2) return 0;
	int steps = 0;
	for (int i=0; i<n; ) {
		steps++;	// jumps one step and find next pos we need to jump
					// and then jump
		if (A[i]+i >= n-1) return steps;

		int maxDist = 0;
		int maxPos = 0;
		for(int j=i+1; j<=i+A[i]; ++j) {
			if (j+A[j] > maxDist) {
				maxDist = j+A[j];
				maxPos = j;
			}
		}
		i = maxPos;
	}
	return steps;
}

// DP approach 
// i think it worked but TLE
int jump1(vector<int>& A) {
	int n = A.size();
	int dp[n] = {0};
	for (int i=1; i<n; i++) {
		int steps = INT_MAX;
		for (int j=0; j<i; ++j) {
			if(A[j] + j >= i)
				steps = min(steps, dp[j] + 1);
		}
		dp[i] = steps;
	}
	return dp[n-1];
}

int main(int argc, char** argv) {
	int n[] = {1, 3, 2};
	vector<int> v(n, n+sizeof(n)/sizeof(int));
	cout << jump(v) << endl;
    return 0;
}
