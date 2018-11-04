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

class Solution {
public:
  vector<int> fairCandySwap(vi& aa, vi& bb) {
    set<int> st(all(bb));  
    int sa = accumulate(all(aa), 0);
    int sb = accumulate(all(bb), 0); 
    fora (a, aa) {
      int t = (sb - sa + 2 * a) / 2;
      if (st.count(t)) return {a, t};  
    }
    return {};
  }
};

void test(vi aa, vi bb) {
  Solution go;
  vi ret = go.fairCandySwap(aa, bb);
  pvi(ret);
}

int main() {
  test({1, 1}, {2, 2});
  test({2}, {1, 3});
  test({1, 2, 5}, {2, 4});
  
}

