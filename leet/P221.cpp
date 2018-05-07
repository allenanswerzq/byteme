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
  return (x && !(x & (x-1)));
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

int maximalSquare(vector<vector<char>>& matrix) {
  if (matrix.size() <= 0) return 0;
  int m = matrix.size();
  int n = matrix[0].size();
  int mx = 0;
  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i=0; i<m; ++i) {
    dp[i][0] = matrix[i][0] - '0';
    mx = max(mx, dp[i][0]);
  }

  for (int i=0; i<n; ++i) {
    dp[0][i] = matrix[0][i] - '0';
    mx = max(mx, dp[0][i]);
  }

  for (int i=1; i<m; ++i) 
    for (int j=1; j<n; ++j)
      if (matrix[i][j] == '1') {
        dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        mx = max(mx, dp[i][j]);
      }
  return mx*mx;
}

int main(int argc, char** argv) {
  return 0;
}
