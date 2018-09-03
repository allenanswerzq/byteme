#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	// It's worked
	// But i don't really know why.	
  int maxVacationDays3(vector<vector<int>>& flights, vector<vector<int>>& days) {
		int N = flights.size();
		int K = days[0].size();
		int dp[N];
		for (int i=0; i<N; ++i)
			dp[i] = INT_MIN;
		dp[0] = 0;

		for (int i=0; i<K; ++i) {
			int temp[N];
			for (int i=0; i<N; ++i)
				temp[i] = INT_MIN;
			for (int j=0; j<N; ++j) {
				for (int k=0; k<N; ++k) {
					if (j == k || flights[k][j] == 1) 
						temp[j] = max(temp[j], dp[k] + days[j][i]);
				}
			}
			for (int i=0; i<N; ++i)
				dp[i] = temp[i];
		}
		int ret = 0;
		for (auto v: dp)
			ret = max(ret, v);
		return ret;

	}
	// solution 2:
	// DP:  dp[i][j] max days of week i staying city j
	// dp[i][j] = max( dp[i-1][k] + days[j][i] ) k = 0...N-1 if we have flights from city k to j  
	// !!!NOTE: NOT TRUE by me
	// need review sometime
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
		int N = flights.size();
		int K = days[0].size();
		int dp[K][N] = {{INT_MIN}}; // k means week n means city
		dp[0][0] = 0;
		for (int i=0; i<K; ++i) {
			for (int j=0; j<N; ++j) {
				for (int k=0; k<N-1; ++k) {
					if (j==k || flights[k][j]==1) 
						dp[i][j] = max(dp[i-1][k] + days[j][i], dp[i][j]);			
				}	
			}
		}		
		
		int ret = 0;
		for (int j=0; j<N; ++j)
			if (dp[K][j] > ret) ret = dp[K][j];
		return ret;
				
	}	
	// IDEAS:
	// DFS. The idea is just try each possible city for every week and keep tracking the max vacation days. 
	// Time complexity O(N^K)
	int maxDays = 0, N = 0, K = 0;
  int maxVacationDays1(vector<vector<int>>& flights, vector<vector<int>>& days) {
		N = flights.size();
		K = days[0].size();
		cout << "City: " << N << endl;
		cout << "Weeks: " << K << endl;
		dfs(flights, days, 0, 0, 0);
		return maxDays;		
  }
private:
	void dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int curr, int week, int sum) {
		if ( week == K) {
			maxDays = max(maxDays, sum);
			return;
		}
		
		for (int dest=0; dest<N; ++dest) {
			if ( curr == dest || flights[curr][dest] == 1) {
				dfs(flights, days, dest, week+1, sum+days[dest][week]);
			}
		}
	}
};

void printMatrix(vector<vector<int> > &matrix)
{
  for(int i=0; i<matrix.size(); i++){
    printf("{");
    for(int j=0; j< matrix[i].size(); j++) {
      printf("%3d ", matrix[i][j]) ;
    }
    printf("}\n");
  }
  cout << endl;
}

int main(int argc, char** argv) {
	int m[][3] = {{0,1,1},{1,0,1},{1,1,0}}; 	
	int n[][3] = {{1,3,1},{6,0,3},{3,3,3}}; 

	vector<vector<int>> flights;
	vector<int> t;
	for (int i=0; i<3; i++) {
		t.push_back(m[i][0]);
		t.push_back(m[i][1]);
		t.push_back(m[i][2]);
		flights.push_back(t);
		t.clear();
	}
	printMatrix(flights);

	vector<vector<int>> days;
	for (int i=0; i<3; i++) {
		t.push_back(n[i][0]);
		t.push_back(n[i][1]);
		t.push_back(n[i][2]);
		days.push_back(t);
		t.clear();
	}
	printMatrix(days);
	Solution s;
	cout << "Max vacation days: " << s.maxVacationDays(flights, days) << endl;
	return 0;
}
