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

class Solution {
public:
  string longestCommonPrefix(vector<string>& aa) {
    string ret;
    if (sz(aa) <= 0) return ret;
    int r = sz(aa), c = (1 << 30);

    for (int i = 0; i < r; ++i)
      c = min(c, sz(aa[i]));

    // trace(r, c);

    for (int j = 0; j < c; ++j) {
      char t = aa[0][j];
      for (int i = 0; i < r; ++i) {
        if (aa[i][j] != t) 
          return ret;
      }
      ret += t;
    }

    return ret;
  }
};


void test(vector<string> inp) {
  Solution go;
  string res = go.longestCommonPrefix(inp);
  output(1, res);
}

int main() {
  test({"aa", "aa"});
  test({"aaaa", "", "acc"});
  test({"flower","flow","flight"});
  return 0;
}
