#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
  // NOTE: difference between pointer vs reference
  // http://www.embedded.com/electronics-blogs/programming-pointers/4023307/References-vs-Pointers
  void bt(vi& aa, int target, vi& path, vvi& ret, int start) {
  if (target == 0) {
  		ret.push_back(path);
  } else {
    for (int i = start; i < aa.size() && target >= aa[i]; ++i) {
    path.push_back(aa[i]);
    bt(aa, target - aa[i], path, ret, i);     
    path.pop_back();
    }
   }
  }

  vector<vector<int>> combinationSum(vector<int>& aa, int target) {
  sort(aa.being(), aa.end());
  vector<vector<int>> ret;
  vector<int> path;
  bt(aa, target, path, ret, 0);    
  return ret;
  }
  
};

int main(int argc, char** argv) {
  return 0;
}
