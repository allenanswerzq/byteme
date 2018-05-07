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

// Accepted
// DP
int numSquaresDP(int n) {
  int sq = 0;
  vector<int> dp(n+1, INT_MAX);
  for (int i=1; i<=n; ++i) {
    if (i>sq*sq && i<(sq+1)*(sq+1)) {
      int t = sq;
      while (t > 0) { 
        dp[i] = min(dp[i], dp[i-t*t]+dp[t*t]);
        t--;
      }
    } else if (i == (sq+1)*(sq+1)) {
      dp[i] = 1;
      sq += 1;
    }
  }
  return dp[n];
}

// BFS
int numSquares(int n) {
  vector<int> squares;  
  int k = 1;
  while (k*k <= n) {
    squares.push_back(k*k);
    k++;
  }

  queue<int> q;
  int cnt = 0;
  q.push(n);
  while (!q.empty()) {
    cnt++;
    int size = q.size();
    for (int i=0; i<size; ++i) {
      int val = q.front(); q.pop();
      for (auto square: squares) {
        if (val == square) return cnt;
        if (val < square) break;
        q.push(val-square);
      }
    }
  }
  return cnt;
}

int main() {
  int x;
  cin >> x;
  cout << numSquares(x);
  return 0;
}