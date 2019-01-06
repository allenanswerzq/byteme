#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  void bt(vi& aa, int target, vi& path, vvi& ret, int start) {
    if (target == 0) {
      ret.push_back(path);
    } else {
      for (int i = start; i < aa.size() && target >= aa[i]; ++i) {
        if (i > start && aa[i] == aa[i - 1]) continue;
          path.push_back(aa[i]);
          bt(aa, target - aa[i], path, ret, i+1);
          path.pop_back();
        }
    }
  }

  vvi combinationSum(vector<int>& aa, int target) {
    vvi ret;
    vi path;
    sort(aa.begin(), aa.end());
    bt(aa, target, path, ret, 0);
    return ret;
  }
};

void test(vi aa) {
  Solution go;
  vvi ret = go.combinationSum(aa);
  for (auto& r : ret) {
    pvi(ret);
  }
}

int main() {
  test({10, 1, 2, 7, 6, 1, 5}, 8);
  return 0;
}
