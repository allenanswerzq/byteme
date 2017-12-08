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

//Given a list of houses and the cost of painting each house, 
//the houses can be painted in three colors RED, GREEN and BLUE, 
//two neighboring houses can’t be painted in the same color, 
//calculate the total minimum cost for painting all houses.


// Input contains N rows and each row have three costs with respct to three colors 
int minCost(vector<vector<int>>& costs) {
  int n = costs.size();
  for (int i=1; i<n; ++i) {
    costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
    costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
    costs[i][2] += min(costs[i-1][0], costs[i-1][1]);
  }
  return n==0 ? 0: min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]) 
}

// Also a very good python approach
def minCost(self, costs):
    prev = [0] * 3
    for now in costs:
        prev = [now[i] + min(prev[:i] + prev[i+1:]) for i in range(3)]
    return min(prev)