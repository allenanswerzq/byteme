#include<bits/stdc++.h>
using namespace std;

// backtrack
void dfs(vector<int>& path, vector<vector<int>>& res, int k, int n, int start) {
  if (path.size()==k && n==0) {
  res.push_back(path);
  }

  for(int i=start; i <= 9; ++i) {
  path.push_back(i);
  dfs(visit, path, res, k, n-i, i+1);
  path.pop_back();
  }

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
