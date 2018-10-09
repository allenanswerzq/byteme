#include<bits/stdc++.h>
using namespace std;

// Given two strings S and T, 
// determine if they are both one edit distance apart.

class Solution {
public:
  bool isOneEditDistance(string ss, string tt) {
    int m = sz(ss), n = sz(tt);
    fori (i, 0, min(m, n)) {
      if (ss[i] != tt[i]) {
        // Replace
        if (m == n) return ss.substr(i) == tt.substr(i); 
        // Deletion
        else if (m > n) return ss.substr(i + 1) == tt.substr(i);
        // Insertion
        else return ss.substr(i) == tt.substr(i + 1);
      } 
    }
    return abs(m - n) == 1;
  }
};

int main(int argc, char** argv) {
  return 0;
}
