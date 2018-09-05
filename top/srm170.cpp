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
    map<string, char> mp; // A map from ending pattern to final output char
    mp[""] = ' '; // blank line map to space char
    fora(s, poem) {
      string end = endPattern(s);
      if (!mp.count(end)) {
        mp[end] = c;
        if (c == 'z')
          c = 'A';
        else 
          ++c;
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
  while (iss >> w) {} // get the last word
  if (w.empty())
    return w;
  
  // fori(i, 0, sz(w))
  //   if (isvowel(w, i))
  //     return w.substr(i);
  bool f = false;
  for(int i=sz(w)-1; i>=0; --i) {
    if (isvowel(w, i))
      f = true;
    else if (f)
      return w.substr(i+1);
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
  fora(c, s)
    r += tolower(c);
  return r;
}

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  vector<string> poem;
  string s;
  Poetry go;
  while (cin >> s) {
    if (s.front() == '{')
      poem.pb(s.substr(1));
    else if (s.back() == '}')
      poem.pb(s.substr(0, sz(s)-1));
    else 
      poem.pb(s);
    fora(s, poem)
      cout << s << '\n';
    if (s.back() == '}')
      go.rhymeScheme(poem);
  }
  return 0;
}
