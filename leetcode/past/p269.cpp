#include <bits/stdc++.h>
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

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
#define vs vector<string>
#define vvs vector<vector<string>>

class Solution {
public:
  string alienOrder(vs& aa) {
    set<pii> edges;
    set<char> ch;
    fora (a, aa) 
      ch.insert(all(a));

    fori (i, 0, sz(aa) - 1) {
      string a = aa[i], b = aa[i + 1];
      int mi = min(sz(a), sz(b)); 
      int j;
      for (; j < mi; ++j) {
        if (a[i] != b[i]) {
          edges.insert(make_pair(a[i], b[i]));
          break;
        }
      }
      // Invalid order.
      if (j == mi && sz(a) > sz(b)) return ""; 
    }

    // Topological Sort.
    vi in(256, 0);
    deque<char> dq; 
    string ret;

    fora (edge, edges) 
      ++in[edge.second]; 

    fora (c, ch)
      if (in[c] == 0) { 
        dq.push_back(c);
        ret += c;
      }

    trace(ret);
    while (sz(dq)) {
      auto c = dq.front(); dq.pop_front(); 
      fora (edge, edges) {
        if (edge.first == c) {
          --in[edge.second];
          if (in[edge.second] == 0) {
            dq.push_back(edge.second);
            ret += edge.second;
          }
        }
      }
    } 
    return sz(ret) == sz(ch) ? ret : "";
  }
};

void test(vs aa) {
  Solution go;
  string ret = go.alienOrder(aa);
  output(1, ret);
}

int main() {
  test({"wrt", "wrf", "er", "ett", "rftt"});
  return 0;
}
