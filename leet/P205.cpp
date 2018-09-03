#include<bits/stdc++.h>
using namespace std;

#define mst(x, a) memset(x, a, sizeof(x))

bool isIsomorphic(string s, string t) {
  int aa[256];
  int bb[256];
  mst(aa, 0);
  mst(bb, 0);
  for (int i=0; i<s.size(); ++i) {
  if ( !aa.count(s[i]) && !bb.count(t[i]) ) {
  aa[s[i]] = t[i];
  bb[t[i]] = s[i];
  } else {
  if (aa[s[i]] != t[i] || bb[t[i]] != s[i]) 
  return false; 
  }
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
