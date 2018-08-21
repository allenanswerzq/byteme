#include<bits/stdc++.h>
using namespace std;



const double eps = 1e-9;
int dcmp(double x, double y = 0, double tol = eps) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool canPartitionRecu(vi& bb, int goal, int n) {
  // Returns true if the sum of any subset from range [0...n-1] can equal goal.
  // if (goal == 0) return 1;
  // if (n == 0 && goal) return 0;
  if (n == 1) return goal == bb[n-1];
  if (bb[n-1] > goal)
    return canPartitionRecu(goal, n-1);
  return canPartitionRecu(goal, n - 1) || 
         canPartitionRecu(goal - bb[n-1], n - 1);
}

const int M = 10000;
const int N = 300;
// dp[i][j] denotes whether or not there exist a subset in the range of [0..j-1]
// such that the sum of that subset equals `i`.
int dp[M][N];
bool canPartitionDP(vi& bb, int goal) {
  int n;
  n = sz(bb);
  mst(dp, 0);
  fori (i, 0, goal+1) {
    // Length of the array which might contain the subset 
    // that its sum can equal to goal i.
    fori (j, 0, n+1) { 
      if (i == 0 && j == 0)
        dp[0][0] = 1;
      else if (i == 0) 
        dp[0][j] = 1;
      else if (j == 0)
        dp[i][0] = 0;
      else {
        dp[i][j] = dp[i][j-1]; // Not include the last element.
        if (i >= bb[j - 1])
          dp[i][j] = dp[i][j] || dp[i - bb[j - 1]][j - 1];
      }
    } 
  }

  return dp[goal][n];;
} 

class Solution {
public:
  bool canPartition(vector<int>& aa) {
    bb = aa;
    int n, sum;
    n = sz(aa);
    if (n <= 1) return 0; 
    sum = accumulate(all(aa), 0);
    if (sum % 2) return 0;
    // return canPartitionRecu(sum / 2, n);
    return canPartitionDP(aa, sum / 2);
  }
};

void test(vi aa) {
  Solution go;
  int x = go.canPartition(aa);
  cerr(x);
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed; 
  test({1, 5, 11, 5});
  return 0;
}
