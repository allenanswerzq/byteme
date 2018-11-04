#include<bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string A, string B) {
  string t = ""; int k = 0;
  while (t.size() < B.size()) {
    t += A;
    ++k;
  }
  if (t.find(B) != string::npos) return k;

  t += A; ++k;
  if (t.find(B) != string::npos) return k;
  return -1;
}

int main() {
  return 0;
}
