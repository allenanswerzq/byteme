#include<bits/stdc++.h>
using namespace std;

set<string> generate(string a) {
  set<string> res;
  if (sz(a) <= 1) {
    res.insert(a);
    return res;
  }

  char ch = a[0];
  set<string> st = generate(a.substr(1));
  fora (s, st) {
    fori (i, 0, sz(s)+1) {
      string b(s);
      b.insert(b.begin()+i, ch);
      res.insert(b);
    }
  }
  return res;
}

int main() {
  return 0;
}
