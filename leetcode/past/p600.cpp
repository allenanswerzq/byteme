#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findIntegers(int aa) {
    vi bits;
    for (aa; aa > 0; aa >>= 1)
      bits.pb(aa & 1);
    int n = sz(bits);
    int a[n], b[n];

    mst(a, 0);
    mst(b, 0);

    a[0] = b[0] = 1;
    fori (i, 1, n) {
      a[i] = a[i-1] + b[i-1];
      b[i] = a[i-1];
    }

    int res = a[n-1] + b[n-1];
    ford (i, n-2, -1) {
      if (bits[i] == 1 && bits[i+1] == 1) break;
      else if (bits[i] == 0 && bits[i+1] == 0) res -= b[i];
    }
    return res;
  }
};

void test() {
  Solution go;
  int r;
  output(r);
}

int main() {
  return 0;
}
