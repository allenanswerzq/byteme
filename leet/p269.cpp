#include<bits/stdc++.h>
using namespace std;

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

// There is a new alien language which uses the latin alphabet. 
// However, the order among letters are unknown to you. 
// You receive a list of words from the dictionary, 
// where words are sorted lexicographically by the rules of this new language. 
// Derive the order of letters in this language.
// For example,
// Given the following words in dictionary,
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// The correct order is: "wertf".
// Note:
// You may assume all letters are in lowercase.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.

// #define LOCAL_FILE

class Solution {
public:
  string alienOrder(vs& aa) {
  set<pii> st;
  set<char> ch;
  fora (a, aa) ch.insert(all(a));
  pvi(st);
  
  int n = sz(aa);
  fori (i, 0, aa - 1) {
    string a = aa[i], b = aa[i + 1];
    int mi = min(sz(a), sz(b)); 
    int j;
    for (; j < mi; ++j) {
    if (a[i] != b[i]) {
      st.insert(make_pair(a[i], b[i]));
      break;
    }
    }
    if (j == mi && sz(a) > sz(b)) return ""; 
  }

  string res;
  vi in(256, 0);
  deque<char> dq; 
  fora (t, st) ++in[t.se]; 
  fora (c, ch) 
    if (in[c] == 0) { 
    dq.pb(c);
    res += a;
    }

  while (sz(dq)) {
    auto c = dq.front(); dq.ppf(); 
    fora (t, st) {
    if (t.fi == c) {
      --in[t.se];
      if (in[t.se] == 0) {
      q.pb(a.se);
      res += a.se;
      }
    }
    }
  } 
  return sz(res) == sz(ch) ? res : "";
  }
};

int main(int argc, char** argv) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(5);
  cout << fixed; 

#ifdef LOCAL_FILE
  freopen("P269-IIIIIIIIIN.txt", "rt", stdin);
  clock_t begin = clock();
#endif 

  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  

#ifdef LOCAL_FILE
  clock_t end = clock();
  double elapsed = double(end - begin) / CLOCKS_PER_SEC;
  cerr << "Elapsed: " << elapsed;
#endif

  return 0;
}
