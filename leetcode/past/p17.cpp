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

#define vc vector<char>
#define vs vector<string>
#define vvc vector<vector<char>>

class Solution {
public:
  vector<string> res;
  void bt(string aa, int idx, vvc &table, string path) {
    if (idx == aa.size()) {
      res.push_back(path);
      return;
    } else {
      vc tmp = table[aa[idx] - '0'];
      for (int i = 0; i < tmp.size(); i++) {
        path += tmp[i];
        bt(aa, idx + 1, table, path);
        path.pop_back();
      }
    }
  }

  vector<string> letterCombinations(string aa) {
    if(aa.size() == 0) return res;
    vvc table = {{'0', '0', '0'},
                 {'0', '0', '0'},
                 {'a', 'b', 'c'},
                 {'d', 'e', 'f'},
                 {'g', 'h', 'i'},
                 {'j', 'k', 'l'},
                 {'m', 'n', 'o'},
                 {'p', 'q', 'r','s'},
                 {'t', 'u', 'v'},
                 {'w', 'x', 'y','z'}};
    bt(aa, 0, table, "");
    return res;
  }
};

void test(string aa) {
  Solution go;
  vs res = go.letterCombinations(aa);
  pvi(res);
}

int main() {
  test("23");
  return 0;
}
