#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[ ";
    for (int x:v)
      cout << x << " ";
    cout <<"] " << endl;
}

// transform it into a bfs problem.
int bfs(vector<int>& A, int start) {
}

// Perfect!!!
// It accepted. the greedy idea is we jump to biggest value every time
int jump(vector<int>& A) {
	int n = A.size();
	if (n<2) return 0;
	int steps = 0;
	for (int i=0; i<n; ) {
		steps++;	// jumps one step and find next pos we need to jump
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
int jump1(vector<int>& A) {
	int n = A.size();
	int dp[n] = {0};
	for (int i=1; i<n; i++) {
		int steps = INT_MAX;
		for (int j=0; j<i; ++j) {
			if (j+A[j] >=i && dp[j] != INT_MAX) {
				steps = min(steps, dp[j] + 1);
				break;
			}
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
