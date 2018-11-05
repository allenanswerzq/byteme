#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  // backtracking
  // iterative
  // bit-manipulation
  void bt(vvi& res, vi& path, vi& aa, int x) {
    res.push_back(path);
    for (int i = x; i < aa.size(); ++i) {
      path.push_back(aa[i]);
      bt(res, path, aa, i + 1);
      path.pop_back();
    }
  }

  vvi subsets(vector<int>& aa) {
    vi path;
    vvi res;
    sort(aa.begin(), aa.end());
    bt(res, path, aa, 0);
    return res; 
  }
};

int main() {
  return 0;
}
