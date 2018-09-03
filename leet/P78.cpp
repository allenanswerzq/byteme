#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// backtracking
// iterative
// bit-manipulation
void bt(vector<vector<int>>& res, vector<int>& ans, vector<int>& A, int x) {
  res.push_back(ans);
  for (int i=x; i<A.size(); ++i) {
  ans.push_back(A[i]);
  bt(res, ans, A, i+1);
  ans.pop_back();
  }
}

vector<vector<int>> subsets(vector<int>& A) {
  vector<vector<int>> res;
  vector<int> ans;
  sort(A.begin(), A.end());
  bt(res, ans, A, 0);
  return res; 
}

int main(int argc, char** argv) {
  return 0;
}
