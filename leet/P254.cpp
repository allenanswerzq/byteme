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

// Numbers can be regarded as product of its factors. For example,
// 8 = 2 x 2 x 2;
  // = 2 x 4.
// Write a function that takes an integer n and return all possible combinations of its factors.
// Note:
// You may assume that n is always positive.
// Factors should be greater than 1 and less than n.

void dfs(vector<vector<int>> &ret, vector<int> &path, int n) {
  int i = path.empty() ? 2 : path.back();
  for (; i<=n/i; ++i) {
    if (n % i == 0) {
      path.push_back(i);
      path.push_back(n/i);
      ret.push_back(path); 

      path.pop_back();
      dfs(ret, path, n/i);
      path.pop_back();
    }
  }  
}

vector<vector<int>> getFactors(int n) {
  vector<vector<int>> ret;
  vector<int> path;
  dfs(ret, path, n);
  return ret;
}
