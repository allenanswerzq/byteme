#include <bits/stdc++.h>
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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& aa) {
    int lo = 0, hi = sz(aa) - 1;
    while (lo < hi) {
      while (!(aa[lo] % 2)) ++lo;
      while (aa[hi] % 2) --hi;
      if (lo < hi && aa[lo] % 2 && !(aa[hi] % 2)) {
        swap(aa[lo], aa[hi]);
      } 
      ++lo, --hi;
    } 
    return aa;
  }
};


void test(vi aa) {
  Solution go;
  vi ret = go.sortArrayByParity(aa);
  pvi(ret);
}

int main() {
  test({0, 1});
  test({3, 1, 2, 4});
  test({0, 2, 1, 4});
}
