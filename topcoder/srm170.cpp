#include<bits/stdc++.h>
using namespace std;

class Poetry {
public:
  string endPattern(string s);
  string lower(string s);
  bool isvowel(string s, int ix);
  string rhymeScheme(vector<string>& poem) {
    string res = "";
    char c = 'a';
    // A map from ending pattern to final output char
    map<string, char> mp;
    // Blank line map to space char
    mp[""] = ' ';
    fora (s, poem) {
      string end = endPattern(s);
      if (!mp.count(end)) {
        mp[end] = c;
        if (c == 'z') c = 'A';
        else ++c;
      }
      res += mp[end];
      //cout << end << " " << mp[end] << " " << res << '\n';
    }
    return res;
  }
};

string Poetry::endPattern(string s) {
  string w;
  istringstream iss(lower(s));
  while (iss >> w) {}
  if (w.empty())
    return w;

  // fori(i, 0, sz(w))
  //   if (isvowel(w, i))
  //     return w.substr(i);
  bool f = false;
  for(int i=sz(w)-1; i>=0; --i) {
    if (isvowel(w, i)) f = true;
    else if (f) return w.substr(i+1);
  }
  return w;
}

bool Poetry::isvowel(string s, int ix) {
  char c = s[ix];
  if (string("aeiouAEIOU").find(c) != string::npos) {
    return true;
  }
  return (tolower(c)=='y') && ix && (ix+1 != sz(s));
}

string Poetry::lower(string s) {
  string r;
  fora(c, s) r += tolower(c);
  return r;
}

int main() {
  return 0;
}
