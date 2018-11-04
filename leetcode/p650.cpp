#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

int minSteps(int n) {
  int N = 1001;
  vector<int> dp(N, INT_MAX);
  dp[1] = 0;
  for (int i=1; i<N; ++i) {
    for (int j=2*i; j<N; j+=i) 
      dp[j] = min(dp[j], dp[i] + j/i);
  }
  return dp[n];
}

int main() {
  return 0;
}
