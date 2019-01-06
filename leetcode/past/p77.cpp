#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  void bt(vvi& res, vi& ans, int n, int k, int x) {
    if(ans.size() == k) {
      res.push_back(ans);
    } else {
      for (int i = x; i <= n; ++i) {
        ans.push_back(i);
        bt(res, ans, n, k, i + 1);
        ans.pop_back();
       }
    }
  }

  vvi combine(int n, int k) {
    vector<vector<int>> res;    
    vector<int> ans;
    bt(res, ans, n, k, 1);
    return res;
  }
};

int main() {
  return 0;
}
