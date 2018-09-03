#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

// fantistic solution
int numTrees(int n) { 
  vector<int> dp(n+1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (x=2; x<=n; ++x) {      // for each x
    for (y=1; y<=x; ++y) {  // select each y that less equal x as root
      dp[x] += dp[y-1] * dp[x-y];
    }
  }
  return dp[n];
}

int main(int argc, char** argv) {
  return 0;
}
