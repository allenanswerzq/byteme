#include<bits/stdc++.h>using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  void bt(vi& aa, vi& path, vvi& res, vector<bool>& visit) {
    int n = aa.size();
    if (path.size() == n) {
      res.push_back(path);
      return;
    } 

    for (int i = 0; i < n; ++i) {
      if (visit[i]) continue;
      if (i > 0 && aa[i] == aa[i-1] && visit[i-1]) continue;
      visit[i] = 1;
      path.push_back(aa[i]);
      bt(aa, path, res, visit); 
      path.pop_back();
      visit[i] = 0;
    }
  }

  vector<vector<int>> permute(vector<int>& aa) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visit(aa.size(), 0);
    sort(aa.begin(), aa.end());
    bt(aa, path, res, visit);
    return res;
  }
};

void test(vi aa) {
  Solution go;
  vvi ret = go.permute(aa); 
  fora (r, ret) {
    pvi(r);
  }
}    

int main() {
  test({1, 1, 2});
  return 0;
}
