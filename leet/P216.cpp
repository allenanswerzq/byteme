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
// 100 & 011 = 000
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
// backtrack
void dfs(vector<int>& path, vector<vector<int>>& res, int k, int n, int start) {
  if (path.size()==k && n==0) {
    res.push_back(path);
  }
  for(int i=start; i<=9; ++i) {
    path.push_back(i);
    dfs(visit, path, res, k, n-i, i+1);
    path.pop_back();
  }

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> res;
  vector<int> path;
  dfs(path, res, k, n, 1);
  return res;
}

// bit manipulation
// 2**9 --> 1
// count the number of one as num
// if num == k
// check whether sum on every one postion equals n or not
int main(int argc, char** argv) {
    return 0;
}
