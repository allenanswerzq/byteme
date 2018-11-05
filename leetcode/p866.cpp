#include <bits/stdc++.h>
using namespace std;

bool prime(int aa) {
  if (aa == 1) return 0;
  for (int i = 2; i * i <= aa; ++i)
    if (aa % i == 0) return 0;
  return 1;
}

bool palind(int aa) {
  string s = to_string(aa);
  int lo = 0, hi = sz(s)-1;
  while (lo < hi) {
    if (s[lo] != s[hi]) return 0;
    ++lo; --hi;
  }
  return 1;
}

class Solution {
public:
  int primePalindrome(int aa) {
    uint up = (1 << 31);
    // trace(aa, up);
    fori (i, aa, up) {
      // trace(aa, i, prime(i));
      if (prime(i) && palind(i))
      return i;
    }
    return 0;
  }
};

int main() {
  return 0;
}
