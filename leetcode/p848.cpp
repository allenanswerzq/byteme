#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shiftingLetters(string S, vector<int>& shifts) {
  int n = sz(shifts);
  ford(i, n-2, -1) {
    shifts[i] = (shifts[i] % 26 + shifts[i+1] % 26) % 26;
  }

  fori(i, 0, n) {
    S[i] = 'a' + (S[i] - 'a' + shifts[i]) % 26;
  }     
  return S;
  }
};

int main() {
 
  return 0;
}
