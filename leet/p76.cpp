#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}


string minWindow(string s, string t) {
  int m = sz(s), n = sz(t);
  if (m < n) return "";
  int pat[256] = {};
  int src[256] = {};
  fori (i, 0, n) {
  ++pat[t[i]];
  }
  int lo = 0, ix = -1, len = (1<<30); 
  int count = 0;
  fori (hi, 0, m) {
  ++src[s[hi]]; 
  if (pat[s[hi]] && src[s[hi]] <= pat[s[hi]]) 
    ++count;
  if (count == n) {
    while (src[s[lo]] > pat[s[lo]] || !pat[s[lo]]) {
    if (src[s[lo]] > pat[s[lo]])
      src[s[lo]]--; 
    ++lo;
    }
    int nlen = hi - lo + 1;
    // cout << lo << " " << hi << " " << nlen << " " << ix << endl;
    if (nlen < len) {
    len = nlen;
    ix = lo;
    }
  } 
  }
  return ix == -1 ? "" : s.substr(ix, len);
}

int main(int argc, char** argv) {
  string a = "ADOBECODEBANC";
  string b = "ABC";
  string r = minWindow(a, b);
  cout << r << endl;
  return 0;
}
