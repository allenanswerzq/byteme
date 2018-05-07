#include <cstdio>
#include <stdio.h> // for using printf
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctype.h> // <cctype> isalpha isdigit
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>   // std:string std:stoi
#include <tuple>
#include <deque>
#include <stack>
#include <sstream>  // std:istringstream
#include <queue>
#include <iterator>

using namespace std;

void printVector(vector<int>& v) {
  printf("[ ");
  for (auto x:v)
      printf("%d ", x);
  printf("]\n");
}

void printMatrix(vector<vector<int>>& v) {
  printf("{\n");
  for (auto x:v)
    printVector(x);
  printf("}\n");
}

bool isPowerOfTwo(int x) {
  //return (x && !(x & (x-1)));
  return x* !(x&(x-1)) > 0;
}

int countOne (int n){
  while( n ){
    n = n&(n-1);
    count++;
  }
  return count;
}

char toupper( char a ) {
  return ((a >= 'a' && a <= 'z') ? a-('a'-'A') : a );
}

int main(int argc, char** argv) {
  return 0;
}

intminCostII(vector<vector<int>>& costs) {
  int n = costs.size();
  int m = costs[0].size();
  int ret = INT_MAX;
  vector<vector<int>> dp(n+1, vector<int>(m, 0));
  for (int i=1; i<=n; ++i) {  // for each house
    for (int j=0; j<m; ++j) { // for each color
      int pre = INT_MAX;
      for (int k=0; k<m; ++k)
        if (k != j)
          pre = min(pre, dp[i-1][k]);
      dp[i][j] = costs[i-1][j] + pre;
      ret = min(ret, dp[i][j]);
    }
  }
  return ret;
}

//There are a row of n houses, each house can be painted with one of the k colors. 
//The cost of painting each house with a certain color is different. 
//You have to paint all the houses such that no two adjacent houses have the same color.
//The cost of painting each house with a certain color is represented by a n x k cost matrix. 
//For example, costs[0][0] is the cost of painting house 0 with color 0; 
//costs[1][2] is the cost of painting house 1 with color 2, 
//and so on... Find the minimum cost to paint all houses.
int minCostII(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = costs.size(), k = costs[0].size();
    int m1 = 0, m2 = 0;           // m1 min value, m2 second min value
    vector<int> dp(k, 0);
    for (int i = 0; i < n; i++) { // Paint each house
        int t1 = m1, t2 = m2;
        m1 = m2 = INT_MAX;
        for (int j = 0; j < k; j++) { // Pick each color
            int pre = dp[j] == t1 ? t2 : t1;  // If last time we got min costs on color j for painting house i-1, 
                                              // now when we pick color j, we can only use second min costs of last time
                                              // becasue two adjcent house have different colors
            dp[j] = pre + costs[i][j];
            if (m1 <= dp[j]) m2 = min(m2, dp[j]);
            else m2 = m1, m1 = dp[j];
        }
    }
    return m1;
}