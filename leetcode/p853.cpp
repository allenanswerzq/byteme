#include<bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int carFleet(int target, vector<int>& aa, vector<int>& bb) {
    vector<pii> a;
    int n = sz(aa);
    if (n == 1) return 1;

    fori(i, 0, n)  {
      a.pb({aa[i], bb[i]});
    }

    sort(all(a));

    int res = 0;
    ford (i, n-1, -1) {
    }
    return res;
  }
};

int main() {
  return 0;
}
