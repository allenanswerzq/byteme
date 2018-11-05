#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string pushDominoes(string aa) {
    int n = sz(aa);
    char pre = 0;
    int prepos = -1;
    fori (i, 0, n) {
      char cur = aa[i];
      if (cur == 'L') {
        if (pre == 'R') {
          int half = (prepos + i + 1 ) / 2 - prepos;
          fori(k, 0, half) {
            aa[prepos + k] = 'R';
            aa[i - k] = 'L';
          }
        } else {
          fori(k, prepos+1, i) aa[k] = 'L';
        }
        pre = 'L';
        prepos = i;
      } else if (cur == 'R') {
        if (pre == 'R') {
          fori(k, prepos, i)
          aa[k] = 'R';
        }
        pre = 'R';
        prepos = i;
      }
    }
    // The ending `R`.
    if (pre == 'R')
      fori(k, prepos, sz(aa)) aa[k] = 'R';
    return aa;
  }
};

int main() {
  return 0;
}
