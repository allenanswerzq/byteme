#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// bracktracking
// Accepted
void bt(vector<vector<int>>& res, vector<int>& ans, int n, int k, int x) {
  if(ans.size() == k) {
  res.push_back(ans);
  }else {
  for (int i=x; i<=n; ++i) {
    ans.push_back(i);
    bt(res, ans, n, k, i+1);
    ans.pop_back();
   }
  }
}

vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> res;    
  vector<int> ans;
  bt(res, ans, n, k, 1);
  return res;
}

int main(int argc, char** argv) {
  return 0;
}
