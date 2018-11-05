#include <bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int p1, p2, k1, k2;
    p1 = p2 = k1 = k2 = 0;
    // Go through s1 n1 times.
    while (p1 < n1) {
      if (s1[k1] == s2[k2]) {
        ++k2;
        if (k2 == sz(s2)) {
          k2 = 0; ++p2;
        }
      }
      ++k1;
      if (k1 == sz(s1)) {
        k1 = 0;
        ++p1;
      }
    }
    return p2 / n2;
  }
};

int main() {
  return 0;
}
