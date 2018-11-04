#include<bits/stdc++.h>
using namespace std;
// TODO
class Solution {
public:
  int minSteps(int n) {
    int dp[n + 1];
    mst(dp, 0);
    fori (i, 2, n+1) {
      dp[i] = i;
      ford (j, i - 1, 1) {
        if (i % j == 0) {
          dp[i] = dp[j] + i / j;
          break;
        }
      }
    }
    return dp[n];
  }
};

void test() {
  Solution go;
  int r;
  output(r);
}

int main() {
  return 0;
}
