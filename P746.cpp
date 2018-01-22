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

int minCostClimbingStairs(vector<int>& cost) {
  int n = cost.size();
  vector<int> dp(n+1, 0); // dp[i] denotes total cost for reaching ith postion, so dp[n] is the result we wanted
  for (int i=2; i<=n; ++i) {
    dp[i] = min(dp[i-1] + cost[i-1],  //  
                dp[i-2] + cost[i-2]); 
  }
  return dp[n];
}