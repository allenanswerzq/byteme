#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mst(x, y) memset(x, y, sizeof(x))
#define output(val) cout << (val) << endl;
#define fora(e, c) for (auto &e : c)
#define fori(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, a, b) for (int i = (a); i > (b); --i)
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

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool check(string aa, string bb) {
  if (sz(aa) != sz(bb)) return 0;
  unordered_map<char, char> mp1;
  unordered_map<char, char> mp2;
  fori (i, 0, sz(bb)) {
    if (mp1.count(bb[i]))
      if (mp1[bb[i]] != aa[i]) return 0; 
    if (mp2.count(aa[i]))
      if (mp2[aa[i]] != bb[i]) return 0;
    mp1[bb[i]] = aa[i];
    mp2[aa[i]] = bb[i];
  } 
}

class Solution {
public:
  vs findAndReplacePattern(vs& wds, string pat) {
    vs ret;
    fora (wd, wds) {
      if (check(wd, pat))
        ret.push_back(wd);
    }   
    return ret;
  }
};

int main() {
  return 0;
}
