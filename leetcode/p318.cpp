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

#define vi vector<int>
#define vs vector<string>

class Solution {
public:
  int maxProduct(vector<string>& aa) {
  int res = 0;
  int n = sz(aa);
  vi mask(n, 0);
  fori (i, 0, n) {
    fora (c, aa[i])
    mask[i] |= 1 << (c - 'a');

    fori (j, 0, i) 
    // If no common letters.
    if (!(mask[i] & mask[j]))
      res = max(res, sz(aa[i]) * sz(aa[j]));
  }   
  return res;
  }
};

void test(vs inp, int right) {
  Solution go;
  int res = go.maxProduct(inp);
  trace(res, right);
  assert(res == right);
}

int main() {
 
  test({"abcw","baz","foo","bar","xtfn","abcdef"}, 16);
  test({"a","ab","abc","d","cd","bcd","abcd"}, 4);
  test({"a","aa","aaa","aaaa"}, 0);

  return 0;
}
