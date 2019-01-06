#include <bits/stdc++.h>
using namespace std;

string strip(string inp) {
  int n = sz(inp);
  char stk[n];
  int k = 0;
  fori(i, 0, n) {
    if (inp[i] == '#') {
      if (k > 0) --k;
    } else {
      stk[k++] = inp[i];
    }
  }
  string res = "";
  fori(i, 0, k) res += stk[i];
  return res;
}

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    string a = strip(S);
    string b = strip(T);
    return a == b;
  }
};

int main() {
  return 0;
}
