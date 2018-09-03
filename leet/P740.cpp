#include<bits/stdc++.h>

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

int deleteAndEarn(vector<int>& a) {
  int n = 10001;
  vector<int> cnt(n, 0);
  for (auto x : a)
  cnt[x]++;

  vector<int> dp(n, 0); // each number in range of [1, 10000]
  for (int i=1; i<n; ++i) {
  // Two choices here, first is that we dont pick current number 
  int earn_one = dp[i-1];
  // And second choice is that we pick current number so we need to delete all points we got in previous step
  int earn_two = cnt[i] * i + (i-2 >= 0 ? dp[i-2]: 0);

  dp[i] = max(earn_one, earn_two);
  }
  return dp[n-1];
}
