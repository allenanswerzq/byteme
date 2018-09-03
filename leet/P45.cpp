#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Transform this problem into a bfs problem.
	int bfs(vector<int>& aa, int start) {
	}

	// The greedy idea is that we jump to biggest value every time.
	int jump(vector<int>& aa) {
		int n = aa.size();
		if (n < 2) return 0;
		int steps = 0;
		for (int i = 0; i < n; ) {
			// Jump one step and find next pos we need to jump.
			steps++;	
			if (aa[i] + i >= n - 1) return steps;

			int maxDist = 0;
			int maxPos = 0;
			for (int j = i + 1; j <= i + aa[i]; ++j) {
				if (j + aa[j] > maxDist) {
					maxDist = j + aa[j];
					maxPos = j;
				}
			}
			i = maxPos;
		}
		return steps;
	}

	// DP approach 
	int jump1(vector<int>& aa) {
		int n = aa.size();
		int dp[n]; mst(dp, 0x7f);
		dp[0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; ++j) {
				if (j + aa[j] >= i) {
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[n - 1];
	}
};

void test(vector<int>& vv) {
	Solution go;
	int ret = go.jump(vv);
	trace(ret);
}

int main(int argc, char** argv) {
	test({1, 3, 2});
  return 0;
}
