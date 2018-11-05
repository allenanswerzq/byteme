#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i=(a); i<(b); ++i)
#define ford(i, a, b) for (int i=(a); i>(b); --i)
#define pvi(x) fora(a, x) cout << a << " "; cout << endl
#define par(x, n) fori(a, 0, n) cout << x[a] << " "; cout << endl
#define output(ix, val) cout << "Case #" << (ix) << ": " << (val) << endl

#define trace(...) _f(#__VA_ARGS__, __VA_ARGS__)
template <typename T>
void _f(const char* name, T&& arg) {
  cout << name << ": " << arg << endl;
}

template <typename T, typename... Args> 
void _f(const char* names, T&& arg, Args&&... args) {
  const char* split = strchr(names + 1, ','); 
  cout.write(names, split - names) << ": " << arg << " |";
  _f(split, args...); 
} 

// Given a pattern and a string str, find if str follows the same pattern.
// Here follow means a full match, such that there is a bijection between a 
// letter in pattern and a non-empty substring in str.
// Examples:
// pattern = "abab", str = "redblueredblue" should return true.
// pattern = "aaaa", str = "asdasdasdasd" should return true.
// pattern = "aabb", str = "xyzabcxzyabc" should return false.
// Notes:
// You may assume both pattern and str contains only lowercase letters.

set<string> st;
unordered_map<char, string> mp;

bool go(string aa, int xx, string bb, int yy) {
  if (xx == sz(aa) && yy == sz(bb)) return 1;
  if (xx == sz(aa) || yy == sz(bb)) return 0;
  char ch = aa[xx];
  fori (i, yy, sz(bb)) {
    string tmp = bb.substr(yy, i - yy + 1);
    if (mp.count(ch) && mp[ch] == tmp) {
      if (go(aa, xx + 1, bb, i + 1))
        return 1;
    } else if (!mp.count(ch)) {
      if (st.count(tmp)) continue;
      mp[ch] = tmp;
      st.insert(tmp);
      if (go(aa, xx + 1, bb, i + 1))
        return 1;
      mp.erase(ch);
      st.erase(tmp);
    }
  } 
  return 0;
}

class Solution {
public:
  bool wordPatternMatch(string aa, strin str) {
    return go(aa, 0, str, 0); 
  }
};

int main() {
  return 0;
}
