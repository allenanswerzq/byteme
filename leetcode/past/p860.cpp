#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int>& aa) {
    int a, b, c;
    a = b = c = 0;
    fori (i, 0, sz(aa)) {
      // trace(i);
      if (aa[i] == 5) ++a;
      else if (aa[i] == 10) {
        if (a <= 0) return 0;
        ++b; --a;
      } else if (aa[i] == 20) {
        if (a < 1 && b > 1) return 0;
        if (a < 3 && b < 1) return 0;

        if (b == 0 && a>=3) {
          a -= 3;
        } else if (b > 0) {
          --b; --a;
        }
      }
    }
    return 1;
  }
};

int main() {
  return 0;
}
