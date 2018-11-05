#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool buddyStrings(string aa, string bb) {
    int a, b;
    a = sz(aa), b = sz(bb);
    if (a != b) return 0;
    vector<pii> two;
    fori (i, 0, a) {
      if (aa[i] != bb[i])
      two.pb({aa[i], bb[i]});
    }

    int n = sz(two);
    if (n == 0) {
      // Note: declare and reset a array.
      int cnt[26] = {};
      fori (i, 0, a) {
        cnt[aa[i] - 'a']++;
        if (cnt[aa[i] - 'a'] > 1) return 1;
      }
      return 0;
    }
    if (n != 2) return 0;
    return two[0].fi == two[1].se && two[0].se == two[1].fi;
  }
};

int main() {
  return 0;
}
