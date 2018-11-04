#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canCross(vector<int>& aa) { 
  int n;
  n = sz(aa);
  unordered_map<int, unordered_set<int>> mp;
  mp.insert({0, {0}}); 
  fora (p, aa) {
    fora (k, mp[p]) {
    if (k - 1)
      mp[p + k - 1].insert(k - 1);
    mp[p + k].insert(k);
    mp[p + k + 1].insert(k + 1);
    }
  }
  return sz(mp[aa.back()]);
  }
};

void test(vi aa) {
  Solution go;
  cout << go.canCross(aa) << "\n";
}

int main() {
   test({0, 1, 3, 5, 6, 8, 12, 17});
  test({0, 1, 2, 3, 4, 8, 9, 11});
  return 0;
}
