#include<bits/stdc++.h>

using namespace std;

// Accepted
string shortestPalindrome(string s) {
  string r = "";
  for (auto c : s)
  r = c + r;    // reverse input string
  for (int i=0; i<r.size(); ++i) {
  string t = r.substr(0, i);
  string o = r.substr(i); 
  if (s.substr(0, o.size()) == o)
    return t + s;
  }
  return "";
}
