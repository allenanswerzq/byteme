#include<bits/stdc++.h>using namespace std;

class Solution {
public:
  int maxVacationDays3(vvi& flights, vvi& days) {
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

  int maxVacationDays(vvi& flights, vvi& days) {
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
  // DFS. The idea is just try each possible city for every week and keep
  // tracking the max vacation days.
  // Time complexity O(N^K)
  int maxDays = 0, N = 0, K = 0;
  int maxVacationDays1(vvi& flights, vvi& days) {
    N = flights.size();
    K = days[0].size();
    cout << "City: " << N << endl;
    cout << "Weeks: " << K << endl;
    dfs(flights, days, 0, 0, 0);
    return maxDays;
  }

private:
  void dfs(vvi& flights, vvi& days, int curr, int week, int sum) {
    if (week == K) {
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

int main() {
  return 0;
}
