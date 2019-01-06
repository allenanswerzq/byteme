#include <bits/stdc++.h>
using namespace std;

// Hash Table Approach
int findLHS(vector<int>& A) {
  map<int, int> cnt;
  int ret = 0;
  for (auto x : A)
    cnt[x]++;

  /*for (auto it=cnt.begin(); it!=cnt.end(); ++it) {
    if (cnt.find(it->first + 1) != cnt.end()) {
      ret = max(ret, it->second + cnt[it->first + 1]);
    }
  }*/

  for (auto x:cnt) {
    if(cnt.find(x.first+1) != cnt.end()) {
      ret = max(ret, x.second+cnt[x.first+1]);
    }
  }
  return ret;
}

int main() {
  return 0;
}
