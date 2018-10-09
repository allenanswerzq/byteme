#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> gg;
  vector<int> color;
  vector<int> res;

  void makeGraph(int n, vector<pair<int, int>>& pre) {
    gg.resize(n);
    color.resize(n);
    for (auto& p : pre) {
      // After finished p.second we start to do p.first
      gg[p.second].push_back(pair.first);
    }
  }

  bool dfs(int i, vector<int>& res) {
    if (color[i] == 2) return false;
    if (color[i] == 1) return true;
    color[i] = 1;
    for (auto nxt : gg[i]) 
      if (dfs(nxt, res) == true) 
        return false;
    res.push_back(i);
    color[i] = 2;
   return false;
  }

  vector<int> findOrder(int numCourses, vector<pair<int, int>>& pre) {
    makeGraph(numCourses, pre); 
    for (int i = 0; i < numCourses; ++i)
      // If there is a cycle return empty vector
      if (dfs(i, res) == true) 
        return {}; 
    
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char** argv) {
  return 0;
}
