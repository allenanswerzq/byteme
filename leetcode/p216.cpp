#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(vi& path, vvi& res, int k, int goal, int start) {
    if (path.size() == k && goal == 0) {
      res.push_back(path);
    }

    for (int i = start; i <= 9; ++i) {
      path.push_back(i);
      dfs(visit, path, res, k, goal - i, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int goal) {
    vvi res;
    vi path;
    dfs(path, res, k, goal, 1);
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
